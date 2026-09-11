#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int LOG = 20;
int nxt[N];
int up[N][LOG + 1];
int dep[N];
inline void get_prefix(const string& str) { // 求 pi 数组
    int n = str.size() - 1;
    nxt[1] = 0;
    for (int i = 2; i <= n; i++) {
        int j = nxt[i - 1];
        while (j > 0 && str[i] != str[j + 1]) j = nxt[j];
        if (str[i] == str[j + 1]) j++;
        nxt[i] = j;
    }
}
inline int lca(int u, int v) { // lca 模板
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int i = 0; i <= LOG; i++) {
        if (diff >> i & 1) u = up[u][i];
    }
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--) {
        if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
    }
    return up[u][0];
}
string s;
int m;
namespace Solution {
    inline void Main() {
        cin >> s;
        s = " " + s;
        int n = s.size() - 1;
        get_prefix(s);
        dep[0] = 0;
        for (int i = 0; i <= LOG; i++) {
            up[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            up[i][0] = nxt[i];
            dep[i] = dep[nxt[i]] + 1;
            for (int j = 1; j <= LOG; j++) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
        cin >> m;
        while (m--) {
            int p, q;
            cin >> p >> q;
            int ans = lca(p, q);
            if (ans == p || ans == q) ans = up[ans][0];
            cout << ans << '\n';
        }
    }
}
signed main() {
    Solution::Main();
    return 0;
}
