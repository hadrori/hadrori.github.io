#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
string s;
int n, cur;

int number(){
    int ret = 0;
    while(isdigit(s[cur]))
        ret = ret*10+s[cur++]-'0';
    return ret;
}

int seq(int sum){
    if(cur == (int)s.size()) return 0;
    if(s[cur] == '('){ cur++; return seq(sum);}
    if(s[cur] == ')'){ cur++; return 0;}
    if(isalpha(s[cur])) {
        if(sum == n) throw s[cur];
        cur++;
        return 1+seq(sum+1);
    }
    int m = number(), l;
    int head = cur;
    if(isalpha(s[cur])) { l = 1; cur++;}
    else l = seq(sum);
    if(l*m+sum > n) {
        cur = head;
        n = (n-sum)%l;
        seq(0);
    }
    return l*m+seq(sum+l*m);
}

char solve(){
    cur = 0;
    try{ seq(0);}
    catch(char e){ return e;}
    return '0';
}

int main(){
    while(cin >> s >> n, s!="0") cout << solve() << endl;
    return 0;
}


