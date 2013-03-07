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
    def save(self, path):
        """Zapisuje obraz do pliku"""
        if self.__image.shape[2] == 4:
            self.__image[:, :, 3] = 255
        misc.imsave(path, self.__image)

    def __grayscale1(self):
        """Konwersja do skali szarości"""
        data = self.__image
#        data[:,:] = 3 * (data[:,:].mean())
#        x = [4 * (int(x.mean()),) for x in data]
        size = data.shape
        tmp = data.reshape(size[0] * size[1], size[2])
        tmp = np.array([size[2] * [z.mean(),] for z in tmp])
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
                new[x * factor:(x + 1 ) * factor, y * factor:(y + 1) * factor, :] = data[x, y, :]
        self.__image = new
