#include <iostream>
#include <vector>
#include <queue>

#define rep(i, b) for(int i = 0; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;
int t, n;
int sim[121][121];
int main(){
    
    while(cin >> t >> n, t || n){
        int x, y;
        rep(i,100)rep(j,100){
            sim[i][j] = 1;
        }
        vector<pair<int,int> > ob;
        rep(i,n){
            cin >> x >> y;
            ob.pb(mp(x,y));
        }
        cin >> x >> y;
        rep(i,n) sim[60-x+ob[i].first][60-y+ob[i].second] = 0;
        
        int ans = 0;
        queue<pair<pair<int,int>,int> > rt;
        rt.push(mp(mp(60,60),0));
        sim[60][60] = 0;
        while(!rt.empty()){
            ans++;
            int cx = rt.front().first.first;
            int cy = rt.front().first.second;
            int ct = rt.front().second;
            rt.pop();
            
            if(ct < t){
                if(sim[cx+1][cy]) sim[cx+1][cy] = 0, rt.push(mp(mp(cx+1,cy),ct+1));
                if(sim[cx+1][cy+1]) sim[cx+1][cy+1] = 0, rt.push(mp(mp(cx+1,cy+1),ct+1));
                if(sim[cx][cy+1]) sim[cx][cy+1] = 0, rt.push(mp(mp(cx,cy+1),ct+1));
                if(sim[cx-1][cy]) sim[cx-1][cy] = 0, rt.push(mp(mp(cx-1,cy),ct+1));
                if(sim[cx-1][cy-1]) sim[cx-1][cy-1] = 0, rt.push(mp(mp(cx-1,cy-1),ct+1));
                if(sim[cx][cy-1]) sim[cx][cy-1] = 0, rt.push(mp(mp(cx,cy-1),ct+1));
            }
        }
        cout << ans << endl;
    }
}