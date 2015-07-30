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
#define INF 1e8
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct S{
    double sum;
    vector<pair<double,double> > sec;
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<double,double> > sect;
    rep(i,n){
        double x, y, r;
        cin >> x >> y >> r;
        double slo = x? atan(y/x): PI/2;
        double t = asin(r/sqrt(x*x+y*y));
        double M = min(PI, slo+t), m = max(0, slo-t);
        bool ok = true;
        rep(j,sect.size()){
            if(sect[j].second>=M && sect[j].first<=m){
                ok = false;
                break;
            }
            if(sect[j].second<M && sect[j].first>m){
                sect.erase(sect.begin()+j,sect.begin()+j+1);
            }
        }
        if(ok) sect.pb( mp(m, M));
    }

    sort(all(sect));

    rep(i,sect.size()){
        int right = i;
        repi(j,i+1,sect.size()){
            if(sect[j].first <= sect[right].second){
                right = j;
            }
        }
        if(rihgt != i)sect.erase(sect.begin()+i+1,sect.begin()+right);
    }

    vector<vector<S> > dp(n,vector<S>(k+1));
    rep(i,sect.size()){
        dp[i][0].sum = 0;
        dp[i][0].sec.clear();
    }
    rep(i,k)rep(j,sect.size()){
        
    }

}
