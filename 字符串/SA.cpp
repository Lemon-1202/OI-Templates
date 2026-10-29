#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    using pii = pair<int, int>;
    const int N = 1e6 + 5;
    int sa[N], cnt[N], id[N], rk[N << 1], tmp[N << 1];
    inline void init_sa(string s) { // 1-index
        int n = s.size() - 1;
        if (n == 1) return sa[1] = rk[1] = 1, void();
        int m = 128, p;
        // radix sort
        for (int i = 1; i <= n; i++) cnt[rk[i] = s[i]]++;
        for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
        for (int w = 1; ; w <<= 1, m = p) { // m = V
            int cur = 0;
            for (int i = n - w + 1; i <= n; i++) id[++cur] = i;
            for (int i = 1; i <= n; i++) {
                if (sa[i] > w) id[++cur] = sa[i] - w;
            }
            fill(cnt + 1, cnt + 1 + m, 0);
            for (int i = 1; i <= n; i++) cnt[rk[i]]++;
            for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
            auto rp = [&](int x) { return (pii) { tmp[x], tmp[x + w] }; };
            copy(rk + 1, rk + 1 + n, tmp + 1);
            p = 0;
            for (int i = 1; i <= n; i++) rk[sa[i]] = rp(sa[i]) == rp(sa[i - 1]) ? p : ++p;
            if (p == n) break;
        }
    }
    inline void solve() {
        string s; cin >> s;
        int n = s.size();
        s = "#" + s;
        init_sa(s);
        for (int i = 1; i <= n; i++) cout << sa[i] << " ";
    }
}
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
