#include <bits/stdc++.h>

using namespace std;
const int N = 3e6 + 5;
const int L = 66;
inline int calc(char c) { // 算是哈希吧
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    return c - 'A' + 36;
}
struct Trie { // 字典树
    int nex[N][L], cnt;
    int tot[N];
    bool exist[N];
    inline void init() {
        for (int i = 0; i <= cnt; i++) {
            tot[i] = 0, exist[i] = 0;
            for (int j = 0; j < L; j++) {
                nex[i][j] = 0;
            }
        }
    }
    inline void insert(char* s, int l) {
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = calc(s[i]);
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
            tot[p]++;
        }
        exist[p] = 1;
    }
    inline bool find(char* s, int l) {
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = calc(s[i]);
            if (!nex[p][c]) return false;
            p = nex[p][c];
        }
        return exist[p];
    }
    inline int search(char* s, int l) {
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = calc(s[i]);
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return tot[p];
    }
} trie;
signed main() {
    return 0;
}