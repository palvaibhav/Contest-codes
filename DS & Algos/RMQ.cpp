#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+10, BITS = 22;
int n, q, timer, xl, vl, in[MAXN], out[MAXN], who[MAXN], w[MAXN];
vector<int> adj[MAXN];

struct RMQ {
    vector<int> a;
    int N;

    RMQ(int sz) {
        N = 1 << (32 - __builtin_clz(sz));
        a = vector<int>(2 * N, INT_MAX);
    }

    void setMin(int pos, int x) {
        for (int i = pos + N; i; i >>= 1) a[i] = min(a[i], x);
    }

    int getMin(int L, int R) { // [L, R) i.e. L <= i < R
        int res = INT_MAX;
        for (L += N, R += N; L < R; L >>= 1, R >>= 1) {
            if (L & 1) {
                res = min(res, a[L]);
                L++;
            }
            if (R & 1) {
                R--;
                res = min(res, a[R]);
            }
        }
        return res;
    }
};

struct Node {
    Node* ch[2];
    vector<int> range[2];
    bool sorted = false;
    RMQ* st[2];

    void add(int pos, int x, int i, int u) {
        if (pos < 0) return;
        int bit = ((x & (1 << pos)) != 0);
        if (!ch[bit]) ch[bit] = new Node();
        range[bit].push_back(i);
        ch[bit]->add(pos - 1, x, i, u);
    }

    int lbRange(int bit, int val) {
        int pos = (lower_bound(range[bit].begin(), range[bit].end(), val) - range[bit].begin());
        if (pos == (int)range[bit].size()) return -1;
        return pos;
    }

    int ubRange(int bit, int val) {
        int pos = (upper_bound(range[bit].begin(), range[bit].end(), val) - range[bit].begin());
        if (pos == (int)range[bit].size()) pos--;
        return pos;
    }

    void maximize(int pos, int x, int l, int r, int& res) {
        if (l == r) {
            res = who[l];
            return;
        }
        if (pos < 0) {
            return;
        }
        int bit = ((x & (1 << pos)) != 0);
        if (!sorted) {
            for (int i = 0; i < 2; i++) sort(range[i].begin(), range[i].end());
            sorted = true;
        }
        int il1 = lbRange(!bit, l);
        int ir1 = ubRange(!bit, r);
        int il2 = lbRange(bit, l);
        int ir2 = ubRange(bit, r);
        if (ch[!bit] && (il1 != -1 && range[!bit][il1] <= r)) {
            l = range[!bit][il1];
            r = range[!bit][ir1 - (range[!bit][ir1] > r)];
            res = st[!bit]->getMin(il1, ir1 - (range[!bit][ir1] > r) + 1);
            ch[!bit]->maximize(pos - 1, x, l, r, res);
        } else if (ch[bit] && (il2 != -1 && range[bit][il2] <= r)) {
            l = range[bit][il2];
            r = range[bit][ir2 - (range[bit][ir2] > r)];
            res = st[bit]->getMin(il2, ir2 - (range[bit][ir2] > r) + 1);
            ch[bit]->maximize(pos - 1, x, l, r, res);
        }
    }

    void buildRMQ() {
        for (int i = 0; i < 2; i++) {
            int sz = range[i].size();
            st[i] = new RMQ(sz);
            for (int j = 0; j < sz; j++) {
                int idx = range[i][j];
                st[i]->setMin(j, who[idx]);
            }
            if (ch[i]) ch[i]->buildRMQ();
        }
    }

    void del() {
        if (ch[0]) ch[0]->del();
        if (ch[1]) ch[1]->del();
        delete(this);
    }
};

void clear() {
    timer = 0;
    xl = 0;
    vl = 0;
    for (int i = 1; i <= n; i++) adj[i].clear();
}

void dfs(int u, int pa) {
    in[u] = ++timer;
    who[timer] = u;
    for (int v : adj[u]) if (v != pa) {
            dfs(v, u);
        }
    out[u] = timer;
}

int main() {
    //~ freopen("in.txt", "r", stdin);
    //~ freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        Node* trie = new Node();
        for (int i = 1; i <= n; i++) {
            trie->add(BITS - 1, w[who[i]], i, who[i]);
        }
        trie->buildRMQ();
        while (q--) {
            int a, b;
            cin >> a >> b;
            int v = (a ^ vl);
            int k = (b ^ xl);
            int l = in[v], r = out[v];
            int ans = 0, node = INT_MAX;
            trie->maximize(BITS - 1, k, l, r, node);
            ans = (k ^ w[node]);
            cout << node << " " << ans << "\n";
            xl = ans;
            vl = node;
        }
        trie->del();
        clear();
    }
    return 0;
}
