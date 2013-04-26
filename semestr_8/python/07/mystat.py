"""To jest modul statystyczny"""
import math


def avg(values):
    """Obliczamy srednia wartosc z podanego wektora"""
    return float(sum(values)) / len(values)


def odchylenie(values):
    """Obliczanie odchylenia std"""
    sr = avg(values)
    return math.sqrt(sum([(sr - x) ** 2 for x in values]) / len(values))


def mediana(values):
    """Zwraca mediane z zadanego wektora"""
    values.sort()
    return values[len(values) / 2]


def rozstep(values):
    """Zwraca rozstep z zadanego wektora"""
    return max(values) - min(values)
