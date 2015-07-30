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

int n, m;

int solve(){
    int id, t = -1, rank = 0;
    bool dab = false;
    rep(i,n){
        int report = -1, r;
        cin >> r;

        if(!i){
            id = i;
            for(int j = 0; report <= m; j++) report = r * j;
            t = report - r;
            rank = r;
        }else {
            bool ok = false;
            for(int j = 0; report < t; j++){
                report = r * j;
            }
            if(report == t){
                if(r == rank) dab = true;
                else if(r < rank){
                    report += r;
                }
            }
            if(report > m){
                while(report > m){
                    report -= r;
                }
                t = report;
                dab = false;
                rank = r;
                id = i;
            }
        }
    }
    return (dab? n: id + 1);
}

int main(){
    while(cin >> n >> m, n || m){
        cout << solve() << endl;
    }
}
