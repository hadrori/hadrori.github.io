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
    int hand[5];
    while(~scanf("%d,%d,%d,%d,%d",hand,hand+1,hand+2,hand+3,hand+4)){
	sort(hand,hand+5);
	if(hand[0] == 1 && hand[1] == 2 && hand[2] == 3 && hand[3] == 4 && hand[4] == 5){
	    cout << "straight" << endl;
	    continue;
	}
	rep(i,5)if(hand[i] == 1) hand[i] = 14;
	sort(hand,hand+5);
	bool straight = true;
	rep(i,4)if(hand[i+1] - hand[i] != 1){
	    straight = false;
	    break;
	}
	if(straight){
	    cout << "straight" << endl;
	    continue;
	}
	int cnt = 0;
	int prev = hand[0];
	vi p;
	rep(i,5){
	    if(hand[i] != prev){
		p.pb(cnt);
		cnt = 1;
	    }
	    else cnt++;
	    prev = hand[i];
	}
	p.pb(cnt);
	sort(rall(p));
	if(p[0] == 4){
	    cout << "four card" << endl;
	    continue;
	}
	if(p[0] == 3 && p[1] == 2){
	    cout << "full house" << endl;
	    continue;
	}
	if(p[0] == 3){
	    cout << "three card" << endl;
	    continue;
	}
	if(p[0] == 2 && p[1] == 2){
	    cout << "two pair" << endl;
	    continue;
	}
	if(p[0] == 2){
	    cout << "one pair" << endl;
	    continue;
	}
	cout << "null" << endl;
    }
    return 0;
}
