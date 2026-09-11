#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;
struct SGT { // 线段树
    // 仅作为示例，实际要根据题目去分析修改
#define ls p << 1
#define rs p << 1 | 1
    struct info {
        inline void set(int x) {}
    } w[N << 2];
    struct tag {
        inline void reset() {}
    } t[N << 2];
    inline info merge(info x, info y) { // 合并 x 与 y 的信息

    }
    inline tag compose(tag x, tag y) { // 把 y 的标记传递给标记 x

    }
    inline info apply(info x, tag y) { // 把 y 的标记传递给信息 x

    }
    inline void pushup(int p) { w[p] = merge(w[ls], w[rs]); }
    inline void maketag(int p, tag& k) { w[p] = apply(w[p], k), t[p] = compose(t[p], k); }
    inline void pushdown(int p) {
        maketag(ls, t[p]), maketag(rs, t[p]), t[p].reset();
    }
    inline info ask(int p, int l, int r, int nl, int nr) { // 查询区间 [nl,nr] 的信息
        if (nl <= l && r <= nr) return w[p];
        int mid = (l + r) >> 1; pushdown(p);
        if (nr <= mid) return ask(p << 1, l, mid, nl, nr);
        if (nl > mid) return ask(p << 1 | 1, mid + 1, r, nl, nr);
        return merge(ask(p << 1, l, mid, nl, nr), ask(p << 1 | 1, mid + 1, r, nl, nr));
    }
    inline int SRCH(int p, int l, int r, int nl, int nr, info& cur, int k) { // 区间内二分查找第一个满足条件的位置
        if (nl <= l && r <= nr) {
            if (merge(cur, w[p]) > k) return cur = merge(cur, w[p]), -1;
            if (l == r) return l;
        }
        int mid = l + r >> 1; pushdown(p);
        if (nl <= mid) {
            int t = SRCH(p << 1, l, mid, nl, nr, cur, k);
            if (t != -1) return t;
        }
        return (nr > mid ? SRCH(p << 1 | 1, mid + 1, r, nl, nr, cur, k) : -1);
    }
    inline int search(int p, int l, int r, int nl, int nr, int k, info cur) {
        return SRCH(p, l, r, nl, nr, cur, k);
    }
    inline void build(int p, int l, int r) { // 构建
        t[p].reset();
        if (l == r) return w[p].set(1);
        int mid = (l + r) >> 1;
        build(p << 1, l, mid), build(p << 1 | 1, mid + 1, r), pushup(p);
    }
} tr;
signed main() {

    return 0;
}
