#include <bits/stdc++.h>
using namespace std;

#define sz(o) ((int)o.size())
#define all(o) o.begin(), o.end()
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define repr(i, a, b) for(int i = (a); i >= (b); i--)
#define INF 1000000007
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

////////////POINT////////////////////
struct point_i
{
    int x, y;
    point_i(){ x = y = 0;}
    point_i(int _x, int _y) : x(_x), y(_y){}
};

struct point
{
    double x, y;
    point(){x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y){}

    bool operator < (point other) const
    {
        if(fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const
    {
        return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
    }

};

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

point rotateCCW(point p, double theta)
{
    double rad = (theta * PI) / 180.0;
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

point rotateCW(point p, double theta)
{
    double rad = (theta * PI) / 180.0;
    return point(p.x * cos(rad) + p.y * sin(rad), -p.x * sin(rad) + p.y * cos(rad));
}

////////////LINE////////////////////
struct line
{
    double a, b, c;
};

void pointsToLine(point p1, point p2, line &l)
{
    if(fabs(p1.x - p2.x) < EPS)
    {
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    }
    else
    {
        l.a = -(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}

bool areParellel(line l1, line l2)
{
    return fabs(l1.a - l2.a) < EPS && fabs(l1.b - l2.b) < EPS;
}

bool areSame(line l1, line l2)
{
    return areParellel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

bool doIntersect(line l1, line l2, point &p)
{
    if(areParellel(l1, l2)) return false;

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c) / l1.b;
    else p.y = -(l2.a * p.x + l2.c) / l2.b;

    return true;
}

////////////VECTOR///////////////////////
struct vec
{
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s)
{
    vec(v.x*s, v.y*s);
}

point translate(point p, vec v)
{
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b)
{
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v)
{
    return v.x * v.x + v.y * v.y;
}

double distToLine(point p, point a, point b, point &c)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c)
{
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if(u < 0.0)
    {
        c = point(a.x, a.y);
        return dist(p, a);
    }else if(u > 1.0)
    {
        c = point(b.x, b.y);
        return dist(p, b);
    }
    return distToLine(p, a, b, c);
}

double angle(point a, point o, point b)
{
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b)
{
    return a.x * b.y - a.y * b.x;
}

int whichSide(point p, point q, point r)
{
    double d = cross(toVec(p, q), toVec(p, r));
    if(fabs(d) < EPS) return 0; // collinear
    else if(d > -EPS) return 1; // Left
    else return -1;             // Right
}

double mag(vec v)
{
    return sqrt(norm_sq(v));
}

double areaOfTri(point a, point b, point c)
{
    return fabs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2);
}


namespace convexHull
{
    point pivot(0, 0);
    bool angleCmp(point a, point b)
    {
        if(whichSide(pivot, a, b) == 0) return dist(pivot, a) < dist(pivot, b);
        double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
        double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
        return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
    }

    vector<point> CH(vector<point> P)
    {
        int i, j, n = sz(P);
        if(n <= 3)
        {
            if(!(P[0] == P[n-1])) P.push_back(P[0]);
            return P;
        }

        int PO = 0;
        rep(i, 1, n-1)
        {
            if(P[i].y < P[PO].y or (fabs(P[i].y - P[PO].y) < EPS and P[i].x > P[PO].x)) PO = i;
        }

        swap(P[PO], P[0]);

        pivot = P[0];
        sort(++P.begin(), P.end(), angleCmp);

        vector<point> S;
        S.push_back(P[n-1]);
        S.push_back(P[0]);
        S.push_back(P[1]);
        i = 2;
        while(i < n)
        {
            j = sz(S) - 1;
            if(whichSide(S[j-1], S[j], P[i]) > 0) S.push_back(P[i++]);
            else S.pop_back();
        }

        return S;
    }
}

void solve(int testcase)
{
   
}

signed main()
{
    #ifdef VPAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(10);
    clock_t b = clock();
    int t = 1;
    //cin >> t;
    rep(tt, 1, t) solve(tt);
    clock_t e = clock();
    cerr << (double(e - b) / CLOCKS_PER_SEC) << " sec";
    return 0;
}
