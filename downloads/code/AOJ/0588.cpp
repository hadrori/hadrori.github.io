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

int calc(int a, int b, char c){
    if(c=='+') return a+b;
    if(c=='-') return a-b;
    if(c=='*') return a*b;
    if(c=='/') return a/b;
}

int main(){
    bool isnum = true;
    char op = '+';
    int arg = 0;
    while(1){
        if(isnum){
            int in;
            cin >> in;
            arg = calc(arg,in,op);
            isnum = false;
        }else{
            cin >> op;
            if(op=='=') break;
            isnum = true;
        }
    }
    cout << arg << endl;
}
