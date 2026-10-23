#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
    const int N = 1e6 + 5;
    string s1, s2;
    int pi[N];
    inline void solve() {
        cin >> s1 >> s2;
        int n = s1.size(), m = s2.size();
        s1 = "#" + s1, s2 = "#" + s2;
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && s2[i] != s2[j + 1]) j = pi[j];
            if (s2[j + 1] == s2[i]) pi[i] = ++j;
        }
        for (int i = 1, j = 0; i <= n; i++) {
            while (j && s1[i] != s2[j + 1]) j = pi[j];
            if (s1[i] == s2[j + 1]) {
                if (++j == m) {
                    cout << i - m + 1 << '\n';
                    j = pi[j];
                }
            }
        }
        for (int i = 1; i <= m; i++) cout << pi[i] << " ";
    }
}
signed main() {
    IOS;
    int t = 1;
    //	cin >> t;
    while (t--) Mort1s::solve();
    return 0;
}
