#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    using pii = pair<int, int>;
    const int N = 1e6 + 5;
    int rk[N << 1], sa[N], tmp[N << 1], cnt[N];
    inline void init_sa(string s) { // 1-index
        int n = s.size() - 1;
        if (n == 1) return void(rk[1] = sa[1] = 1);
        for (int i = 1; i <= n; i++) sa[i] = i, rk[i] = s[i];
        for (int w = 1, m = max(128, n); w < n; w <<= 1) {
            fill(cnt + 1, cnt + 1 + m, 0);
            for (int i = 1; i <= n; i++) cnt[rk[sa[i] + w]]++;
            for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; i--) tmp[cnt[rk[sa[i] + w]]--] = sa[i];
            fill(cnt + 1, cnt + 1 + m, 0);
            for (int i = 1; i <= n; i++) cnt[rk[tmp[i]]]++;
            for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
            for (int i = n; i >= 1; i--) sa[cnt[rk[tmp[i]]]--] = tmp[i];
            auto rp = [&](int x) { return (pii) { rk[x], rk[x + w] }; };
            for (int i = 1, p = 0; i <= n; i++) tmp[sa[i]] = rp(sa[i - 1]) == rp(sa[i]) ? p : ++p;
            copy(tmp + 1, tmp + n + 1, rk + 1);
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
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
