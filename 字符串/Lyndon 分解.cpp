#include <bits/stdc++.h>

using namespace std;
inline vector<string> Duval(string s) {
    int n = s.size();
    vector <string> res;
    int i = 0, j, k;
    while (i < n) {
        j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j]) k = i;
            else k++;
            j++;
        }
        int len = j - k;
        while (i <= k) {
            res.push_back(s.substr(i, len));
            i += len;
        }
    }
    return res;
}
signed main() {
    return 0;
}
