/* Luogu P8306 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fir first
#define sec second
using namespace std;

namespace Mort1s {
  const int N = 3e6 + 5;
  const int L = 66;
  int n, q;
  inline int calc(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return c - 'A' + 36;
  }
  struct Trie {
    int nex[N][L], cnt;
    int tot[N];
    bool exist[N];
    inline void init() {
      for (int i = 0; i <= cnt; i++) {
        tot[i] = exist[i] = 0;
        for (int j = 0; j < L; j++) nex[i][j] = 0;
      }
      cnt = 0;
    }
    inline void insert(string s) {
      int u = 0;
      for (char c : s) {
        int x = calc(c);
        if (!nex[u][x]) nex[u][x] = ++cnt;
        u = nex[u][x], tot[u]++;
      }
      exist[u] = 1;
    }
    inline bool find(string s) {
      int u = 0;
      for (char c : s) {
        int x = calc(c);
        if (!nex[u][x]) return false;
        u = nex[u][x];
      }
      return exist[u];
    }
    inline int search(string s) {
      int u = 0;
      for (char c : s) {
        int x = calc(c);
        if (!nex[u][x]) return 0;
        u = nex[u][x];
      }
      return tot[u];
    }
  } tr;
  inline void solve() {
    tr.init();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      string s; cin >> s;
      tr.insert(s);
    }
    while (q--) {
      string s; cin >> s;
      cout << tr.search(s) << '\n';
    }
  }
}
signed main() {
  IOS;
  int t = 1;
  cin >> t;
  while (t--) Mort1s::solve();
  return 0;
}
