import numpy as np


class Wektor:
    def __init__(self, vals):
        self.matrix = np.array(vals)

    def __add__(self, val):
        if hasattr(val, '__class__') and val.__class__ is Wektor:
            return Wektor(self.matrix + val.matrix)
        else:
            return Wektor(self.matrix + val)

    def __sub__(self, val):
        return Wektor(self - (-1 * val))

    def __mul__(self, val):
        if hasattr(val, '__class__') and val.__class__ is Wektor:
            return Wektor(np.dot(self.matrix, val.matrix)), Wektor(np.cross(self.matrix, val.matrix))
        else:
            return Wektor(self.matrix * val)

    __rmul__ = __mul__

    def len(self):
        return self.matrix.size

    def __str__(self):
        return str(self.matrix)
