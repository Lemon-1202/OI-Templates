#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    using ll = long long;
    const int N = 4e7 + 5;
    ll z[N];
    inline void getz(string s) {
        int n = s.size();
        for (int i = 2, j = 0; i <= n; i++) {
            if (i < j + z[j]) z[i] = min(z[i - j + 1], j + z[j] - i);
            while (i + z[i] <= n && s[i + z[i]] == s[1 + z[i]]) z[i]++;
            if (i + z[i] > j + z[j]) j = i;
        }
    }
    inline void solve() {
        string a, b; cin >> a >> b;
        int n = a.size(), m = b.size();
        a = "@" + a, b = "#" + b;
        a = b + a;
        getz(a);
        ll ans1 = 0, ans2 = 0;
        z[1] = m;
        for (ll i = 1; i <= m; i++) ans1 ^= i * (z[i] + 1);
        for (ll i = 1; i <= n; i++) ans2 ^= i * (z[i + m + 1] + 1);
        cout << ans1 << '\n' << ans2;
    }
}
signed main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
