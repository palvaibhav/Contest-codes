#include <bits/stdc++.h>
using namespace std;
 
#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
 
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<int> vi;
 
const int maxn = 905, mxbit = 31;
ll n, a[maxn];
 
struct node{
    node* child[2];
    node(){
        child[0] = child[1] = NULL;
    }
};
 
node* root = new node();
 
void insert(node* u, int pos, ll x){
    if(pos==-1) return;
    int bit = (x>>pos)&1;
    if(u->child[bit]==NULL) u->child[bit] = new node();
    insert(u->child[bit], pos-1, x);
}
 
void maximize(node* u, int pos, ll x, ll &p){
    if(pos==-1)return;
    int bit = (x>>pos)&1;
    if(u->child[!bit]!=NULL){
        if(!bit) p |= (1<<pos);
        maximize(u->child[!bit], pos-1, x, p);
    }else{
        if(bit) p |= (1<<pos);
        maximize(u->child[bit], pos-1, x, p);
    }
}
 
void solve(int testcase) {
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ll mx = 0;
    repr(i, n, 1){
        ll sum = 0;
        rep(j, i, n){
            sum+=a[j];
            insert(root, mxbit, sum);
        }
        sum = 0;
        repr(j, i-1, 1) {
            sum += a[j];
            ll p = 0;
            maximize(root, mxbit, sum, p);
            mx = max(mx, p ^ sum);
        }
    }
    cout << mx;
}
 
int main() {
    #ifdef VPAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(2);
    clock_t b = clock();
    int t = 1;
    //cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}