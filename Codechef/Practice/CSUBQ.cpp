/*
 * Author : underdog_eagle
 * Title : CSUBQ use of double segtree to solve query of about subarrays in a range l - r	
 */
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(o) ((int)o.size())
#define eb(o) emplace_back(o)
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define repo(i, o) for(auto i = o.begin(); i != o.end(); i++)

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int maxn = 5e5;
int n, q, L, R;

struct Node{
    ll ans, pref, suf, len;
};

Node t1[4 * maxn + 5], t2[4 * maxn + 5];

inline Node combine(Node a, Node b){
    Node res;
    res.ans = a.ans + b.ans + a.suf * b.pref;
    res.pref = a.pref;
    res.suf = b.suf;
    if(a.pref == a.len) res.pref += b.pref;
    if(b.suf == b.len) res.suf += a.suf;
    res.len = a.len + b.len;
    return res;
}

inline void build1(int p, int l, int r){
    if(l == r)
        t1[p].ans = t1[p].pref = t1[p].suf = t1[p].len = 1;
    else{
        int left = p << 1, right = p << 1|1, mid = (l + r)/2;
        build1(left, l, mid);
        build1(right, mid + 1, r);
        t1[p] = combine(t1[left], t1[right]);
    }
}

inline void build2(int p, int l, int r){
    if(l == r)
        t2[p].ans = t2[p].pref = t2[p].suf = t2[p].len = 1;
    else{
        int left = p << 1, right = p << 1|1, mid = (l + r)/2;
        build2(left, l, mid);
        build2(right, mid + 1, r);
        t2[p] = combine(t2[left], t2[right]);
    }
}

inline void modify1(int p, int l, int r, int i, ll val){
    if(i > r || i < l) return;
    if(l == r)
        t1[p].ans = t1[p].pref = t1[p].suf = val <= (L - 1);
    else{
        int left = p << 1, right = p << 1|1, mid = (l + r)/2;
        modify1(left, l, mid, i, val);
        modify1(right, mid + 1, r, i, val);
        t1[p] = combine(t1[left], t1[right]);
    }
}

inline void modify2(int p, int l, int r, int i, ll val){
    if(i > r || i < l) return;
    if(l == r)
        t2[p].ans = t2[p].pref = t2[p].suf = val <= R;
    else{
        int left = p << 1, right = p << 1|1, mid = (l + r)/2;
        modify2(left, l, mid, i, val);
        modify2(right, mid + 1, r, i, val);
        t2[p] = combine(t2[left], t2[right]);
    }
}

inline Node query1(int p, int l, int r, int i, int j){
    if(i > r || j < l){
        Node res = Node();
        return res;
    }
    if(i <= l && r <= j) return t1[p];
    else{
        int left = p << 1, right = p << 1|1, mid = (l + r)/2;
        return combine(query1(left, l, mid, i, j), query1(right, mid + 1, r, i, j));
    }
}

inline Node query2(int p, int l, int r, int i, int j){
    if(i > r || j < l){
        Node res = Node();
        return res;
    }
    if(i <= l && r <= j) return t2[p];
    else{
        int left = p << 1, right = p << 1|1, mid = (l + r)/2;
        return combine(query2(left, l, mid, i, j), query2(right, mid + 1, r, i, j));
    }
}

void solve(){
    cin >> n >> q >> L >> R;
    build1(1, 1, n);
    build2(1, 1, n);
    while(q--){
        int type;
        cin >> type;
        if(type == 1){
            ll x, y;
            cin >> x >> y;
            modify1(1, 1, n, x, y);
            modify2(1, 1, n, x, y);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << query2(1, 1, n, l, r).ans - query1(1, 1, n, l, r).ans << '\n';
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(8);
    clock_t b = clock();
    solve();
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}