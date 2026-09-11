#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
template <typename T>
struct Fenwick {
    int n; vector<T> c; fenwick() = default; fenwick(int n) { resize(n); }
    void resize(int x) { n = x + 1, c.resize(n + 1); }
    void clear() { c.clear(), n = 0; }
    void reset() { c.assign(n + 1, 0); }
    void upd(int x, T val) { assert(x >= 0); for (x++; x <= n; x += x & -x) c[x] += val; }
    T ask(int x) { T r = 0; for (x = min(x + 1, n); x; x -= x & -x) r += c[x]; return r; }
};
signed main() {

    return 0;
}
