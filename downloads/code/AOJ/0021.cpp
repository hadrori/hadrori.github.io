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
typedef complex<double> P;
typedef vector<P> G;

int main(){
    int n;
    cin >> n;
    while(n--){
        G p(4);
        rep(i,4) cin >> p[i].real() >> p[i].imag();
        if(p[0].real() == p[1].real()){
            cout << (p[2].real() == p[3].real()? "YES": "NO") << endl;
        }else if(p[2].real() == p[3].real()){
            cout << "NO\n";
        }else{
            cout << ((p[0].imag()-p[1].imag())/(p[0].real()-p[1].real()) == 
                     (p[2].imag()-p[3].imag())/(p[2].real()-p[3].real())? "YES": "NO") << endl;
        }
    }
}
