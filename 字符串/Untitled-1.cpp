#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
const int BIT = 30;
const int M = N * (BIT + 1);
struct Trie { // 01Trie
    int nex[M][2], tot;
    Trie() {
        tot = 1;
        memset(nex, 0, sizeof(nex));
    }
    inline void insert(int x) {
        int p = 1;
        for (int i = BIT; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (!nex[p][c]) nex[p][c] = ++tot;
            p = nex[p][c];
        }
    }
    inline int get(int x) {
        int res = 0, p = 1;
        for (int i = BIT; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nex[p][c ^ 1]) {
                res |= (1 << i);
                p = nex[p][c ^ 1];
            } else {
                p = nex[p][c];
            }
        }
        return res;
    }
} trie;
signed main() {
    return 0;
}