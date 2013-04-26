"""Modul do kodowania i dekodowania szyfru cesara"""
import operator


def code(data, key):
    result = []
    for d in data:
        if d.isalpha():
            new = ord(d) + key
            if d.islower():
                if new > 122:
                    new -= 26
            else:
                if new > 90:
                    new -= 26
            d = chr(new)
        result.append(d)
    return "".join(result)


def decode(data):
    """dekoduje tekst"""
    tab = {'a': 8.91, 'b': 1.47, 'c': 3.96, 'd': 3.25, 'e': 7.66, 'f': 0.30, 'g': 1.42, 'h': 1.08, 'i': 8.21, 'j': 2.28, 'k': 3.51, 'l': 2.10, 'm': 2.80, 'n': 5.52, 'o': 7.75, 'p': 3.13, 'r': 4.69, 's': 4.32, 't': 3.98, 'u': 2.50, 'w': 4.65, 'y': 3.76, 'z': 5.64}
    tab = sorted(tab.items(), key=operator.itemgetter(1))
    czestosc = {}
    for i in range(ord('a'), ord('z') + 1):
        a = data.count(chr(i))
        if czestosc.has_key(chr(i)):
            czestosc[chr(i)] += a
        else:
            czestosc[chr(i)] = a
    czestosc = sorted(czestosc.items(), key=operator.itemgetter(1))
    tab = [a[0] for a in tab[::-1]]
    czestosc = [a[0] for a in czestosc[::-1]]
    print tab
    print czestosc
    print zip(tab,czestosc)
