#include <bits/stdc++.h>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> pii;

vector<pii> inter;
map<string,int> id;
int n, m;
string op = "+-/*";
bool memo[128][256];

int main(){
    cin >> m;
    inter.resize(m);
    rep(i,m){
        string str;
        cin >> str;
        id[str] = i;
        cin >> inter[i].fst >> inter[i].snd;
    }
    cin >> n;
    stack<int> st;
    rep(i,n){
        string s; cin >> s;
        if(op.find(s) == string::npos){
            map<string,int>::iterator itr = id.find(s);
            if(itr == id.end()) memo[i][atoi(s.c_str())] = true;
            else {
                int pos = (*itr).snd;
                repi(j,inter[pos].fst,inter[pos].snd+1) memo[i][j] = true;
            }
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if(s == "+")
                rep(j,256)rep(k,256)
                    memo[i][(j+k)%256] |= memo[a][j] & memo[b][k];
            else if(s == "-")
                rep(j,256)rep(k,256)
                    memo[i][(j-k+256)%256] |= memo[a][j] & memo[b][k];
            else if(s == "*")
                rep(j,256)rep(k,256)
                    memo[i][j*k%256] |= memo[a][j] & memo[b][k];
            else if(s == "/"){
                if(memo[b][0]) {
                    cout << "error\n";
                    return 0;
                }
                rep(j,256)repi(k,1,256)
                    memo[i][j/k%256] |= memo[a][j] & memo[b][k];
            }

        }
        st.push(i);
    }
    cout << "correct\n";
    return 0;
}
