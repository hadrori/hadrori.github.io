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

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int ans[1<<15] = {0};
    for(int i = 0; i*i<(1<<15); i++){
        for(int j = 0; i*i+j*j<(1<<15) && j<=i; j++){
            for(int k = 0; i*i+j*j+k*k<(1<<15) && k<=j; k++){
                for(int l = 0; i*i+j*j+k*k+l*l<(1<<15) && l<=k; l++){
                    ans[i*i+j*j+k*k+l*l]++;
                }
            }
        }
    }
    int n;
    while(cin>>n,n){
        cout << ans[n] << endl;
    }
}

