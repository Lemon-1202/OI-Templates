#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
#define int long long
using namespace std;

namespace Mort1s {
  /*
  时间复杂度：O(n+q\log n)
  空间复杂度：O(n)
  */
  const int N = 1e6 + 5;
  int n, q;
  /* 重链剖分模板 */
  int tot;
  int siz[N], dep[N], son[N], fa[N], top[N], dfn[N];
  vector<int> g[N];
  inline void dfs1(int u) {
    siz[u] = 1;
    for (int v : g[u]) {
      if (v == fa[u]) continue;
      fa[v] = u, dep[v] = dep[u] + 1;
      dfs1(v);
      siz[u] += siz[v];
      if (siz[v] > siz[son[u]]) son[u] = v;
    }
  }
  inline void dfs2(int u, int tp) {
    top[u] = tp, dfn[u] = ++tot;
    if (son[u]) dfs2(son[u], tp);
    for (int v : g[u]) {
      if (v == fa[u] || v == son[u]) continue;
      dfs2(v, v);
    }
  }
  /* 重链剖分求 LCA */
  inline int lca(int u, int v) {
    int x = top[u], y = top[v];
    while (x != y) {
      if (dep[x] < dep[y]) swap(x, y), swap(u, v);
      u = fa[x], x = top[u];
    }
    return dfn[u] < dfn[v] ? u : v;
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
