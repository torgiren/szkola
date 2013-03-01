#*-* coding: utf8 *-*
"""Moduł zawierający klasy używane do przetwarzania obrazu"""
import Image
import numpy as np


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
            if not self.__image:
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
        self.__image = Image.open(path)

    @image_loaded
    def negative(self):
        """Tworzy negatyw obrazu"""
        data = np.array(self.__image.getdata())
        data = 255 - data
        data = [tuple(x) for x in data]
        self.__image.putdata(data)

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

    @image_loaded
    def convert(self, fmt):
        self.__image = self.__image.convert(fmt)
        """Konwertuje obraz do zadanego formatu"""

    @image_loaded
    def normalize(self):
        data = np.array(self.__image.getdata())
        R = data[:, 0]
        G = data[:, 1]
        B = data[:, 2]
        R = (R - R.min()) * 255. / R.max()
        B = (B - B.min()) * 255. / B.max()
        B = (B - B.min()) * 255. / B.max()

        data[:, 0] = R
        data[:, 1] = G
        data[:, 2] = B

        data = [tuple(x) for x in data]
        self.__image.putdata(data)

    @image_loaded
    def save(self, path):
        """Zapisuje obraz do pliku"""
        if not self.__image:
            raise NoImageError
        self.__image.save(path)

    def __grayscale1(self):
        """Konwersja do skali szarości"""
        data = np.array(self.__image.getdata())
        data = [3 * (int(x.mean()),) for x in data]
        self.__image.putdata(data)

    def __grayscale2(self):
        """konwersja do skali szarości"""
        data = np.array(self.__image.getdata())
        data = [3 * (int(0.3 * x[0] + 0.59 * x[1] + 0.11 * x[2]),) for x in data]
        self.__image.putdata(data)
