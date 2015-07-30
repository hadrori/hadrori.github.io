#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
const string cs = "01+-*()";
const string ops = "+-*";
string s, eq;
int K, pos;
int use[8];

inline bool valid(int &a){ return a >= 0 and a <= 1023;}
bool valid(char c, char d){
    if(count(all(ops),c) and count(all(ops),d)) return 0;
    if(c == '(' and d == ')' or c == ')' and d == '(') return 0;
    if(c == '(' and count(all(ops), d)) return 0;
    if(d == '(' and isdigit(c)) return 0;
    if(c == ')' and isdigit(d)) return 0;
    if(d == ')' and count(all(ops), c)) return 0;
    return 1;
}
bool valid(){
    int d = 0;
    if(count(all(ops),eq[0]) or eq[0] == ')' or
       count(all(ops),eq[eq.size()-1]) or eq[eq.size()-1] == '(')
        return 0;
    rep(i,eq.size()){
        if(eq[i] == '(') d++;
        else if(eq[i] == ')') d--;
        if(d < 0) return 0;
        if(i and !valid(eq[i-1], eq[i])) return 0;
    }
    if(d) return 0;
    return 1;
}

int pack(int m){
    int d = 0, l = m-1, r = m+1, ret = 0;
    if(isdigit(eq[l]))
        while(l >= 0 and isdigit(eq[l])) l--;
    else{
        l--; d--;
        while(d){
            if(eq[l] == ')') d--;
            else if(eq[l] == '(') d++;
            l--;
        }
    }
    if(isdigit(eq[r]))
        while(r < eq.size() and isdigit(eq[r])) r++;
    else{
        r++; d++;
        while(d){
            if(eq[r] == ')') d--;
            else if(eq[r] == '(') d++;
            r++;
        }
    }
    if(l < 0 or eq[l] != '(' or r >= eq.size() or eq[r] != ')'){
        eq.insert(l+1,"(");
        eq.insert(r+1,")");
        return 1;
    }
    return 0;
}

void normalize(){
    rep(i,eq.size())
        if(eq[i] == '*')
            i += pack(i);
    rep(i,eq.size())
        if(eq[i] == '+' or eq[i] == '-')
            i += pack(i);
}

int number(){
    int ret = 0;
    while(pos < eq.size() and isdigit(eq[pos])){
        ret = (ret << 1) + eq[pos++]-'0';
        if(ret > 1023) throw -1;
    }
    if(!valid(ret)) throw -1;
    return ret;
}

int expr(){
    if(eq[pos] != '(') return number();
    pos++;
    int a = expr();
    if(!valid(a)) throw -1;
    char op = eq[pos++];
    if(ops.find(op) == string::npos) throw -1;
    int b = expr();
    pos++;
    if(!valid(b)) throw -1;
    int ret = 0;
    if(op == '*') ret = a*b;
    else if(op == '+') ret = a+b;
    else if(op == '-') ret = a-b;
    if(!valid(ret)) throw -1;
    return ret;
}

int calc(){
    eq = s;
    int idx = 0;
    rep(i,s.size()) if(eq[i] == '.')
        eq[i] = cs[use[idx++]];
    pos = 0;
    if(!valid()) throw -1;
    normalize();
    int ret = expr();
    //    cerr << eq << " = " << ret << endl;
    if(!valid(ret)) throw -1;
    return ret;
}

int rec(int cur){
    int ret = -1;
    if(cur == K){
        try{
            ret = calc();
        } catch(int e){
            ret = e;
        }
        return ret;
    }
    rep(i,7){
        use[cur] = i;
        ret = max(ret, rec(cur+1));
    }
    return ret;
}

int solve(){
    K = 0;
    rep(i,s.size()) if(s[i] == '.') K++;
    return rec(0);
}


signed main(){
    cin >> s;
    cout << solve() << endl;
    return 0;
}


