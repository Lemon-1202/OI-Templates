#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const ull base = 131;
const ull mod = 1e9 + 7;
inline ull get_hash(string s) { // 单哈希
    int len = s.size();
    ull res = 0;
    for (int i = 0; i < len; i++) res = (res * base + (ull)s[i]) % mod;
    return res;
}
ull mod1 = 212370440130137957, mod2 = 1e9 + 7;
inline ull get_hash1(string s) { // 双哈希
    int len = s.size();
    ull ans = 0;
    for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod1;
    return ans;
}
inline ull get_hash2(string s) { // 双哈希
    int len = s.size();
    ull ans = 0;
    for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod2;
    return ans;
}
inline bool compare(const string s, const string t) {
    bool f1 = get_hash1(s) != get_hash1(t);
    bool f2 = get_hash2(s) != get_hash2(t);
    return f1 || f2;
}
signed main() {
    return 0;
}