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

int main(){
    string str;
    while(cin>>str,str!="#"){
        int ans = 1e8;
        rep(i,2){
            bool foot = (i==0); //0:pre=right 
            int L = foot? str[0]-'0'-1: 0;
            int R = foot? 2: str[0]-'0'-1;            
            int cnt = 0;
            repi(j,1,str.size()){
                if(foot){
                    if((str[j]-'0'-1)%3 < L%3){
                        cnt++;
                        L = str[j]-'0'-1;
                    }else{
                        R = str[j]-'0'-1;
                        foot = false;
                    }
                }else{
                    if((str[j]-'0'-1)%3 > R%3){
                        cnt++;
                        R = str[j]-'0'-1;
                    }else{
                        L = str[j]-'0'-1;
                        foot = true;
                    }
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
}
