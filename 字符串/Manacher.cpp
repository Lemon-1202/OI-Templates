#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int Manacher(string str) { // 求出最长 Border
    int n = str.size();
    vector <int> p(2 * n + 5);
    vector <char> t(2 * n + 5);
    int m = 0;
    t[++m] = '$';
    for (int i = 0; i < n; i++) t[++m] = str[i], t[++m] = '$';
    int M = 0, R = 0;
    for (int i = 1; i <= m; i++) {
        if (i > R) p[i] = 1;
        else p[i] = min(p[2 * M - i], R - i + 1);
        while (i - p[i] >= 1 && i + p[i] <= m && t[i - p[i]] == t[i + p[i]]) p[i]++;
        if (i + p[i] - 1 > R) M = i, R = i + p[i] - 1;
    }
    return *max_element(p.begin(), p.end()) - 1;
}
string s;
namespace Solution {
    inline void Main() {
        cin >> s;
        cout << Manacher(s);
    }
}
signed main() {
    int T = 1;
    // cin >> T;
    while (T--) Solution::Main();
    return 0;
}
