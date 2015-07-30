#include <bits/stdc++.h>
#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) (u).begin(),(u).end()
#define pb push_back
#define mp make_pair
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef complex<double> P;
typedef vector<P> G;

double dot(const P& a, const P& b) { return real(conj(a)*b); }
struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};
P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}
P reflection(const L &l, const P &p) { return p + 2.0 * (projection(l, p) - p);}

int N, ans;
P s;
G g;
bool used[10];
vector<L> mirrs;

bool input(){
    cin >> N;
    if(!N) return 0;

    ans = 0;
    g.clear();
    memset(used,0,sizeof(used));

    double a, b;
    cin >> a >> b;
    s = P(a,b);
    rep(i,N){
        cin >> a >> b;
        g.pb(P(a,b));
    }
    return 1;
}

void ref_points(int cur){
    L mirror = L(g[cur], g[(cur+1)%N]);
    rep(j,N) if(j != cur && j != (cur + 1) % N) g[j] = reflection(mirror, g[j]);
}

void swap(P &p){
    double s = p.real();
    double t = p.imag();
    p = P(t, s);
}

void realmax(P &p, P q){
    double s = p.real();
    double t = q.real();
    p = P(max(s, t), p.imag());
}

void imagmin(P &p, P q){
    double s = p.imag();
    double t = q.imag();
    p = P(p.real(), min(s, t));
}

bool ok(){
    vector<P> res(2);
    res[0] = P(-PI,0);
    res[1] = P(0, PI);
    int T = mirrs.size();
    rep(i,T){
        P args = P(arg(mirrs[i].a - s), arg(mirrs[i].b - s));
        if(args.real() > args.imag()) swap(args);
        P sect[2];
        if(args.imag() - args.real() > PI + EPS) {
            sect[0] = P(-PI, args.real());
            sect[1] = P(args.imag(), PI);
        }
        else if(args.real() < 0 && args.imag() < 0){
            sect[0] = P(args.real(), args.imag());
            sect[1] = P(0, 0);
        }
        else if(args.real() < 0 && args.imag() >= 0){
            sect[0] = P(args.real(), 0);
            sect[1] = P(0, args.imag());
        }
        else {
            sect[0] = P(0, 0);
            sect[1] = P(args.real(), args.imag());
        }
        rep(i,res.size()){
            realmax(res[i], sect[i]);
            imagmin(res[i], sect[i]);
        }
    }
    rep(i,res.size()) if(res[i].imag() - res[i].real() < EPS) {
        res.erase(res.begin() + i, res.begin() + i + 1);
        i--;
    }
    return res.size();
}

void dfs(){
    if(mirrs.size() == N){
        if(ok()) ans++;
        return;
    }

    rep(i,N) if(!used[i]) {
        used[i] = 1;
        mirrs.pb(L(g[i],g[(i+1)%N]));
        ref_points(i);
        dfs();
        ref_points(i);
        mirrs.pop_back();
        used[i] = 0;
    }
}

int solve(){
    dfs();
    return ans;
}

signed main(){
    while(input()){ cout << solve() << endl;}
    return 0;
}
