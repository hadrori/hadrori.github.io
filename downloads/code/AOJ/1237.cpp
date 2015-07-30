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

int ston(string s){
    int ret = 0;
    rep(i,s.size()){
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

int main(){
    int t;
    string s;
    while(cin>>t>>s, t||(s!="0")){
        int sum = -1;
        bool rej = false;
        vec part;
        int len = s.size();
        rep(i,1<<(len-1)){
            int tsum = 0;
            string tmp;
            vec tpart;
            rep(j,len-1){            
                if(i&(1<<j)){
                    tmp.pb(s[j]);
                    int tt = ston(tmp);
                    tsum += tt;
                    tpart.pb(tt);
                    tmp.clear();
                }else tmp.pb(s[j]);
            }
            tmp.pb(s[len-1]);
            int tt = ston(tmp);
            tsum += tt;
            tpart.pb(tt);
            if(sum == tsum) rej = true;
            else if(tsum<=t && sum<tsum){
                sum = tsum;
                part = tpart;
                rej = false;
            }
        }
        if(rej) cout << "rejected\n";
        else if(sum==-1) cout << "error\n";
        else{
            cout << sum << ' ';
            rep(i,part.size())cout << part[i] << ((i==part.size()-1)?'\n': ' ');
        }
//        cout << "+++++\n";
    }
}
