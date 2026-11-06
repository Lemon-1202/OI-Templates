#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
#define int long long
using namespace std;

namespace Mort1s {
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
  /* 建立虚树 */
  int k;
  vector<int> e[N]; // 存储虚树的边
  vector<int> v;    // 虚树上的点的点集
  int a[N];  // a 是选取的关键点
  bool b[N]; // b 记录这个点是不是关键点
  inline bool cmp(int u, int v) {
    return dfn[u] < dfn[v];
  }
  inline void build() {
    sort(a + 1, a + 1 + k, cmp);
    v.clear();
    v.push_back(a[1]);
    for (int i = 2; i <= k; i++) v.push_back(a[i]), v.push_back(lca(a[i], a[i - 1]));
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i < (int)v.size(); i++) {
      int p = lca(v[i], v[i - 1]);
      e[p].push_back(v[i]);
    }
  }
  // 树形 DP
  int f[N];
  inline void work(int u) {
    for (int v : e[u]) {
      work(v);
      /* 树形 DP */
    }
    e[u].clear();
  }
  inline void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v), g[v].push_back(u);
    }
    dfs1(1);
    dfs2(1, 1);
    cin >> q;
    while (q--) {
      cin >> k;
      for (int i = 1; i <= k; i++) cin >> a[i], b[a[i]] = 1;
      build();
      work(v[0]);
      for (int i = 1; i <= k; i++) b[a[i]] = 0;
    }
  }
}
signed main() {
  IOS;
  int t = 1;
  // cin >> t;
  while (t--) Mort1s::solve();
  return 0;
}
