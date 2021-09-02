/**
 * area = D/2
 * or area = abs(Ax*(By−Cy) + Bx*(Cy − Ay) + Cx*(Ay - By)) / 2
 * NOTE: A,B,C should be given in COUNTER-CLOCKWISE order
 * =================================
 * D =
 * (x1-x2) (x1-x3)     | a   c |
 * (y1-y2) (y1-y3)     | b   d |
 */
long long tridet(){ /// returns the determinant, the area is tridet()/2;
    long long a = x0 - x1, b = x0 - x2, c = y0 - y1, d = y0 - y2;
    return abs((a*d - c*b));
}