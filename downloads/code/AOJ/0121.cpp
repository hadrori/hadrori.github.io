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

int main(){
    map<string,int> dp;
    string str = "01234567";

    dp[str] = 0;
    queue<string> bfs;
    bfs.push(str);
    while(!bfs.empty()){
        bool flag = true;
        str = bfs.front();
        bfs.pop();
        int t;
        rep(i,8) if(str[i] == '0') t = i;
        
        if(t>0 && t!=4){
            string tm = str;
            swap(tm[t],tm[t-1]);
            if(dp.find(tm) == dp.end()){
                bfs.push(tm);
                dp[tm] = dp[str] + 1;
            }
        }
        if(t<7 && t!=3){
            string tm = str;
            swap(tm[t],tm[t+1]);
            if(dp.find(tm) == dp.end()){
                bfs.push(tm);
                dp[tm] = dp[str] + 1;
            }
        }
        if(t>3){
            string tm = str;
            swap(tm[t],tm[t-4]);
            if(dp.find(tm) == dp.end()){
                bfs.push(tm);
                dp[tm] = dp[str] + 1;
            }                        
        }
        if(t<4){
            string tm = str;
            swap(tm[t],tm[t+4]);
            if(dp.find(tm) == dp.end()){
                bfs.push(tm);
                dp[tm] = dp[str] + 1;
            }                        
        }
    }
    
    string pz;
    pz.resize(8);
    while(cin>>pz[0]){
        rep(i,7)cin >> pz[i+1];
        cout << dp[pz] << endl;
    }
}
