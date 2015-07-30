#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
 
using namespace std;
 
#define rep(i,a) for(int i=0;i<a;i++)
typedef long long ll;
 
ll ans, n, cnt;
bool used[15];
ll keisu[15];
bool dame[15];
 
void dfs(int k, ll sum){

    if(k==cnt){
        if(!sum)ans++;
        return;
    }
 
    rep(i,10){
        if(used[i] || (i==0 && dame[k])) continue;
         
        used[i] = true;
        dfs(k+1,sum+i*keisu[k]);
        used[i] = false;
    }
    return;
}
 
int main(){
    while(cin>>n,n){
        vector<string> str(n);
        map<char,int> id;
        cnt = 0;
        ans = 0;
 
        rep(i,15){
            used[i] = false;
            keisu[i] = 0;
            dame[i] = false;
        }
 
        rep(i,n){
            cin >> str[i];
 
            rep(j,str[i].size()){
                if(id.find(str[i][j]) == id.end()){
                    id[str[i][j]] = cnt++;
                }
                if(j == 0 && str[i].length() > 1) dame[id[str[i][j]]] = true;
 
                if(i != n-1) keisu[id[str[i][j]]] += (int)pow(10.0,str[i].size()-j-1);
                else keisu[id[str[i][j]]] -= (int)pow(10.0,str[i].size()-j-1);
                 
            }
        } 
 
        dfs(0,0);
        cout << ans << endl;
    }
}

