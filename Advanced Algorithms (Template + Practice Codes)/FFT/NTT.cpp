const int mod = 998244353;
const int root = 31; // primitive root, works well with 998244353
const int root_1 = 128805723; // inverse of primitive root
const int root_pw = 1 << 23;

int wlena[32], wleninv[32];

void precompute()
{
    wlena[0] = root;
    wleninv[0] = root_1;
    for(int i = 1; i <= 30; i++) {
        wlena[i] = (1LL * wlena[i-1] * wlena[i-1] % mod);
        wleninv[i] = (1LL * wleninv[i-1] * wleninv[i-1] % mod);
    }
}

// keep vector size to be as close as possible to the needed maximum degree to avoid TLE
// only work with some special primes as modulo including 998244353
// inv[i] = mod - (mod/i) * inv[mod%i] % mod; -> precompute inverse of i modulo mod
// refer to https://www.codechef.com/viewsolution/42654100 for implementation

void fft(vector<int> & a, bool invert) { // size of vector a must be power of two
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    int aa = 1;
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? wleninv[23-aa] : wlena[23-aa];
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
        aa++;
    }

    if (invert) {
        int n_1 = inv[n]; // inverse of n modulo mod
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}
