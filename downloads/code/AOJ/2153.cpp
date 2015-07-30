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
#define MAX 51

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int di[] = {0,1,0,-1};
int dj[] = {1,0,-1,0};

struct S{
    int ri, rj, li, lj, t;
};

int main(){
    int w, h;
    while(cin>>w>>h,w||h){
        vector<string> roomr(h),rooml(h);
        rep(i,h) cin >> rooml[i] >> roomr[i];
        bool visited[MAX][MAX][MAX][MAX] = {false};
        queue<S> bfs;
        S s;
        s.t = 0;
        rep(i,h)rep(j,w){
            if(roomr[i][j]=='R'){
                s.ri = i;
                s.rj = j;
            }
            if(rooml[i][j]=='L'){
                s.li = i;
                s.lj = j;
            }
        }
        visited[s.li][s.lj][s.ri][s.rj] = true;
        bfs.push(s);
        bool ok = false;
        while(!bfs.empty()){
            S st = bfs.front();
            bfs.pop();
            int tri = st.ri, trj = st.rj, tli = st.li, tlj = st.lj;
            int turn = st.t;
//            cout << tli << ' ' << tlj << ' ' << tri << ' ' << trj << endl;;
            if((rooml[tli][tlj]=='%' && roomr[tri][trj]!='%') || 
               (rooml[tli][tlj]!='%' && roomr[tri][trj]=='%')) continue;
            if( rooml[tli][tlj]=='%' && roomr[tri][trj]=='%'){
                ok = true;
                break;
            }
            rep(d,4){
                S ns;
                ns.ri = tri; ns.rj = trj; ns.li = tli; ns.lj = tlj;
                if(tli+di[d]>=0 && tli+di[d]<h) ns.li = tli+di[d];
                if(tlj+dj[d]>=0 && tlj+dj[d]<w) ns.lj = tlj+dj[d];
                if(rooml[ns.li][ns.lj] == '#'){
                    ns.li = tli;
                    ns.lj = tlj;
                }
                if(tri+di[d]>=0 && tri+di[d]<h) ns.ri = tri+di[d];
                if(trj-dj[d]>=0 && trj-dj[d]<w) ns.rj = trj-dj[d];
                if(roomr[ns.ri][ns.rj] == '#'){
                    ns.ri = tri;
                    ns.rj = trj;
                }
                if(!visited[ns.li][ns.lj][ns.ri][ns.rj]){
                    visited[ns.li][ns.lj][ns.ri][ns.rj] = true;
                    ns.t = turn+1;
                    bfs.push(ns);
                }
            }
        }
        cout << (ok? "Yes\n": "No\n");
    }
}
