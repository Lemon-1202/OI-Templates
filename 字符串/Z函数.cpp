#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 2e7 + 5;
ll z[N];
ll p[N];
inline void getz(string str) { // 求自己的 Z 函数
    int n = str.size();
    z[0] = n;
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min((ll)z[i - l], (ll)r - i + 1);
        }
        while (i + z[i] < n && str[i + z[i]] == str[z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}
inline void getp(string str, string pat) { // 求文本串的后缀和模式串的 LCP
    int n = str.size(), m = pat.size();
    int l = 0;
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (i <= r) {
            p[i] = min(z[i - l], (ll)r - i + 1);
        }
        while (i + p[i] < n && p[i] < m && str[i + p[i]] == pat[p[i]]) {
            p[i]++;
        }
        if (i + p[i] - 1 > r) {
            l = i;
            r = i + p[i] - 1;
        }
    }
}
signed main() {
    return 0;
}
