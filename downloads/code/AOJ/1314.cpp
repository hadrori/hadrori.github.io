#include <bits/stdc++.h>
using namespace std;
 
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
 
const int mod = 1<<15;
 
typedef vector<vector<int>> matrix;
 
ostream &operator<<(ostream& os, const matrix &m) {
    if(!m.size()) return os;
    int h = m.size(), w = m[0].size();
    rep(i,h) rep(j,w) cout << m[i][j] << (j==w-1? '\n': ' ');
    return os;
}
 
matrix expr(int l, int r);
matrix primary(int l, int r);
 
string s;
int id[256];
matrix ms[16];
 
inline int inum(int l, int r) { return (atoi(s.substr(l,r-l).c_str())%mod+mod)%mod; }
inline matrix var(int i) { return ms[id[int(s[i])]]; }
 
int find_back(int l, int r, char c) {
    int m = r-1, d = 0;
    while(m >= l) {
        if(s[m] == '(' or s[m] == '[') d--;
        else if(s[m] == ')' or s[m] == ']') d++;
        else if(!d and s[m] == c) return m;
        m--;
    }
    return -1;
}
 
matrix connect(matrix a, matrix b) {
    matrix c(a.size(), vector<int>(a[0].size()+b[0].size()));
    rep(i,a.size()) rep(j,a[0].size()) c[i][j] = a[i][j];
    rep(i,b.size()) rep(j,b[0].size()) c[i][j+a[0].size()] = b[i][j];
    return c;
}
 
matrix push_back(matrix a, matrix b) {
    int ph = a.size();
    a.resize(ph+b.size(), vector<int>(a[0].size()));
    rep(i,b.size()) rep(j,b[0].size()) a[i+ph][j] = b[i][j];
    return a;
}
 
matrix row(int l, int r) {
    int p = find_back(l,r,' ');
    if(p < 0) return expr(l,r);
    matrix a = row(l,p);
    return connect(a,expr(p+1,r));
}
 
matrix row_seq(int l, int r) {
    int p = find_back(l,r,';');
    if(p < 0) return {row(l,r)};
    return push_back(row_seq(l,p), row(p+1,r));
}
 
matrix mat(int l, int r) { return row_seq(l+1,r-1); }
 
matrix trans(int l, int r) {
    matrix a = primary(l,r-1), b(a[0].size(), vector<int>(a.size()));
    rep(i,a.size()) rep(j,a[0].size()) b[j][i] = a[i][j];
    return b;
}
 
int search_open(int p, char o, char c) {
    int d = 0;
    do {
        if(s[p] == o) d++;
        else if(s[p] == c) d--;
        p--;
    } while(d);
    return p+1;   
}
 
matrix indexed(int l, int r) {
    int p = search_open(r-1,'(',')');
    int q = find_back(p+1,r-1,',');
    matrix a = primary(l,p);
    matrix x = expr(p+1,q), y = expr(q+1,r-1);
    matrix b(x[0].size(), vector<int>(y[0].size()));
    rep(i,b.size()) rep(j,b[0].size()) b[i][j] = a[x[0][i]-1][y[0][j]-1];
    return b;
}
 
int search_close(int p, char o, char c) {
    int d = 0;
    do {
        if(s[p] == o) d++;
        else if(s[p] == c) d--;
        p++;
    } while(d);
    return p;
}
 
matrix primary(int l, int r) {
    if(s[r-1] == '\'') return trans(l,r);
    if(s[r-1] == ')' and ~find_back(l,r-1,',')) return indexed(l,r);
 
    if(isdigit(s[l])) return {{inum(l,r)}};
    else if(isalpha(s[l])) return var(l);
    else if(s[l] == '[') return mat(l,r);
    else if(s[l] == '(') return expr(l+1,r-1);
    return {{}};
}
 
matrix mul(matrix a, const int &x) {
    rep(i,a.size()) rep(j,a[0].size()) a[i][j] = (a[i][j]*x%mod+mod)%mod;
    return a;
}
 
matrix factor(int l, int r) {
    if(s[l] == '-') return mul(factor(l+1,r), -1);
    return primary(l,r);
}
 
matrix mul(const matrix &a, const matrix &b) {
    if(a.size() == 1 and a[0].size() == 1) return mul(b,a[0][0]);
    if(b.size() == 1 and b[0].size() == 1) return mul(a,b[0][0]);
    matrix c(a.size(), vector<int>(b[0].size(), 0));
    rep(i,c.size()) rep(j,c[0].size()) rep(k,a[0].size()) (c[i][j] += a[i][k]*b[k][j]%mod) %= mod;
    return c;
}
 
matrix calc(char op, matrix a, const matrix &b) {
    if(op == '+') rep(i,a.size()) rep(j,a[0].size()) (a[i][j] += b[i][j]) %= mod;
    else if(op == '-') rep(i,a.size()) rep(j,a[0].size()) a[i][j] = (a[i][j]-b[i][j]+mod)%mod;
    else if(op == '*') return mul(a,b);
    return a;
}
 
bool valid_minus(int p, int l, int r) {
    static const string invm = "+-* ;,[(";
    return p > l and invm.find(s[p-1]) == string::npos;
}
 
int search_op(int l, int r, vector<char> ops) {
    int p = r-1, d = 0;
    while(l < r and find(begin(ops), end(ops), s[l]) != end(ops)) l++;
    while(p >= l) {
        if(s[p] == '(' or s[p] == '[') d--;
        else if(s[p] == ')' or s[p] == ']') d++;
        else if(!d and find(begin(ops), end(ops), s[p]) != end(ops) and (s[p] != '-' or valid_minus(p,l,r))) return p;
        p--;
    }
    return -1;
}
 
matrix term(int l, int r) {
    int p = search_op(l,r,{'*'});
    if(~p) return mul(term(l,p),factor(p+1,r));
    return factor(l,r);
}
 
matrix expr(int l, int r) {
    int p = search_op(l,r,{'+','-'});
    if(~p) return calc(s[p], expr(l,p), term(p+1,r));
    return term(l,r);
}
 
void init() {
    memset(id,-1,sizeof(id));
    rep(i,16) ms[i].clear();
}
 
int q;
 
void solve() {
    init();
    rep(i,q) {
        getline(cin, s);
        char v = s[0];
        ms[id[int(v)] = i] = expr(2,s.size()-1);
        cout << ms[i];
    }
    cout << "-----" << endl;
}
 
bool input() {
    cin >> q;
    cin.ignore();
    return q;
}
 
int main() {
    cin.tie(0);
    while(input()) solve();
    return 0;
}