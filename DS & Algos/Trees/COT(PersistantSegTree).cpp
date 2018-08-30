/**
	SPOJ Problem :- COT
**/

#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;

void fs(int &nn) {
    bool neg = false;
    register int ch;
    nn = 0;
    ch = getchar();
    if (ch == '-') {
        neg = true;
        ch = getchar();
    }
    for (; (ch > 47 && ch < 58); ch = getchar()) nn = nn * 10 + ch - 48;
    if (neg) nn *= -1;
}

const int maxn = 111111, maxlogn = 19;
int pa[maxn][maxlogn], depth[maxn], rm[maxn], w[maxn], n, maxi;
vi adj[maxn];
map<int, int> M;

struct node {
    int count;
    node *left, *right;
    node(int count, node *left, node *right) :count(count), left(left), right(right) {}
};

node *root[maxn];
node *null = new node(0, NULL, NULL);

node* build(node *cur, int l, int r, int c) {
    if (l == r) return new node(cur->count + 1, null, null);
    else {
        int mid = (l + r) >> 1;
        node *newNode = new node(0, null, null);
        if (c <= mid) {
            newNode->right = cur->right;
            newNode->left = build(cur->left, l, mid, c);
            newNode->count = newNode->left->count + newNode->right->count;
        }
        else {
            newNode->left = cur->left;
            newNode->right = build(cur->right, mid + 1, r, c);
            newNode->count = newNode->left->count + newNode->right->count;
        }
        return newNode;
    }
}

void dfs(int u, int prev) {
    pa[u][0] = prev;
    depth[u] = depth[prev] + 1;
    root[u] = build(root[prev], 1, maxi, M[w[u]]);
    for (auto v : adj[u]) {
        if (v == prev) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        return lca(v, u);

    int diff = depth[u] - depth[v];

    rep(i, 0, maxlogn)
        if ((diff >> i) & 1)
            u = pa[u][i];

    if (u != v)
    {
        repr(i, maxlogn - 1, 0)
        if (pa[u][i] != pa[v][i])
        {
            u = pa[u][i];
            v = pa[v][i];
        }
        u = pa[u][0];
    }

    return u;
}

int query(node *a, node *b, node *c, node *d, int l, int r, int k) {
    if (l == r) return l;
    else {
        int mid = (l + r) >> 1;
        int count = a->left->count + b->left->count - c->left->count - d->left->count;
        if (count >= k) return query(a->left, b->left, c->left, d->left, l, mid, k);
        return query(a->right, b->right, c->right, d->right, mid + 1, r, k - count);
    }
}

void solve() {
    int m;
    fs(n);
    fs(m);

    /*** Cordinate compression of weights ***/
    rep(i, 1, n) {
        fs(w[i]);
        M[w[i]];
    }

    maxi = 0;
    for (auto it = M.begin(); it != M.end(); it++) {
        M[it->first] = ++maxi;
        rm[maxi] = it->first;
    }

    rep(i, 1, n - 1) {
        int u, v;
        fs(u);
        fs(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*** Filling depth and immediate parent information & Building presistant segtrees for each node in nlogn***/
    null->left = null->right = null;
    root[0] = null;
    depth[0] = -1;
    memset(pa, -1, sizeof(pa));
    dfs(1, 0);
    pa[0][0] = 0;
    pa[1][0] = 1;

    /*** DP jump table filling ***/
    int ln = log2(n);
    rep(j, 1, ln)
        rep(i, 1, n)
            if (pa[i][j - 1] != -1)
                pa[i][j] = pa[pa[i][j - 1]][j - 1];


    /*** Answering queries ***/
    while (m--) {
        int u, v, k;
        fs(u);
        fs(v);
        fs(k);
        int LCA = lca(u, v);
        printf("%d\n", rm[query(root[u], root[v], root[LCA], LCA == 1 ? null : root[pa[LCA][0]], 1, maxi, k)]);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    cout << setprecision(10);
    clock_t b = clock();
    solve();
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}