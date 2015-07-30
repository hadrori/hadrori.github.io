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

int main(){
    int n;
    while(cin>>n,n){
        string group1;
        map<string,int> id;
        vector<vector<string> > group(n);
        rep(i,n){
            string str;
            cin >> str;
            int cur = 0;
            string gr = "";
            while(str[cur] != ':') gr += str[cur++];
            id[gr] = i;
            while(str[cur++] != '.'){
                string me = "";
                while(str[cur] != ',' && str[cur] != '.') me += str[cur++];
                group[i].pb(me);
            }
        }
        set<string> ans;
        queue<int> que;
        vector<bool> used(n,false);
        que.push(0);
        used[0] = true;
        while(!que.empty()){
            int tid = que.front(); que.pop();
            rep(i,group[tid].size()){
                map<string,int>::iterator it;
                if((it = id.find(group[tid][i])) != id.end()){
                    if(!used[(*it).second]){
                        que.push((*it).second);
                        used[(*it).second] = true;
                    }
                }else ans.insert(group[tid][i]);
            }
        }
        cout << ans.size() << endl;
    }
}


