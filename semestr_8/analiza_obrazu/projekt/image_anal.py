#*-* coding: utf8 *-*
"""Moduł zawierający klasy używane do przetwarzania obrazu"""
import numpy as np
from scipy import misc
import itertools
from pprint import pprint


class NoImageError(Exception):
    """Wyjątek sygnalizujący próbę operowania na niewczytanym obrazie"""
    pass


class NoSuchMethodError(Exception):
    """Wyjątek sygnalizujący podanie złej metody operacji"""
    pass


class FilterSizeError(Exception):
    """Wyjątek sygnalizujący błędny format filtru"""
    pass


class ImageAnal:
    """Klasa przetwarzająca obrazy"""

    def image_loaded(fn):
        """dekorator.
        Sprawdza czy został załadowany obraz"""
        def wrapped(self, *args, **kwargs):
            if self.__image is None:
                raise NoImageError()
            return fn(self, *args, **kwargs)
        return wrapped

    def __init__(self, path=None):
        """Konstruktor obiektu ImageAnal"""
        self.__image = None
        if path:
            self.load_image(path)

    def load_image(self, path):
        """Wczytuje obraz z pliku <path>"""
        self.__image = misc.imread(path)

    def open(self, path):
        """Wczytuje obraz z pliku"""
        self.load_image(path)

    @image_loaded
    def negative(self):
        """Tworzy negatyw obrazu"""
        self.__image = 255 - self.__image

    @image_loaded
    def grayscale(self, method=1):
        """Konwertuje do odcieni szarości.
        method:
        1 (default) wykorzystuje metodę wartości średniej kolorów
        2 wykorzystuje wzór 0.3*R+0.59*G+0.11*B
        Obsługa tylko formatu RGB"""
        if method == 1:
            self.__grayscale1()
        elif method == 2:
            self.__grayscale2()
        else:
            raise NoSuchMethodError()

#    @image_loaded
#    def convert(self, fmt):
#        self.__image = self.__image.convert(fmt)
#        """Konwertuje obraz do zadanego formatu"""

    @image_loaded
    def normalize(self):
        data = self.__image
        R = data[:, 0]
        G = data[:, 1]
        B = data[:, 2]
        R = (R - R.min()) * 255 / R.max()
        G = (G - G.min()) * 255 / G.max()
        B = (B - B.min()) * 255 / B.max()

        data[:, 0] = R
        data[:, 1] = G
        data[:, 2] = B

        self.__image = data

    @image_loaded
    def scale(self, factor):
        if factor < 1:
            self.__scale_down(factor)
        else:
            self.__scale_up(factor)

    @image_loaded
    def progowanie(self, method="global", otoczenie=5, odchylenie=15):
        """Przeprowadza progowanie obrazka.
        metody:
        global - progowanie globalne
        local - progowanie lokalne
        mixed - progowanie mieszane

        parametry:
        otoczenie = rozmiar otoczenia pixela
        odchylenie - stopień ochylenia od średniej"""
        self.__grayscale1()
        if method == "global":
            self.__progowanie_globalne()
        elif method == "local":
            self.__progowanie_lokalne(otoczenie=otoczenie)
        elif method == "mixed":
            self.__progowanie_mieszane(
                otoczenie=otoczenie, odchylenie=odchylenie)

    @image_loaded
    def splot(self, filter):
        filter = np.array(filter, dtype=np.int8)
        if filter.shape != (3, 3):
            raise(FilterSizeError)
        data = self.__image
        new = self.__expand(data, 1)
        new = np.array(new, dtype=np.int32)
#        new = np.array(new, dtype=np.uint8)
#        print (filter[0,0] * new[:-2,:-2])[160,130]
#        print (filter[0,1] * new[:-2,1:-1])[160,130]
#        print (filter[0,2] * new[:-2,2:])[160,130]
#        print (filter[1,0] * new[1:-1,:-2])[160,130]
#        print (filter[1,1] * new[1:-1,1:-1])[160,130]
#        print (filter[1,2] * new[1:-1,2:])[160,130]
#        print (filter[2,0] * new[2:,:-2])[160,130]
#        print (filter[2,1] * new[2:,1:-1])[160,130]
#        print (filter[2,2] * new[2:,2:])[160,130]
        new = (filter[0, 0] * new[:-2, :-2] + filter[0, 1] * new[:-2, 1:-1] +
               filter[0, 2] * new[:-2, 2:] + filter[1, 0] * new[1:-1, :-2] +
               filter[1, 1] * new[1:-1, 1:-1] + filter[1, 2] * new[1:-1, 2:] +
               filter[2, 0] * new[2:, :-2] + filter[2, 1] * new[2:, 1:-1] +
               filter[2, 2] * new[2:, 2:])
        new = new / (filter.sum())
        new -= 255
        new = new * (new < 0)
        new += 255
        new = new * (new > 0)
        data = np.array(new, dtype=np.uint8)
        self.__image = data
#        self.normalize()

    @image_loaded
    def brightness(self, val):
        data = self.__image
        new = np.array(data[:, :, :3], dtype=np.int32)
        new += val
        new = self.__shrink_values(new)
        self.__image[:, :, :3] = new

    @image_loaded
    def roberts(self):
        data = self.__image
        new = self.__expand(np.array(data, np.int32), 1)
        data[:, :] = self.__shrink_values(abs(new[1:-1, 1:-1] - new[2:, 2:]) +
                                          abs(new[2:, 1:-1] - new[1:-1, 2:]))
        self.__image = data

    @image_loaded
    def sobel(self):
        data = self.__image
        new = self.__expand(np.array(data, np.int32), 1)
        new[1:-1, 1:-1] = (((new[2:, :-2] + 2 * new[2:, 1:-1] + new[2:, 2:]) -
                            (new[:-2, :-2] + 2 * new[:-2, 1:-1] + new[:-2, 2:])) ** 2 +
                           ((new[:-2, 2:] + 2 * new[1:-1, :-2] + new[2:, 2:]) -
                            (new[:-2, :-2] + 2 * new[1:-1, :-2] + new[2:, :-2])) ** 2) ** (0.5)
        new = self.__shrink_values(new)
        data = new[1:-1, 1:-1]
        self.__image = data

    @image_loaded
    def rotate(self, angle):
        angle = np.deg2rad(angle)
        data = self.__image
        px = data.shape[0] / 2
        py = data.shape[1] / 2
        new = np.zeros((data.shape[0] * 3, data.shape[1] * 3, data.shape[2]), np.uint8)
        for i, j in itertools.product(np.arange(0, data.shape[0]), np.arange(0, data.shape[1]), repeat=1):
            new[np.cos(angle) * i - np.sin(angle) * j + px, np.sin(angle) * i + np.cos(angle) * j + py] = data[i, j]
        horiz = np.nonzero(new.sum(axis=0) != 0)[0]
        vert = np.nonzero(new.sum(axis=1) != 0)[0]

        new = new[vert[0]:vert[-1], horiz[0]:horiz[-1]]
        self.__image = new

    @image_loaded
    def szum(self, prop, method):
        if method == 'solpieprz':
            self.__szum_solpieprz(prop)
        elif method == 'rownomierny1':
            self.__szum_rownomierny1(prop)
        elif method == 'rownomierny2':
            self.__szum_rownomierny1(prop)

    @image_loaded
    def odszumianie(self, method):
        if method == 'srednia':
            self.__odszumianie_srednie(self)
        elif method == 'mediana':
            self.__odszumianie_medianowe(self)
        elif method == 'mediana2':
            self.__odszymianie_medianowe2(self)
        else:
            raise NoSuchMethodError()

    @image_loaded
    def maska(self):
        data = self.__image
        data = data[:, :, 0]
        data = (data < 125) * 1

        tmp = np.zeros(data.shape)

        tmp[1:-1,1:-1] = ((data[1:-1,:-2] == 0) & (data[1:-1, 1:-1] == 1) & (data[1:-1, 2:] == 1) & (data[:-2, 2:] == 1) & (data[2:, 2:] == 1) |
                          (data[2:,1:-1] == 0) & (data[1:-1, 1:-1] == 1) & (data[:-2, 2:] == 1) & (data[:-2, 1:-1] == 1) & (data[:-2, :-2] == 1) |
                          (data[2:,1:-1] == 0) & (data[1:-1, 1:-1] == 1) & (data[:-2, 2:] == 1) & (data[:-2, 1:-1] == 1) & (data[:-2, :-2] == 1) |
                          (data[:-2,1:-1] == 0) & (data[1:-1, 1:-1] == 1) & (data[2:, :-2] == 1) & (data[2:, 1:-1] == 1) & (data[2:, 2:] == 1))
        self.__image = np.zeros((data.shape[0], data.shape[1], 3))
        self.__image[:,:,0] = tmp
        self.__image[:,:,1] = tmp
        self.__image[:,:,2] = tmp

    @image_loaded
    def KKM(self):
#        np.set_printoptions(linewidth=504, threshold='nan')
        czworki = [3, 6, 7, 12, 14, 15, 24, 28, 30, 48, 56, 60, 96, 112, 120, 129, 131, 135, 192, 193, 195, 224, 225, 240]
        wyciecia = [3, 5, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31, 48, 52, 53, 54, 55, 56, 60, 61, 62, 63, 65, 67, 69, 71, 77, 79, 80, 81, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 99, 101, 103, 109, 111, 112, 113, 115, 116, 117, 118, 119, 120, 121, 123, 124, 125, 126, 127, 131, 133, 135, 141, 143, 149, 151, 157, 159, 181, 183, 189, 191, 192, 193, 195, 197, 199, 205, 207, 208, 209, 211, 212, 213, 214, 215, 216, 217, 219, 220, 221, 222, 223, 224, 225, 227, 229, 231, 237, 239, 240, 241, 243, 244, 245, 246, 247, 248, 249, 251, 252, 253, 254, 255]
        data = self.__image
        print data.shape
        data = data[:,:,0]
        data = (data < 125) * 1
#        data[2,2] = 1
#        data = np.array([[0,0,0,0,0,0,0,0,0],
#                         [0,0,0,0,0,1,0,0,0],
#                         [0,1,0,0,0,1,1,0,0],
#                        [0,1,0,0,0,1,1,0,0],
#                        [1,1,1,0,0,1,1,0,0],
#                        [0,1,0,0,0,1,1,0,0],
#                        [0,0,0,0,0,0,0,1,0],
#                        [0,0,0,0,0,0,0,0,0]])
        old = np.zeros(data.shape)
        iter = 0
        verb = False
        while not np.array_equal(old, data):
            print "iteracja: ", iter
            iter += 1
            old = data.copy()
            if verb:
                print "Poczatkowe"
                print data
                        #krok I
            pion = np.zeros(data.shape)
            pion[1:-1,1:-1] = (data[:-2,1:-1] == 0) | (data[2:,1:-1] == 0) |\
                              (data[1:-1,:-2] == 0) | (data[1:-1,2:] == 0)
#            pion = pion < 4
            pion = (data == 1) * pion
#            data = (data * (-pion)) + (pion * 2)
            data = data + pion
            if verb:
                print "Po kroku I"
                print data

                        #krok II
            pion = np.zeros(data.shape)
            pion[1:-1,1:-1] = (data[:-2, :-2] == 0) | (data[:-2, 2:] == 0) |\
                              (data[2:, :-2] == 0) | (data[2:, 2:] == 0)
#            pion = pion < 4
            pion = (data == 1) * pion
#            data = (data * (-pion)) + (pion * 3)
            data = data + pion * 2
            if verb:
                print "Po kroku II"
                print data
                        #krok III
            tmp = np.zeros(data.shape)
            tmp[1:-1,1:-1] = 1 * (data[:-2, :-2]>0) +\
                             2 * (data[1:-1, :-2]>0) +\
                             4 * (data[2:, :-2]>0) +\
                             128 * (data[:-2, 1:-1]>0) +\
                             8 * (data[2:, 1:-1]>0) +\
                             64 * (data[:-2, 2:]>0) +\
                             32 * (data[1:-1, 2:]>0) +\
                             16 * (data[2:, 2:]>0)

            tmp = (data==2) * tmp
            tmp2 = np.zeros(tmp.shape, dtype=np.bool)
            for i in czworki:
                tmp2 |= (tmp == i)
            data += (tmp2*2)
            if verb:
                print "Po kroku III"
                print data

                            #krok IV
            tmp = np.zeros(data.shape)
            tmp[1:-1,1:-1] = 1 * (data[:-2, :-2]>0) +\
                             2 * (data[1:-1, :-2]>0) +\
                             4 * (data[2:, :-2]>0) +\
                             128 * (data[:-2, 1:-1]>0) +\
                             8 * (data[2:, 1:-1]>0) +\
                             64 * (data[:-2, 2:]>0) +\
                             32 * (data[1:-1, 2:]>0) +\
                             16 * (data[2:, 2:]>0)

            tmp = (data == 4) * tmp
            tmp2 = np.zeros(tmp.shape, dtype=np.bool)
            for i in wyciecia:
                tmp2 |= (tmp == i)
            tmp = (tmp>0) - tmp2

            data = data * (data != 4) + tmp * 1 + tmp2 * 0
            if verb:
                print "Po kroku IV"
                print data

                            #krok V
            tmp = np.zeros(data.shape)
            tmp[1:-1,1:-1] = 1 * (data[:-2, :-2]>0) +\
                             2 * (data[1:-1, :-2]>0) +\
                             4 * (data[2:, :-2]>0) +\
                             128 * (data[:-2, 1:-1]>0) +\
                             8 * (data[2:, 1:-1]>0) +\
                             64 * (data[:-2, 2:]>0) +\
                             32 * (data[1:-1, 2:]>0) +\
                             16 * (data[2:, 2:]>0)

            tmp = (data == 2) * tmp
            tmp2 = np.zeros(tmp.shape, dtype=np.bool)
            for i in wyciecia:
                tmp2 |= (tmp == i)
            tmp = (tmp>0) - tmp2

            data = data * (data != 2) + tmp * 1 + tmp2 * 0
            if verb:
                print "Po kroku V"
                print data

                            #krok VI
            tmp = np.zeros(data.shape)
            tmp[1:-1,1:-1] = 1 * (data[:-2, :-2]>0) +\
                             2 * (data[1:-1, :-2]>0) +\
                             4 * (data[2:, :-2]>0) +\
                             128 * (data[:-2, 1:-1]>0) +\
                             8 * (data[2:, 1:-1]>0) +\
                             64 * (data[:-2, 2:]>0) +\
                             32 * (data[1:-1, 2:]>0) +\
                             16 * (data[2:, 2:]>0)

            tmp = (data == 3) * tmp
            tmp2 = np.zeros(tmp.shape, dtype=np.bool)
            for i in wyciecia:
                tmp2 |= (tmp == i)
            tmp = (tmp>0) - tmp2

            data = data * (data != 3) + tmp * 1 + tmp2 * 0
            if verb:
                print "Po kroku VI"
                print data

        data = data * 255
        print data.shape
        self.__image = np.zeros((data.shape[0], data.shape[1], 3))
        print self.__image.shape
        self.__image[:,:,0] = data
        self.__image[:,:,1] = data
        self.__image[:,:,2] = data
        print self.__image.shape
#        self.__image = data



    @image_loaded
    def save(self, path):
        """Zapisuje obraz do pliku"""
        self.__clear_alpha()
        misc.imsave(path, self.__image)

    def __grayscale1(self):
        """Konwersja do skali szarości"""
        data = self.__image
#        data[:,:] = 3 * (data[:,:].mean())
#        x = [4 * (int(x.mean()),) for x in data]
        new = np.array(data, dtype=np.uint32)
        new[:, :, 0] += data[:, :, 1]
        new[:, :, 0] += data[:, :, 2]
        new[:, :, 0] /= 3
        data[:, :, 1] = data[:, :, 2] = data[:, :, 0] = new[:, :, 0]

        self.__image = data

    def __scale_down(self, factor):
        factor = (int)(factor ** (-1))
        data = self.__image
        data = np.array(data[::factor, ::factor, :])
        self.__image = data

    def __scale_up(self, factor):
        data = self.__image
        new = np.zeros(
            (data.shape[0] * factor, data.shape[1] * factor, data.shape[2]))
        for x in xrange(data.shape[0]):
            for y in xrange(data.shape[1]):
                new[x * factor:(x + 1) * factor, y *
                    factor:(y + 1) * factor, :] = data[x, y, :]
        self.__image = new

    def __progowanie_globalne(self, *args, **kwargs):
        data = self.__image
        mean = self.__prog_globalny()
#        mean = data[:, :, 0].mean()
        data = (data > mean) * 255.
        self.__image = data

    def __progowanie_lokalne(self, otoczenie=5, *argx, **kwargs):
        data = self.__image
        prog = self.__prog_lokalny(otoczenie)
        data = (data > prog) * 255
        self.__image = data

    def __progowanie_mieszane(self, otoczenie, odchylenie):
        data = self.__image
        prog = self.__prog_mieszany(otoczenie, odchylenie)
        data = (data > prog) * 255
        self.__image = data

    def __prog_globalny(self):
        data = self.__image
        return data[:, :, 0].mean()

    def __prog_lokalny(self, otoczenie):
        data = self.__image
        new = self.__expand(data, otoczenie)
        prog = np.zeros(data.shape)
#        for x in xrange(otoczenie, new.shape[0] - otoczenie):
#            for y in xrange(otoczenie, new.shape[1] - otoczenie):
#                prog[x - otoczenie, y - otoczenie] = new[x - otoczenie: x + otoczenie, y - otoczenie:y + otoczenie, :3].mean()
        for d in itertools.product(np.arange(0, 2 * otoczenie + 1), repeat=2):
            prog[:, :] += new[d[0]:new.shape[0] - 2 * otoczenie + d[0],
                              d[1]:new.shape[1] - 2 * otoczenie + d[1]]

        prog /= (2 * otoczenie + 1) ** 2
#        print prog
        return prog

    def __prog_mieszany(self, otoczenie, odchylenie):
        glob = self.__prog_globalny()
        prog = self.__prog_lokalny(otoczenie)
        prog -= (glob + odchylenie)
        prog = prog * (prog > 0)
        prog -= 2 * odchylenie
        prog = prog * (prog < 0)
        prog += (glob + odchylenie)
        return prog

    def __expand(self, src, otoczenie):
        data = src.copy()
        left = data[:, 0, :]
        right = data[:, -1, :]
        for i in xrange(otoczenie - 1):
            left = np.column_stack((left, data[:, 0, :]))
            right = np.column_stack((right, data[:, -1, :]))
        left = left.reshape((data.shape[0], -1, data.shape[2]))
        right = right.reshape((data.shape[0], -1, data.shape[2]))
        data = np.column_stack((left, data, right))
        top = data[0, :, :]
        bottom = data[-1, :, :]
        for i in xrange(otoczenie - 1):
            top = np.column_stack((top, data[0, :, :]))
            bottom = np.column_stack((bottom, data[-1, :, :]))
        top = top.reshape((-1, data.shape[1], data.shape[2]))
        bottom = bottom.reshape((-1, data.shape[1], data.shape[2]))
        data = np.vstack((top, data, bottom))
        return data

    def __clear_alpha(self):
#        print "clear alpha"
        if len(self.__image.shape) > 2:
            if self.__image.shape[2] == 4:
                self.__image[:, :, 3] = 255
        pass

    def __shrink_values(self, src):
        data = src.copy()
        data = data * (data > 0)
        data -= 255
        data = data * (data < 0)
        data += 255
        return data

    def __szum_solpieprz(self, prop):
        data = self.__image
        prop *= 100
        s = data.shape[0] * data.shape[1]
        s2 = (data.shape[0], data.shape[1])
        r = np.random.randint(100, size=s).reshape(s2)
        R = r < prop
        r2 = np.random.randint(2, size=s).reshape(s2)
        data = data * (1-r).repeat(4).reshape(data.shape) + r2.repeat(4).reshape(data.shape)
        self.__image = data

    def __szum_rownomierny1(self, prop):
        data = self.__image
        prop *= 100
        s = data.shape[0] * data.shape[1]
        s2 = (data.shape[0], data.shape[1])
        r = np.random.randint(100, size = s2).reshape(s2)
        r = r < prop
        tmp = np.array(data, dtype=np.int64)
        r2 = np.random.randint(20, size = s2).reshape(s2)-10
        r2 = r2 + (r2 > 0) * 20 - (r2 < 0) * 20
        r2 = r2 * r
        r2 = r2.repeat(4).reshape(data.shape)
        tmp += r2
        tmp = tmp * (tmp > 0)
        tmp -= 255
        tmp = tmp * (tmp < 0)
        tmp += 255
        self.__image = tmp

    def __szum_rownomierny2(self, prop):
        data = slef.__image
        prop *= 100
        s = reduce(lambda x, y: x * y, data.shape)
        r = np.random.randint(100, size = s).reshape(s2)
        r = r < prop
        tmp = np.array(data, dtype=np.int64)
        r2 = np.random.randint(20, size = s)-10
        r2 = r2 * r
        r2 = r2 + (r2 > 0) * 20 - (r2 < 0) * 20
        r2 = r2.reshape(data.shape)
        tmp += r2
        tmp = tmp * (tmp > 0)
        tmp -= 255
        tmp = tmp * (tmp < 0)
        tmp += 255
        self.__image = tmp

    def segment1(self, directory):
        def ranges(val):
            lines = []
            tmp = 0
            combo = False
            for (i,j) in enumerate(hist):
                if j > 0 and not combo:
                    combo = True
                    tmp = i
                elif not j and combo:
                    combo = False
                    lines.append([tmp, i])
            if combo:
                lines.append([tmp,i])
            return lines

    #    print type(self.__image)
     #   print self.__image.shape
        data = (self.__image[:,:,0] < 127) * 1
        misc.imsave('binary.png', data)
        hist = data.sum(axis=1)
        lines = ranges(hist)
   #     print lines
        num = 0
        for l in lines:
            line = data[l[0]:l[1],:]
            hist = line.sum(axis=0)
            chars = ranges(hist)
            for c in chars:
                path = directory + '/%05d.png'%num
  #              print path
                c1 = data[l[0]:l[1], c[0]:c[1]]
                hist = c1.sum(axis=1)
                lines2 = ranges(hist)
 #               print lines2
#                if lines2:
                litera = misc.imresize(data[l[0]+lines2[0][0]:l[0]+lines2[-1][1], c[0]:c[1]], size=(100,100))
                litera = [litera, litera, litera]
#                misc.imsave(path, data[l[0]+lines2[0][0]:l[0]+lines2[-1][1], c[0]:c[1]])
                misc.imsave(path, litera)
 #               else:
 #                   misc.imsave(path, data[l[0]:l[1], c[0]:c[1]])

                num += 1

    def segment2(self, directory):
        print "Segment2"
        def neighbour(data, p):
            p = list(p)
            if p[0] == 0:
                p[0] = 1
            if p[1] == 0:
                p[1] = 1
            return set([tuple(i+p-(1,1)) for i in np.transpose(data[p[0] - 1:p[0] + 2, p[1] - 1:p[1] + 2].nonzero())])
#        self.kkm2()
#        print "po kkm"
#        print self.__image.shape
        pprint(self.__image[:,:,0])
        data = (self.__image[:, :, 0] < 127) * 1

        buf = set()
        checked = set()
        num = 0
        pprint(data)
        licznik = 1
        while data.sum():
            checked = set()
            buf.add(tuple(np.transpose(data.nonzero())[0]))
            while buf:
#                print "buf",buf
                p = buf.pop()
#                print "point",p
                n = neighbour(data, p)
#                print "neighbour", n
                checked.add(p)
#                print "checked", checked
                buf = buf.union(n - checked)
#                print "buf", buf
#                print "**********"
            print licznik
            licznik += 1
            checked = np.array(list(checked))
            minx = checked[:, 0].min()
            miny = checked[:, 1].min()
            maxx = checked[:, 0].max()+1
            maxy = checked[:, 1].max()+1
            tmp = np.zeros((1 + maxx - minx, 1 + maxy - miny))
           # path = directory+'/'+str(num)+".png"
            path = directory + '/%05dx%05dx%05dx%05d.png'%(minx, maxy, maxx, miny)
            for i in checked:
                data[i[0], i[1]] = 0
                tmp[i[0] - minx, i[1] - miny] = 1
            misc.imsave(path, tmp)
            num += 1
	def resize2(self, size):
		self.__image = misc.imresize(self.__image__, size)
		return self.__image__

    def kkm2(self):
        czworki = [3, 6, 7, 12, 14, 15, 24, 28, 30, 48, 56, 60, 96, 112, 120, 129, 131, 135, 192, 193, 195, 224, 225, 240]
        wyciecia = [3, 5, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31, 48, 52, 53, 54, 55, 56, 60, 61, 62, 63, 65, 67, 69, 71, 77, 79, 80, 81, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 97, 99, 101, 103, 109, 111, 112, 113, 115, 116, 117, 118, 119, 120, 121, 123, 124, 125, 126, 127, 131, 133, 135, 141, 143, 149, 151, 157, 159, 181, 183, 189, 191, 192, 193, 195, 197, 199, 205, 207, 208, 209, 211, 212, 213, 214, 215, 216, 217, 219, 220, 221, 222, 223, 224, 225, 227, 229, 231, 237, 239, 240, 241, 243, 244, 245, 246, 247, 248, 249, 251, 252, 253, 254, 255]
        #sprawdzarka = [[128, 64, 32], [1, 0, 16], [2, 4, 8]]
        def sprawdzarka(obj, p):
            tmp = 1* ((data[p[0]-1:p[0]+2,p[1]-1:p[1]+2]) > 0)
            macierz = np.array([[128, 64, 32], [1, 0, 16], [2, 4, 8]])
            #macierz = np.array([[128, 1, 2], [64,0,4], [32,16,8]])
            suma = (tmp * macierz).sum()
           # print "DEBUG"
           # print p
           # pprint(data[p[0]-1:p[0]+2,p[1]-1:p[1]+2])
           # pprint(tmp)
           # print suma
            return suma
        data = self.__expand(self.__image, 1)[:,:,0]
        data = 1 * (data < 127)
        data[0,:] = 0
        data[-1,:] = 0
        data[:,0] = 0
        data[:,-1] =0
        old = np.zeros(data.shape)
        DEBUG = True
        while not (old == data).all():
            print "iteracja"
            old = data.copy()
            #krok 1
            sasiedzi = 1* (data[1:-1,:-2] == 0)+ 1*(data[1:-1,2:] == 0)+\
                       1* (data[:-2,1:-1] == 0) +1* (data[2:,1:-1] == 0)
            
            sasiedzi = (sasiedzi > 0)

            sasiedzi = (data[1:-1, 1:-1] == 1) * sasiedzi
            data[1:-1,1:-1] = data[1:-1,1:-1]+ sasiedzi
            if DEBUG:
                print "Krok 1"
                pprint(data)

            #krok 2
            sasiedzi = 1*(data[:-2,:-2] == 0) + 1*(data[2:,2:] == 0)+\
                       1*(data[:-2,2:] == 0)+ 1*(data[2:,:-2] == 0)
            sasiedzi = (sasiedzi > 0)
            sasiedzi = (data[1:-1,1:-1] == 1) * sasiedzi
            data[1:-1,1:-1] = data[1:-1,1:-1] + sasiedzi * 2.0
            if DEBUG:
                print "Krok 2"
                pprint(data)

            #krok 3
        #    data2 = data.copy()
            tmp = np.transpose((data == 2).nonzero())
            for d in tmp:
                if sprawdzarka(self,d) in czworki:
                    data[d[0],d[1]] = 4
            if DEBUG:
                print "Krok 3"
                pprint(data)

            #krok 4
            #data2 = data.copy()
            tmp = np.transpose((data == 4).nonzero())
            for c in tmp:
                if sprawdzarka(self, c) not in wyciecia:
                    data[c[0],c[1]] = 1
                else:
                    data[c[0],c[1]] = 0
            if DEBUG:
                print "Krok 4"
                pprint(data)
            
            #krok 5
            #data2 = data.copy()
            tmp = np.transpose((data == 2).nonzero())
            for c in tmp:
                if sprawdzarka(self, c) not in wyciecia:
                    data[c[0],c[1]] = 1
                else:
                    data[c[0],c[1]] = 0
            if DEBUG:
                print "Krok 5"
                pprint(data)

            #krok 6
            #data2 = data.copy()
            tmp = np.transpose((data == 3).nonzero())
            for c in tmp:
                if sprawdzarka(self, c) not in wyciecia:
                    data[c[0],c[1]] = 1
                else:
                    data[c[0],c[1]] = 0
            if DEBUG:
                print "Krok 6"
                pprint(data)
  #      print type(data)
   #     print "Po kkm2"
        data = data[1:-1, 1:-1] * 255
        wynik = []
        for i in data:
            tmp = []
            for j in i:
                tmp.append([j, j, j])
            wynik.append(tmp)
        self.__image = np.array(wynik)
        self.negative()
        print "A"
        pprint(data)
        pprint(self.__image)
        print "B"
   # def info(self):
   #     print "Rozmiar obrazu: ",self.__image.shape
