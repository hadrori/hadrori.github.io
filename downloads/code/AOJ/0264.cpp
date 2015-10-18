#include <bits/stdc++.h>
using namespace std;
 
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
int mod;
string s;
 
int ex(int a, int t){
    if(!t) return 1;
    int x = ex(a,t/2);
    x = 1LL*x*x%mod;
    return (t&1)?x*a:x;
}
 
int calc(char op, int x, int y) {
    if(op == '+') return (x+y)%mod;
    if(op == '-') return (x-y+mod)%mod;
    if(op == '*') return 1LL*x*y%mod;
    if(!y) throw -1;
    return 1LL*x*ex(y,mod-2)%mod;
}
inline int number(int l, int r) { return atoi(s.substr(l,r-l).c_str()); }
 
int find_back(int l, int r, string ops) {
    int d = 0;
    for(int p = r-1; p >= l; p--) {
        if(s[p] == ')') d++;
        else if(s[p] == '(') d--;
        if(!d and ops.find(s[p]) != string::npos) return p;
    }
    return -1;
}
 
int expr(int l, int r);
int prim(int l, int r) {
    if(s[l] == '(') return expr(l+1,r-1);
    return number(l,r);
}
 
int term(int l, int r) {
    int p = find_back(l,r,"*/");
    if(p < 0) return prim(l,r);
    return calc(s[p],term(l,p),prim(p+1,r));
}
 
int expr(int l, int r) {
    int p = find_back(l,r,"+-");
    if(p < 0) return term(l,r);
    return calc(s[p],expr(l,p),term(p+1,r));
}
 
void solve() {
    int ans = expr(0,s.size());
    cout << s << " = " << ans << " (mod " << mod << ")" << endl;
}
 
bool input() {
    getline(cin,s);
    if(s == "0:") return 0;
    int p = s.find(':');
    mod = atoi(s.substr(0,p).c_str());
    string t = s.substr(p+1);
    s = "";
    for(char &c: t) if(c != ' ') s.push_back(c);
    return 1;
}
 
int main() {
    while(input()) {
        try {
            solve();
        }
        catch(int e) {
            puts("NG");
        }
    }
    return 0;
}