#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <bitset>

#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

/* 外積 */
double cross(const P& a, const P& b) {return imag(conj(a)*b);}
/* 内積 */
double dot(const P& a, const P& b) {return real(conj(a)*b);}
/* 角度 */
double angle(const P &a, const P &b){return arg(conj(a)*b);}
/* 回転 */
P rotate(const P& a, double th){return a*polar(1.0, th);}
/* 線分 */
struct L {
    P a, b;
    L(const P &a, const P &b) : a(a), b(b){ }
};
/* 正射影(Lがスクリーン) */
P projection(const L &l, const P &p) {
    double t = dot(p-l.a, l.a-l.b) / norm(l.a-l.b);
    return l.a + t*(l.a-l.b);
}
/* 線対称な点 */
P reflectionL(const L &l, const P &p) {return p + 2.0 * (projection(l, p) - p);}
/* 円 */
struct C {
    P p; double r;
    C() : p(0), r(0) {}
    C(const P &p, double r) : p(p), r(r) { }
};
/* 点の進行方向 (a->b->c) */
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1;       // +1 : 反時計回り
    if (cross(b, c) < 0)   return -1;       // -1 : 時計回り
    if (dot(b, c) < 0)     return +2;       // +2 : 線上(c--a--b)
    if (norm(b) < norm(c)) return -2;       // -2 : 線上(a--b--c)
    return 0;
}
bool intersectCL(const C &c, const L &l){
    return norm(projection(l, c.p) - c.p) - c.r*c.r < EPS;
}
int intersectCS(const C &c, const L &l){ // 交点数を返す
    if(norm(projection(l, c.p) - c.p) - c.r*c.r > EPS) return 0;
    double d1 = abs(c.p - l.a);
    double d2 = abs(c.p - l.b);
    if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;
    if(d1 < c.r - EPS && d2 > c.r + EPS
       || d1 > c.r + EPS && d2 < c.r - EPS ) return 1;
    P h = projection(l, c.p);
    if(dot(l.a - h, l.b - h) < 0) return 2;
    return 0;
}
L crosspointCL(const C &c, const L &l) {
    P hp = projection(l, c.p);
    P h =  hp - c.p;
    double d2 = norm(h);
    P v = sqrt(c.r*c.r - d2)*(l.b-l.a)/abs(l.b-l.a);
    return L(hp - v, hp + v);
}
L crosspointCS(const C &c, const L &l) {
    if(intersectCS(c, l) == 2) return crosspointCL(c, l);
    L ret = crosspointCL(c, l);
    // 交点1つの場合は両方同じ点を返す
    if(dot(l.a - ret.a, l.b - ret.a) < 0) ret.b = ret.a;
    else ret.a = ret.b;
    return ret;
}
L crosspointCC(const C &c1, const C &c2){ // 重なっているとnan
    double d = abs(c1.p - c2.p);
    double x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2.0*d);
    P v = sqrt(c1.r*c1.r - x*x)*(c1.p-c2.p)/abs(c1.p-c2.p)*P(0, 1);
    P h = c1.p + x * (c2.p - c1.p)/abs(c2.p - c1.p);
    return L(h - v, h + v);
}

double r, x1, x2, y01, y2;
double w, h;
G cnr;

//center
void solve1(){
    double ret = 0;
    double rrad, lrad;
    double rr = r, lr = r;
    if(y01 >= r){
	printf("%.8f\n", r*2*PI);
	return;
    }
    if(abs(cnr[0]) >= r){
	lrad = asin(y01 / lr);
	ret += lr * (PI/2 + lrad);
	if(abs(cnr[1]) >= r){
	    rrad = asin(y01 / rr);
	    ret += rr * (PI/2 + rrad);
	}else {
	    rrad = atan(y01 / x2);
	    ret += rr * (PI/2 + rrad);
	    rr -= abs(cnr[1]);
	    ret += rr * (PI/2 - rrad);
	    rr -= h;
	    if(rr > 0){
		ret += rr * PI / 2;
	    }
	}
	printf("%.8f\n", ret);
	return;
    }
    if(abs(cnr[0]) < r && abs(cnr[0]) + h >= r){
	lrad = atan(-y01 / x1);
	ret += lr * (PI/2 + lrad);
	lr -= abs(cnr[0]);
	ret += lr * (PI/2 - lrad);
	if(abs(cnr[1]) >= r){
	    rrad = asin(y01 / rr);
	    ret += rr * (PI/2 + rrad);
	}else {
	    rrad = atan(y01 / x2);
	    ret += rr * (PI/2 + rrad);
	    rr -= abs(cnr[1]);
	    ret += rr * (PI/2 - rrad);
	    rr -= h;
	    if(rr > 0){
		ret += rr * PI / 2;
	    }
	}
	printf("%.8f\n", ret);
	return;
    }
    if(abs(cnr[0]) + h < r){
	lrad = atan(-y01 / x1);
	ret += lr * (PI/2 + lrad);
	lr -= abs(abs(cnr[0]));
	if(abs(cnr[1]) >= r){
	    ret += lr * (PI/2 - lrad);
	    lr -= h;
	    ret += lr * PI / 2;
	    rrad = asin(y01 / rr);
	    ret += rr * (PI/2 + rrad);
	    printf("%.8f\n", ret);
	    return;
	}
	if(abs(cnr[1]) + h >= r){
	    rrad = (x2 == 0)? PI/2: atan(y01 / x2);
	    ret += rr * (PI/2 + rrad);
	    rr -= abs(cnr[1]);
	    ret += rr * (PI/2 - rrad);
	    ret += lr * (PI/2 - lrad);
	    lr -= h;
	    ret += lr * PI / 2;
	    printf("%.8f\n", ret);
	    return;
	}
	rrad = (x2 == 0)? PI/2: atan(y01 / x2);
	ret += rr * (PI/2 + rrad);
	rr -= abs(cnr[1]);
	if(rr + lr <= 2*h + w){
	    ret += lr * (PI/2 - lrad);
	    lr -= h;
	    ret += rr * (PI/2 - rrad);
	    rr -= h;
	    ret += lr * PI / 2;
	    ret += rr * PI / 2;
	    printf("%.8f\n", ret);
	    return;
	}
	if((rr-h)*(rr-h) > w*w + (lr-h)*(lr-h)){
	    ret += rr * (PI/2 - rrad);
	    rr -= h;
	    C c1 = C(cnr[0], lr), c2 = C(cnr[2], rr);
	    L cp = crosspointCC(c1, c2);
	    if(cp.a.imag() < cp.b.imag())
		swap(cp.a, cp.b);
	    double lang = arg(cp.a - cnr[0]);
	    double rang = arg(cp.a - cnr[2]);
	    ret += lr * (PI - lang - lrad);
	    ret += rr * (rang - PI/2);
	    printf("%.8f\n", ret);
	    return;
	}
	if((lr-h)*(lr-h) > w*w + (rr-h)*(rr-h)){
	    ret += lr * (PI/2 - lrad);
	    lr -= h;
	    C c1 = C(cnr[3], lr), c2 = C(cnr[1], rr);
	    L cp = crosspointCC(c1, c2);
	    if(cp.a.imag() < cp.b.imag())
		swap(cp.a, cp.b);
	    double lang = arg(cp.a - cnr[3]);
	    double rang = arg(cp.a - cnr[1]);
	    ret += lr * (PI/2 - lang);
	    ret += rr * (rang - rrad);
	    printf("%.8f\n", ret);
	    return;
	}
	ret += lr * (PI/2 - lrad);
	lr -= h;
	ret += rr * (PI/2 - rrad);
	rr -= h;
	C c1 = C(cnr[3], lr), c2 = C(cnr[2], rr);
	L cp = crosspointCC(c1, c2);
	if(cp.a.imag() < cp.b.imag())
	    swap(cp.a, cp.b);
	double lang = arg(cp.a - cnr[3]);
	double rang = arg(cp.a - cnr[2]);
	ret += lr * (PI/2 - lang);
	ret += rr * (rang - PI/2);
	printf("%.8f\n", ret);
	return;
    }
}

//right
void solve2(){
    double ret = 0;
    double rr = r, lr = r;
    double rrad, lrad;
    if(abs(cnr[0]) >= r){
	printf("%.8f\n", r*2*PI);
	return;
    }
    if(abs(cnr[3]) >= r){
	lrad = acos(x1 / lr);
	ret += lr * (PI*3/2 - lrad);
	if(abs(cnr[1]) >= r){
	    rrad = asin(y01 / rr);
	    ret += rr * (PI/2 + rrad);
	    printf("%.8f\n", ret);
	    return;
	}
	if(abs(cnr[1]) + h >= r){
	    rrad = (x2 == 0)? PI/2: atan(y01 / x2);
	    ret += rr * (PI/2 + rrad);
	    rr -= abs(cnr[1]);
	    ret += rr * (PI/2 - rrad);
	    printf("%.8f\n", ret);
	    return;
	}
    }
    lrad = (x1 == 0)? PI/2: atan(y2 / x1);
    ret += lr * (PI*3/2 - lrad);
    lr -= abs(cnr[3]);
    if(abs(cnr[1]) >= r){
	ret += lr * lrad;
	rrad = asin(y01 / rr);
	ret += rr * (PI/2 + rrad);
//	cerr << "hoge?\n";
	printf("%.8f\n", ret);
	return;
    }
    if(abs(cnr[1]) + h >= r){
	ret += lr * lrad;
	lr -= w;
	if(lr > 0)
	    ret += lr * PI / 2;
	rrad = (x2 == 0)? PI/2: atan(y01 / x2);
	ret += rr * (PI/2 + rrad);
	rr -= abs(cnr[1]);
	ret += rr * (PI/2 - rrad);
	printf("%.8f\n", ret);
	return;
    }
    if(abs(cnr[1]) + h + w >= lr + rr){
	ret += lr * lrad;
	rrad = asin(y01 / rr);
	ret += rr * (PI/2 + rrad);
	rr -= abs(cnr[1]);
	ret += rr * (PI/2 - rrad);
	rr -= h;
	ret += rr * PI / 2;
	printf("%.8f\n", ret);
	return;
    }
    rrad = asin(y01 / rr);
    ret += rr * (PI/2 + rrad);
    rr -= abs(cnr[1]);
    if(rr <= h){
	ret += lr * lrad;
	lr -= w;
	C c1 = C(cnr[2],lr), c2 = C(cnr[1],rr);
	L cp = crosspointCC(c1, c2);
	if(cp.a.imag() < cp.b.imag())
	    swap(cp.a, cp.b);
	double lang = arg(cp.a - cnr[2]);
	double rang = arg(cp.a - cnr[1]);
	ret += lr * abs(lang);
	ret += rr * (rang - rrad);
	cerr << "hogehoge\n";
	printf("%.8f\n", ret);
	return;
    }
    if(lr <= w){
	ret += rr * (PI/2 - rrad);
	rr -= h;
	C c1 = C(cnr[3],lr), c2 = C(cnr[2],rr);
	L cp = crosspointCC(c1, c2);
	if(cp.a.imag() < cp.b.imag())
	    swap(cp.a, cp.b);
	double lang = arg(cp.a - cnr[3]);
	double rang = arg(cp.a - cnr[2]);
	ret += lr * (PI/2 - lang);
	ret += rr * (rang - PI/2);
	printf("%.8f\n", ret);
	return;
    }
    if(lr*lr <= w*w + (rr-h)*(rr-h)){
	ret += rr * (PI/2 - rrad);
	rr -= h;
	C c1 = C(cnr[3],lr), c2 = C(cnr[2],rr);
	L cp = crosspointCC(c1, c2);
	if(cp.a.imag() < cp.b.imag())
	    swap(cp.a, cp.b);
	double lang = arg(cp.a - cnr[3]);
	double rang = arg(cp.a - cnr[2]);
	ret += lr * (PI/2 - lang);
	ret += rr * (rang - PI/2);
	printf("%.8f\n", ret);
	return;
    }
    if(rr*rr <= h*h + (lr-w)*(lr-w)){
	ret += lr * lrad;
	lr -= w;
	C c1 = C(cnr[2],lr), c2 = C(cnr[1],rr);
	L cp = crosspointCC(c1, c2);
	if(cp.a.imag() < cp.b.imag())
	    swap(cp.a, cp.b);
	double lang = arg(cp.a - cnr[2]);
	double rang = arg(cp.a - cnr[1]);
	ret += lr * abs(lang);
	ret += rr * (rang - rrad);
	cerr << "hogehoge\n";
	printf("%.8f\n", ret);
	return;
    }
    C c1 = C(cnr[3],lr), c2 = C(cnr[1],rr);
    L cp = crosspointCC(c1, c2);
    if(cp.a.imag() < cp.b.imag())
	swap(cp.a, cp.b);
    double lang = arg(cp.a - cnr[3]);
    double rang = arg(cp.a - cnr[1]);
    ret += lr * (PI/2 - lang);
    ret += rr * (rang - rrad);
    printf("%.8f\n", ret);
    return;
}

int main(){
    int cnt = 1;
    while(cin >> r >> x1 >> y01 >> x2 >> y2, r||x1||y01||x2||y2){
	cnr.clear();
	if(y2 <= 0){
	    y2 *= -1; y01 *= -1;
	    swap(y01, y2);
	}
	if(x2 <= 0){
	    x2 *= -1; x1 *= -1;
	    swap(x1, x2);
	}
	cnr.pb(P(x1,y01)); cnr.pb(P(x2,y01));
	cnr.pb(P(x2,y2)); cnr.pb(P(x1,y2));
	if(y01 < 0){
	    rep(i,4) cnr[i] = rotate(cnr[i], PI/2);
	    P tmp = cnr[3];
	    rep(i,3) cnr[i+1] = cnr[i];
	    cnr[0] = tmp;
	}
	x1 = cnr[0].real(); y01 = cnr[0].imag();
	x2 = cnr[2].real(); y2 = cnr[2].imag();
	w = x2 - x1; h = y2 - y01;
	cerr << "Case" << cnt++ << ": ";
	if(x1 < 0) solve1();
	else solve2();
    }
    return 0;
}
