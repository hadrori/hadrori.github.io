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

string str;

bool isSym(int l, int r){
    return ((str[l] == '(' && str[r] == ')') ||
	    (str[l] == ')' && str[r] == '(') ||
	    (str[l] == '{' && str[r] == '}') ||
	    (str[l] == '}' && str[r] == '{') ||
	    (str[l] == '[' && str[r] == ']') ||
	    (str[l] == ']' && str[r] == '['));
}

int rec(int l, int r){
    int ret = 0;
    while(str[l] != 'i'){
	int cur = r;
	while(str[cur] != 'i'){
	    if(isSym(l,cur))
		ret = max(ret, rec(l+1,cur-1) + 2);
	    cur--;
	}
	l++;
    }
    return ret;
}

int main(){
    cin >> str;
    cout << rec(0,str.size()-1) + 3 << endl;
    return 0;
}
