// extended gcd
// by pin3da
// ref https://github.com/pin3da/Programming-contest/blob/master/solved/kattis/2018%20NAIPC%20Practice%20Contest%2001/Candy%20Distribution/solution.cc

void ext_euclid(long long a, long long b, long long &x, long long &y, long long &g) {
  x = 0, y = 1, g = b;
  long long m, n, q, r;
  for (long long u = 1, v = 0; a != 0; g = a, a = r) {
    q = g / a, r = g % a;
    m = x - u * q, n = y - v * q;
    x = u, y = v, u = m, v = n;
  }
}