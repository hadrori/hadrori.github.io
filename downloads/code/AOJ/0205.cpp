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

typedef long long ll;

using namespace std;

int main(){
  int a[5];
  while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4], a[0]){
    int ja[4] = {0};
    rep(i,5) ja[a[i]]++;
    int wi = 0, lo = 0;
    if(ja[1] >= 1 && ja[2] >= 1 && !ja[3]) wi = 1, lo = 2;
    else if(ja[2] >= 1 && ja[3] >= 1 && !ja[1]) wi = 2, lo = 3;
    else if(ja[3] >= 1 && ja[1] >= 1 && !ja[2]) wi = 3, lo = 1;
    rep(i,5){
      if(a[i] == wi) cout << 1 << endl;
      else if(a[i] == lo) cout << 2 << endl;
      else cout << 3 << endl;
    }
  }
}
