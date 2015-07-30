#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

#define EPS 1e-10

int main(){
    int N, M = 256;
    while(cin>>N,N){
        vec I(N);
        rep(i,N)cin>>I[i];
        int S, A, C;
        double h = 10000000;
        rep(s,16)rep(a,16)rep(c,16){
            int R = s;
            int x[256] = {0};
            rep(i,N){
                R = (a*R+c) % M;
                int O = (I[i]+R) % M;
                x[O]++;
            }
            double H = 0;
            rep(i,M){
                if(!x[i]) continue;
                double t = 1.0*x[i]/N;
                H -= (t*log(t));
            }
            if(H+EPS < h){
                h = H;
                S = s;
                A = a;
                C = c;
            }
        }
        cout << S << ' ' << A << ' ' << C << endl;
    }
}
