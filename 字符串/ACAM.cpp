#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
class ACAM {
private:
    struct Node {
        int nex[26];
        int fail;
        int idx;
        Node() {
            memset(nex, -1, sizeof(nex));
            fail = idx = 0;
        }
    };
    vector <Node> trie;
    vector <int> vis;
    vector <int> order;
    inline int newNode() { // 新建一个节点
        trie.emplace_back();
        vis.push_back(0);
        return trie.size() - 1;
    }
public:
    ACAM() {
        newNode();
    }
    inline void clear() { // 清空
        trie.clear();
        vis.clear();
        order.clear();
        newNode();
    }
    inline void insert(string& str, int id) { // 插入一个编号为 id 的字符串 s
        int u = 0;
        for (char ch : str) {
            int c = ch - 'a';
            if (trie[u].nex[c] == -1) trie[u].nex[c] = newNode();
            u = trie[u].nex[c];
        }
        trie[u].idx = id;
    }
    inline void build() { // 构建字典树，同时添加了拓扑优化
        queue <int> q;
        for (int c = 0; c < 26; c++) {
            int v = trie[0].nex[c];
            if (v != -1) trie[v].fail = 0, q.push(v);
            else trie[0].nex[c] = 0;
        }
        while (!q.empty()) {
            int u = q.front();
            order.push_back(u);
            q.pop();
            for (int c = 0; c < 26; c++) {
                int v = trie[u].nex[c];
                if (v != -1) trie[v].fail = trie[trie[u].fail].nex[c], q.push(v);
                else trie[u].nex[c] = trie[trie[u].fail].nex[c];
            }
        }
    }
    inline void query(string& text) { // 在 AC 自动机上跑文本，标记每个经过状态的访问次数
        int u = 0;
        for (char ch : text) {
            int c = ch - 'a';
            u = trie[u].nex[c];
            vis[u]++;
        }
    }
    inline vector<int> get_result(int mx) { // 求出输入的各个模式串的出现次数
        for (int i = order.size() - 1; i >= 0; i--) {
            int u = order[i];
            vis[trie[u].fail] += vis[u];
        }
        vector <int> cnt(mx + 1, 0);
        for (int u = 0; u < (int)trie.size(); u++) {
            if (trie[u].idx != 0) {
                cnt[trie[u].idx] = vis[u];
            }
        }
        return cnt;
    }
};
ACAM ac;
signed main() {
    return 0;
}
