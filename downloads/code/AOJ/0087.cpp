#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) rep(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

string op = "+-*/";
int main(){
    string s;
    while(getline(cin,s)){
        stringstream ss;
        ss << s;
        stack<double> st;
        while(ss >> s){
            int t = op.find(s);
            if(t >= 0){
                double b = st.top(); st.pop();
                double a = st.top(); st.pop();
                switch (t){
                case 0: st.push(a+b); break;
                case 1: st.push(a-b); break;
                case 2: st.push(a*b); break;
                case 3: st.push(a/b); break;
                }
            }
            else st.push(atoi(s.c_str()));
        }
        printf("%.8f\n",st.top());
    }
    return 0;
}
