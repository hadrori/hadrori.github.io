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

double len;
G bld;
double w, h;

void solve(){
    if(bld[0].real() >= 0){
	if(abs(bld[0]) >= len){
	    printf("%.6f\n", len*2*PI);
	    return;
	}
	if(abs(bld[3]) >= len){
	    double ret = 0;
	    double rad = acos(bld[0].real()/len);
	    ret += len * (PI*3/2 - rad);
	    if(abs(bld[1]) >= len){
		rad = asin(bld[0].imag()/len);
		ret += len * (PI/2 + rad);
	    }else{
		rad = (bld[1].real() == 0)? PI/2: atan(bld[1].imag()/bld[1].real());
		ret += len * (PI/2 + rad);
		double rlen = len - abs(bld[1]);
		ret += len * (PI/2 - rad);
	    }
	    printf("%.6f\n", ret);
	    return;
	}
	else {
	    double ret = 0;
	    double rad = (bld[3].real()==0)? PI/2: atan(bld[3].imag()/bld[3].real());
	    ret += len * (PI*3/2 - rad);
	    if(abs(bld[1]) >= len){
		double llen = len - abs(bld[3]);
		ret += llen * rad;
		llen -= w;
		if(llen > 0) ret += llen * PI / 2;
		rad = asin(bld[1].imag()/len);
		ret += len * (PI/2 + rad);
		printf("%.6f\n", ret);
		return;
	    }
	    else {
		double rrad = atan(bld[1].imag()/bld[1].real());
		ret += len * (PI/2 + rrad);
		double llen = len - abs(bld[3]);
		double rlen = len - abs(bld[1]);
		if(llen + rlen <= w + h ){
		    ret += llen * rad;
		    ret += rlen * (PI/2 - rrad);
		    llen -= w;
		    rlen -= h;
		    if(llen > 0)
			ret += llen * PI / 2;
		    if(rlen > 0)
			ret += rlen * PI / 2;
		    printf("%.6f\n", ret);
		    return;
		}
		else {
		    if(llen > w && rlen > h){
			if(llen*llen > w*w + (rlen-h)*(rlen-h) &&
			   rlen*rlen > h*h + (llen-w)*(llen-w)){
			    C c1 = C(bld[3],llen), c2 = C(bld[1], rlen);
			    L cp = crosspointCC(c1, c2);
			    if(cp.a.imag() < cp.b.imag())
				swap(cp.a,cp.b);
			    double ang1 = arg(cp.a-bld[3]);
			    double ang2 = arg(cp.a-bld[1]);
			    ret += llen * (rad - ang1);
			    ret += rlen * (ang2 - rrad);
			}else if(llen*llen <= w*w + (rlen-h)*(rlen-h)){
			    ret += rlen * (PI/2 - rrad);
			    rlen -= h;
			    C c1 = C(bld[3],llen), c2 = C(bld[2], rlen);
			    L cp = crosspointCC(c1, c2);
			    if(cp.a.imag() < cp.b.imag())
				swap(cp.a,cp.b);
			    double ang1 = arg(cp.a-bld[3]);
			    double ang2 = arg(cp.a-bld[2]);
			    ret += llen * (rad - ang1);
			    ret += rlen * (ang2 - PI/2);
			    /*
			    */
			}else if(rlen*rlen <= h*h + (llen-h)*(llen-h)){
			    ret += llen * rad;
			    llen -= w;
			    C c1 = C(bld[2],llen), c2 = C(bld[1], rlen);
			    L cp = crosspointCC(c1, c2);
			    if(cp.a.real() < cp.b.real())
				swap(cp.a,cp.b);
			    double ang1 = arg(cp.a-bld[2]);
			    double ang2 = arg(cp.a-bld[1]);
			    ret += llen * (-ang1);
			    ret += rlen * (ang2 - rrad);

			}
		    }else if(llen > w){
			ret += llen * rad;
			llen -= w;
			if(llen + rlen <= h){
			    ret += llen * PI / 2;
			    ret += rlen * (PI/2 - rrad);
			}else{
			    C c1 = C(bld[2],llen), c2 = C(bld[1],rlen);
			    L cp = crosspointCC(c1,c2);
			    if(cp.a.real() < cp.b.real())
				swap(cp.a,cp.b);
			    double ang1 = -arg(cp.a-bld[2]);
			    double ang2 = arg(cp.a-bld[1]);
			    ret += llen * ang1;
			    ret += rlen * (ang2 - rrad);
			}
		    }else if(rlen > h){
			ret += rlen * (PI/2 - rrad);
			rlen -= h;
			if(llen + rlen <= w){
			    ret += llen * rad;
			    ret += rlen * PI / 2;
			}else{
			    C c1 = C(bld[3],llen), c2 = C(bld[2],rlen);
			    L cp = crosspointCC(c1, c2);
			    if(cp.a.imag() < cp.b.imag())
				swap(cp.a,cp.b);
			    double ang1 = arg(cp.a-bld[3]);
			    double ang2 = arg(cp.a-bld[2]);
			    ret += llen * (rad - ang1);
			    ret += rlen * (ang2 - PI/2);
			}
		    }
		}
		printf("%.6f\n", ret);
		return;
	    }
	}
    }
    else{
	if(bld[0].imag() >= len){
	    printf("%.6f\n", len*2*PI);
	    return;
	}
	if(abs(bld[0]) >= len){
	    double ret = 0;
	    double rad = asin(bld[0].imag()/len);
	    ret += len * (PI/2 + rad);
	    if(abs(bld[1]) >= len){
		rad = asin(bld[1].imag()/len);
		ret += len * (PI/2 + rad);
		printf("%.6f\n", ret);
		return;
	    }
	    rad = (bld[1].real()==0)? PI/2: atan(bld[1].imag()/bld[1].real());
	    ret += len * (PI/2 + rad);
	    double rlen = len - abs(bld[1]);
	    ret += rlen * PI / 2;
	    rlen -= h;
	    if(rlen > 0)
		ret += rlen * PI / 2;
	    printf("%.6f\n", ret);
	    return;
	}
	else{
	    double ret = 0;
	    double lrad = (bld[0].real()==0)? PI/2: atan(-bld[0].imag()/bld[0].real());
	    ret += len * (PI/2 + lrad);
	    double llen = len - abs(bld[0]);
	    /*
	    ret += llen * (PI/2 - lrad);
	    llen -= h;
	    */
	    if(abs(bld[1]) > len){
		ret += llen * (PI/2 - lrad);
		llen -= h;
		double rrad = asin(bld[1].imag()/len);
		ret += len * (PI/2 + rrad);
		if(llen > 0)
		    ret += llen * PI / 2;
		printf("%.6f\n", ret);
		return;
	    }
	    else{
		double rrad = atan(bld[1].imag()/bld[1].real());
		ret += len * (PI/2 + rrad);
		double rlen = len - abs(bld[1]);

		if(llen - h + rlen - h <= w){
		    ret += llen * (PI/2 - lrad);
		    llen -= h;
		    ret += rlen * (PI/2 - rrad);
		    rlen -= h;
		    if(llen > 0)
			ret += llen * PI / 2;
		    if(rlen > 0)
			ret += rlen * PI / 2;
		    printf("%.6f\n", ret);
		    return;		    
		}else{
		    if((llen-h)*(llen-h) > w*w + (rlen-h)*(rlen-h)){
			ret += llen * (PI/2 - lrad);
			llen -= h;
			C c1 = C(bld[3],llen), c2 = C(bld[1],rlen);
			L cp = crosspointCC(c1,c2);
			if(cp.a.imag() < cp.b.imag())
			    swap(cp.a,cp.b);
			double ang1 = arg(cp.a - bld[3]);
			double ang2 = arg(cp.a - bld[1]);
			ret += llen * (PI/2 - ang1);
			ret += rlen * (ang2 - rrad);
		    }else if((rlen-h)*(rlen-h) > w*w + (llen-h)*(llen-h)){
			ret += rlen * (PI/2 - rrad);
			rlen -= h;
			C c1 = C(bld[0],llen), c2 = C(bld[2],rlen);
			L cp = crosspointCC(c1,c2);
			if(cp.a.imag() < cp.b.imag())
			    swap(cp.a,cp.b);
			double ang1 = arg(cp.a - bld[0]);
			double ang2 = arg(cp.a - bld[2]);
			ret += llen * (PI - ang1 - lrad);
			ret += rlen * (ang2 - PI/2);
		    }else{
			ret += llen * (PI/2 - lrad);
			llen -= h;
			ret += rlen * (PI/2 - rrad);
			rlen -= h;
			C c1 = C(bld[3],llen), c2 = C(bld[2],rlen);
			L cp = crosspointCC(c1,c2);
			if(cp.a.imag() < cp.b.imag())
			    swap(cp.a,cp.b);
			double ang1 = arg(cp.a - bld[3]);
			double ang2 = arg(cp.a - bld[2]);
			ret += llen * (PI/2 - ang1);
			ret += rlen * (ang2 - PI/2);
		    }
		    printf("%.6f\n", ret);
		    return;
		}
	    }
	}
    }
    return;
}

int main(){
    double x1, y1, x2, y2;
    int cnt = 1;
    while(cin >> len >> x1 >> y1 >> x2 >> y2, len){
	bld.clear();
	/*
	  前処理
	  全部y>0になるように移動
	  checked
	 */
	if(y2 <= 0){
	    y2 *= -1; y1 *= -1;
	    swap(y1,y2);
	}
	if(x2 <= 0){
	    x2 *= -1; x1 *= -1;
	    swap(x1,x2);
	}
	bld.pb(P(x1,y1)); bld.pb(P(x2,y1));
	bld.pb(P(x2,y2)); bld.pb(P(x1,y2));
	if(y1 < 0){
	    rep(i,4) bld[i] = rotate(bld[i], PI/2);
	    P tmp = bld[3];
	    rep(i,3) bld[i+1] = bld[i];
	    bld[0] = tmp;
	}
	w = bld[1].real() - bld[0].real();
	h = bld[2].imag() - bld[1].imag();
//	rep(i,4) cerr << bld[i] << endl;
//	cerr << "Case" << cnt++ << ": ";
	solve();
    }
    return 0;
}
