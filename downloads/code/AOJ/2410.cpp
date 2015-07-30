#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int main(){
    int N;
    cin >> N;
    int exp[16]= {0};
    int pos = -1, maxa = -1;
    rep(i,N){
        rep(j,N){
            char c; cin >> c;
            if(c == '-') exp[i]++;
            else if(c == 'o') exp[i] += 3;
        }
        if(maxa < exp[i]){
            maxa = exp[i];
            pos = i + 1;
        }
    }
    int t = -1;
    rep(i,1000){
        cout << pos << endl;
        cin >> t;
    }
    return 0;
}
