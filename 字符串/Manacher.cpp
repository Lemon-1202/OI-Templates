#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    const int N = 3e7 + 5;
    int ans;
    int p[N];
    inline void Manacher(string t) {
        int n = t.size();
        string s = "^#";
        for (char c : t) s.push_back(c), s.push_back('#');
        s.push_back('@');
        for (int i = 1, j = 0; i <= 2 * n + 1; i++) {
            if (i <= j + p[j]) p[i] = min(p[2 * j - i], j + p[j] - i);
            while (s[i + p[i] + 1] == s[i - p[i] - 1]) p[i]++;
            if (i + p[i] > j + p[j]) j = i;
            ans = max(ans, p[i]);
        }
    }
    inline void solve() {
        string s; cin >> s;
        Manacher(s);
        cout << ans;
    }
}
signed main() {
    IOS;
    int t = 1;
    // cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
