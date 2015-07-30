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

int w, h;

struct St{
    set<char> S;
    vector<string> scans;
    St(set<char> S, vector<string> scans):S(S),scans(scans){}
};

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> h >> w;
        vector<string> tscans(h);
        rep(i,h) cin >> tscans[i];

        set<char> tS;
        rep(i,h)rep(j,w){
            if(tscans[i][j] != '.') tS.insert(tscans[i][j]);
        }

        stack<St> dfs;
        dfs.push(St(tS,tscans));
        bool ok = false;
        while(!dfs.empty()){
            St s = dfs.top();
            dfs.pop();
            if(s.S.size()==0){
                ok = true;
                break;
            }
            repit(itr,s.S){
                set<char> ttS = s.S;
                char ch = *ttS.find(*itr);
                int mi=INF, mj=INF, Mi=-1, Mj=-1;
                rep(i,h)rep(j,w){
                    if(s.scans[i][j] == ch){
                        mi = min(mi, i);
                        mj = min(mj, j);
                        Mi = max(Mi, i);
                        Mj = max(Mj, j);
                    }
                }
                vector<string> tmp = s.scans;
//                cout << mi << ' ' << mj << ' ' << Mi << ' ' << Mj << endl;

                repi(i,mi,Mi+1){
                    repi(j,mj,Mj+1){
                        if(s.scans[i][j] != '?' && s.scans[i][j] != ch){
                            goto fail;
                        }
                    }

                }

//                rep(i,h) rep(j,w) cout << s.scans[i][j] << ((j==w-1)? '\n': ' ');
                rep(i,h)rep(j,w){
                    if(tmp[i][j] == ch) tmp[i][j] = '?';
                }
                ttS.erase(ttS.find(ch));
                dfs.push(St(ttS,tmp));
            fail:;
            }
        }
        cout << (ok? "SAFE\n": "SUSPICIOUS\n");
    }
}
