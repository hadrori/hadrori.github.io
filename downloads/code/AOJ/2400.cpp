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

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define ps push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

typedef long long ll;

using namespace std;

int t, p, r;
int main(){
    while(cin >> t >> p >> r, t || p || r){
        vector<pair<pair<int,int>,int> > team(t);
        vector<vector<int> > teamwa(t);
        rep(i,t){
            team[i] = mp(mp(r,0),i);
            teamwa[i] = vector<int>(p);
        }
        rep(i,r){
            int tid, pid, time;
            string judge;
            cin >> tid >> pid >> time >> judge;
            if(judge == "WRONG"){
                teamwa[tid-1][pid-1]++;
            }else{
                team[tid-1].first.first--;
                team[tid-1].first.second += teamwa[tid-1][pid-1] * 1200 + time;
            }
        }
        sort(team.begin(),team.end());
        rep(i,t){
            cout << team[i].second + 1<< ' ' << r - team[i].first.first << ' ' << team[i].first.second << endl;
        }
    }
    
}