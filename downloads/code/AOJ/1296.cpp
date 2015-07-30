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
        vector<pair<string, string> > ab(n);
        rep(i,n) cin >> ab[i].first >> ab[i].second;
        string g, d;
        cin >> g >> d;
        queue<pair<string,int> > que;
        int ans = -1;
        que.push(mp(g,0));
        while(!que.empty()){
            string str = que.front().first;
            int cnt = que.front().second;
            que.pop();

            if(str == d){
                ans = cnt;
                break;
            }

            rep(i,n){
                string tmp = str;
                int cur = 0;
                while(cur < tmp.size()){
                    cur = tmp.find(ab[i].first,cur);
                    if(cur == string::npos) break;
                    tmp.replace(cur,ab[i].first.size(),ab[i].second);
                    cur += ab[i].second.size();
                }
                if(tmp != str && tmp.size() <= d.size()){
                    que.push(mp(tmp,cnt+1));
                }
            }
        }
        cout << ans << endl;
    }
}


