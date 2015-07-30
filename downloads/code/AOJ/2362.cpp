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
#define lb lower_bound
#define ub upper_bound
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

int main(){
    string str;
    cin >> str;
    vector<vector<string> > words;
    string prev = "", cur = "";
    int c = 0, family = 0;
    words.pb(vector<string>());
    while(c < str.size()){
	if(str[c] == 'e'){
	    cur = "egg";
	    c += 3;
	}else{
	    cur = "chicken";
	    c += 7;
	}
	if(cur == prev){
	    words.pb(vector<string>());
	    family++;
	}
	words[family].pb(cur);
	prev = cur;
    }
    int old = 0;
    string ans;
    rep(i,words.size())
	if(old < words[i].size()){
	    ans = words[i][words[i].size()-1];
	    old = words[i].size();
	}
    cout << ans << endl;
    return 0;
}
