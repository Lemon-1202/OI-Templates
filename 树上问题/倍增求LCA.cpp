#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
#define int long long
using namespace std;

namespace Mort1s {
  /*
  时间复杂度：O(n\log n+q\log n)
  空间复杂度：O(n\log n)
  */
  const int N = 1e6 + 5;
  const int LOG = 25;
  int n, q;
  int anc[N][LOG], dep[N];
  vector<int> g[N];
  inline void dfs(int u, int fa) {
    anc[u][0] = fa;
    for (int i = 1; i < LOG; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for (int v : g[u]) {
      if (v == fa) continue;
      dep[v] = dep[u] + 1;
      dfs(v, u);
    }
  }
  inline int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
      if (dep[anc[u][i]] >= dep[v]) u = anc[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
      if (anc[u][i] != anc[v][i]) u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
  }
  inline void solve() {

  }
}
signed main() {
  IOS;
  int t = 1;
  // cin >> t;
  while (t--) Mort1s::solve();
  return 0;
}
