#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int pi[N];
inline void get_prefix(string s) { // 预处理 pi 数组
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
}
inline int KMP(string str, string pet) { // KMP 匹配，找到 pet 第一次在 str 中出现的位置
    int n = str.size();
    int m = pet.size();
    get_prefix(pet);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && str[i] != pet[j]) j = pi[j - 1];
        if (str[i] == pet[j]) j++;
        if (j == m) return i - m + 2;
    }
    return -1;
}
signed main() {
    return 0;
}
