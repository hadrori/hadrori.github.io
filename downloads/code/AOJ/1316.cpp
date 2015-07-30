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
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int di[8] = {1,1,1,0,-1,-1,-1,0};
int dj[8] = {-1,0,1,1,1,0,-1,-1};

int main(){
    int h, w;
    while(cin>>h>>w, h||w){
        vector<string> data(h);
        rep(i,h) cin >> data[i];
        map<string,int> seq;
        string ans;
        rep(i,h)rep(j,w){
            rep(t,8){
                string str = "";
                int ti = i;
                int tj = j;
                bool f = true;
                while(f || ti!=i || tj!=j){
                    f = false;
                    str+=data[ti][tj];
                    seq[str]++;
                    if(seq[str]>1){
                        if(str.size()>ans.size()) ans = str;
                        else if(str.size() == ans.size() && str<ans) ans = str;
                    }
                    ti = (ti + di[t] + h)%h;
                    tj = (tj + dj[t] + w)%w;
                }
            }
        }
/*
        string ans;
        for(map<string,int>::iterator itr = seq.begin(); itr != seq.end(); itr++){
            if((*itr).second>1){
                string str = (*itr).first;
                if(str.size() > ans.size()) ans = str;
                else if(str.size() == ans.size() && str<ans) ans = str; 
            }
        }
*/
        if(ans.size()<2) cout << 0 << endl;
        else cout << ans << endl;
    }
}
