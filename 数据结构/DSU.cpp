#include <bits/stdc++.h>

using namespace std;
struct DSU {
    vector<int> fa, sz;
    inline void init(int n) {
        fa.resize(n + 1), sz.resize(n + 1);
        for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    }
    inline int find(int u) {
        return fa[u] == u ? u : fa[u] = find(fa[u]);
    }
    inline bool cnct(int x, int y) {
        return find(x) == find(y);
    }
    inline void mrg(int u, int v) {
        int fu = find(u), fv = find(v);
        if (sz[fu] < sz[fv]) swap(fu, fv);
        if (fu != fv) sz[fu] += sz[fv], fa[fv] = fu;
    }
};
struct DSU {
    vector<int> fa, sz, s;
    inline void init(int n) {
        fa.resize(n + 1), sz.resize(n + 1), s.clear();
        for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
    }
    inline int find(int u) {
        while (fa[u] != u) u = fa[u];
        return u;
    }
    inline void undo() {
        int x = s.back();
        s.pop_back();
        if (x > 0) sz[fa[x]] -= sz[x], fa[x] = x;
    }
    inline bool cnct(int x, int y) {
        return find(x) == find(y);
    }
    inline void mrg(int u, int v) {
        int fu = find(u), fv = find(v);
        if (sz[fu] < sz[fv]) swap(fu, fv);
        if (fu == fv) { s.push_back(-1); return; }
        s.push_back(fv), sz[fu] += sz[fv], fa[fv] = fu;
    }
};
signed main() {

    return 0;
}
