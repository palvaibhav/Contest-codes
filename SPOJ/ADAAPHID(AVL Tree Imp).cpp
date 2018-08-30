#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000000000000000LL
#define MOD 1000000007
#define EPS 1e-9
#define PI 3.1415926535
#define ff first
#define ss second
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<pi> vpi;

struct item{
    ll key, val, sum, h;
    item *l, *r;
    item(ll key, ll val): key(key), val(val), sum(0), l(NULL), r(NULL){}
};

typedef item* pitem;

ll height(pitem t){ return t ? t->h : 0; }

void upd_height(pitem t){ t->h = 1 + max(height(t->l), height(t->r)); }

ll sum(pitem t){ return t ? t->sum : 0; }

void upd_sum(pitem t){ t->sum = t->val + sum(t->l) + sum(t->r); }

void updation(pitem t){
    upd_height(t);
    upd_sum(t);
}

void left_rotate(pitem &t){
    pitem temp = t;
    t = t->r;
    temp->r = t->l;
    t->l = temp;
    updation(t);
    updation(t->l);
}

void right_rotate(pitem &t){
    pitem temp = t;
    t = t->l;
    temp->l = t->r;
    t->r = temp;
    updation(t);
    updation(t->r);
}

void check_balance(pitem &t){
    if(abs(height(t->l) - height(t->r)) > 1){
        ll x = height(t->l) - height(t->r);
        if(x < 0){
            ll y = (t->r ? (height(t->r->l) - height(t->r->r)) : 0);
            if(y < 0)  left_rotate(t);   // Case R-R
            else{                        // Case R-L
                right_rotate(t->r);
                left_rotate(t);
            }
        }else{
            ll y = (t->l ? (height(t->l->l) - height(t->l->r)) : 0);
            if(y < 0){
                left_rotate(t->l);   // Case L-R
                right_rotate(t);
            }
            else{                    // Case L-L
                right_rotate(t);
            }
        }
    }
}

void insert(pitem &t, pitem it){
    if(!t) t = it;
    else if(t->key == it->key) t->val += it->val;
    else if(t->key < it->key) insert(t->r, it);
    else insert(t->l, it);
    check_balance(t);
    updation(t);
}

ll search(pitem t, ll x){
    if(!t) return 0;
    else if(t->key <= x) return sum(t->l) + t->val + search(t->r, x);
    else return search(t->l, x);
}

ll q, a, v, l;

pitem tree;

void solve(int testcase) {
    cin >> q;
    rep(i, 1, q){
        cin >> a >> v;
        a ^= l, v ^= l;
        ll sum = v + search(tree, a);
        item *newItem = new item(a, v);
        insert(tree, newItem);
        cout << a << ' ' << sum << '\n';
        l = sum;
    }
}

int main() {
    #ifdef VPAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(20);
    clock_t b = clock();
    int t = 1;
    //cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}
