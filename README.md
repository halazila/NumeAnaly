# NumeAnaly
# nestmultp.c`
nest multiply, to calculate value of a polynomial
polynomial express: y = c[0] + c[1]*x^1 + c[2]*x^2 + ... + c[n-1]*x^(n-1)
it can be rewrite as: y = c[0] + x * ( c[1] + x * ( c[2] + x * ( c[3] + x * ( c[4] + ... + x * ( c[n-2] + x * c[n-1])...))))
generally, add array {r,n}, it can be writed as:
y = c[0] + (x - r[1]) * ( c[1] + (x - r[2]) * ( c[2] + (x - r[3]) * ( c[3] + (x - r[4]) * ( c[4] + ... + (x - r[n-2]) * ( c[n-2] + (x - r[n-1]) * c[n-1])...)))),
which represents formula : 
y = c[0] + c[1] * (x - r[1]) + c[2] * (x - r[1]) * (x - r[2]) + c[3] * (x - r[1]) * (x - r[2]) * (x - r[3])...
