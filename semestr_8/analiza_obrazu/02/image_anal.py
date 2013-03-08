#*-* coding: utf8 *-*
"""Moduł zawierający klasy używane do przetwarzania obrazu"""
import numpy as np
from scipy import misc


class NoImageError(Exception):
    """Wyjątek sygnalizujący próbę operowania na niewczytanym obrazie"""
    pass


class NoSuchMethodError(Exception):
    """Wyjątek sygnalizujący podanie złej metody operacji"""
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
    def progrowanie(self, method="global", otoczenie=5, odbieg=15):
        """Przeprowadza progowanie obrazka.
        metody:
        global - progowanie globalne
        local - progowanie lokalne
        mixed - progowanie mieszane

        parametry:
        otoczenie = rozmiar otoczenia pixela
        odbieg - stopień odbiegania od średniej"""
        if method == "global":
            self.__progowanie_globalne()
        elif method == "local":
            self.__progowanie_lokalne(otoczenie=otoczenie)

    @image_loaded
    def save(self, path):
        """Zapisuje obraz do pliku"""
        misc.imsave(path, self.__image)

    def __grayscale1(self):
        """Konwersja do skali szarości"""
        data = self.__image
#        data[:,:] = 3 * (data[:,:].mean())
#        x = [4 * (int(x.mean()),) for x in data]
        size = data.shape
        tmp = data.reshape(size[0] * size[1], size[2])
        tmp = np.array([size[2] * [z[:3].mean(), ] for z in tmp])
        data = tmp.reshape((size[0], size[1], size[2]))

        self.__image = data

    def __scale_down(self, factor):
        factor = (int)(factor ** (-1))
        data = self.__image
        data = np.array(data[::factor, ::factor, :])
        self.__image = data

    def __scale_up(self, factor):
        data = self.__image
        new = np.zeros((data.shape[0] * factor, data.shape[1] * factor, data.shape[2]))
        for x in xrange(data.shape[0]):
            for y in xrange(data.shape[1]):
                print x, y
                new[x * factor:(x + 1) * factor, y * factor:(y + 1) * factor, :] = data[x, y, :]
        self.__image = new

    def __progowanie_globalne(self, otoczenie, odbieg):
        self.__grayscale1()
        data = self.__image
        mean = data[:, :, 0].mean()
        data = (data > mean) * 255.
        self.__image = data

    def __progowanie_lokalne(self, otoczenie):
        self.__grayscale1()
        data = self.__image
        new = data.copy()

        left = data[:, 0, :]
        right = data[:, -1, :]
        for i in xrange(otoczenie - 1):
            left = np.column_stack((left, data[:, 0, :]))
            right = np.column_stack((right, data[:, -1, :]))
        left = left.reshape((data.shape[0], -1, data.shape[2]))
        right = right.reshape((data.shape[0], -1, data.shape[2]))
        new = np.column_stack((left, new, right))
        top = new[0, :, :]
        bottom = new[-1, :, :]
        for i in xrange(otoczenie - 1):
            top = np.column_stack((top, new[0, :, :]))
            bottom = np.column_stack((bottom, new[-1, :, :]))
        top = top.reshape((-1, new.shape[1], new.shape[2]))
        bottom = bottom.reshape((-1, new.shape[1], new.shape[2]))
        new = np.vstack((top, new, bottom))
        for x in xrange(otoczenie, new.shape[0] - otoczenie):
            for y in xrange(otoczenie, new.shape[1] - otoczenie):
                data[x - otoczenie, y - otoczenie] = (new[x, y] > new[x - otoczenie: x + otoczenie, y - otoczenie:y + otoczenie, :3].mean()) * 255
        self.__image = data
        self.__clear_alpha()

    def __progowanie_mieszane(self, otoczenie, odbieg):
        pass

    def __clear_alpha(self):
        if self.__image.shape[2] == 4:
            self.__image[:, :, 3] = 255
