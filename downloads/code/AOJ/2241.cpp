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


int main(){
    int n, u, v, m;
    map<int, pii> rab, cat;
    int winner = -1; // 0: DRAW, 1: USAGI, 2: NEKO
    int rabf = 0, catf = 0; // count finished
    cin >> n >> u >> v >> m;

    rep(i,n)rep(j,n){
        int t;
        cin >> t;
        rab[t] = mp(j,i);
    }
    rep(i,n)rep(j,n){
        int t;
        cin >> t;
        cat[t] = mp(j,i);
    }
    if(n>1){
        vi rabyc(n,0), rabxc(n,0); // count y, x  
        vi rablowr(2*n,0), rablowl(2*n,0); // count lower right dir (y = x + b), lower left dir (y = -x + b)
        
        vi catyc(n,0), catxc(n,0); // count y, x  
        vi catlowr(2*n,0), catlowl(2*n,0); // count lower right dir (y = x + b), lower left dir (y = -x + b)
        
        rep(i,m){
            int num;
            cin >> num;
            if(winner==-1){
                bool clearedR = false, clearedC = false;
                if(rab.find(num) != rab.end()){
                    pii p = rab[num];
                    int x = p.first, y = p.second;
                    rabyc[y]++; rabxc[x]++;
                    rablowr[y-x+n-1]++; rablowl[y+x]++;
                    if(rabyc[y] == n) rabf++;
                    if(rabxc[x] == n) rabf++;
                    if(rablowr[y-x+n-1] == n) rabf++;
                    if(rablowl[y+x] == n) rabf++;
                    if(rabf >= u) clearedR = true;
                }
                if(cat.find(num) != cat.end()){
                    pii p = cat[num];
                    int x = p.first, y = p.second;
                    catyc[y]++; catxc[x]++;
                    catlowr[y-x+n-1]++; catlowl[y+x]++;
                    if(catyc[y] == n) catf++;
                    if(catxc[x] == n) catf++;
                    if(catlowr[y-x+n-1] == n) catf++;
                    if(catlowl[y+x] == n) catf++;
                    if(catf >= v) clearedC = true;
                }
                if(clearedR && clearedC) winner = 0;
                else if(clearedR) winner = 1;
                else if(clearedC) winner = 2;
            }
        }
    }else {
        rep(i,m){
            int num;
            cin >> num;
            int rabc = 0, catc = 0;
            if(winner == -1){
                if(rab.find(num) != rab.end()) rabc++;
                if(cat.find(num) != cat.end()) catc++;
                if(rabc == u && catc == v) winner = 0;
                else if(rabc == u) winner = 1;
                else if(catc == v) winner = 2;
            }
        }
    }
    cout << (winner==1? "USAGI": winner==2? "NEKO": "DRAW") << endl;

}
