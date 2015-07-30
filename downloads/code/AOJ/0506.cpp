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
typedef pair<int,int> pii;

string ntos(int n){
    if(!n) return "0";
    string ret = "";
    while(n){
        ret += (n%10+'0');
        n /= 10;
    }
    reverse(all(ret));
    return ret;
}

int main(){
    int n;
    while(cin>>n,n){
        string str;
        cin >> str;
        while(n--){
            string tmp = str;
            str.clear();
            char t = tmp[0];
            int cnt = 1;
            repi(i,1,tmp.size()){
                if(tmp[i] != t){
                    str += ntos(cnt);
                    str += t;
                    t = tmp[i];
                    cnt = 1;
                }else cnt++;
            }
            str += ntos(cnt);
            str += t;
        }
        cout << str << endl;
    }
}
