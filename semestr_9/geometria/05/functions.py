def prosta(A, B):
    a = (A[1] - B[1]) / (A[0] - B[0])
    b = A[1] - a * A[0]
    return (a, b)


def przeciecie(A1, A2, B1, B2):

#    a = (y1 - y2) / (x1 - x2)
#    b=  y1- ax1
    p1 = prosta(A1, A2)
    p2 = prosta(B1, B2)

    #q1 = (p2[1] - p1[0]) / (p1[0] - p2[0])
    #q2 = (p1[0] * q1 + p1[0])

    #q1 = (b2 - b1) / (a1 - a2)
    #q2 = (a1 * q1 + b1)

    q1 = (p2[1] - p1[1]) / (p2[0] - p1[0])
    q2 = p1[0] * q1 + p1[1]

    return (-q1, -q2)


def DiagonalIntExt(i, j, n):
    for k in range(n):
        k1 = (k + 1) % n
        if not ((k == i) or (k1 == i) or (k == j) or (k1 == j)):
            return False
    return True
