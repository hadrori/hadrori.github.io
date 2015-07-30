#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

#define int long long
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define INF 1e9

using namespace std;

int N;
string a[1024];

int input(){
    cin >> N;
    rep(i,N) cin >> a[i];
    return N;
}

string solve(){
    int lower = -INF * 2;
    int upper = INF * 2;
    string prev = "2000000000";
    rep(i,N){
        if(a[i] == "x"){
            if(prev == "x") return "none";
            if((i + 1) % 2) {
                upper = min(upper, (int)atoi(prev.c_str()));
                if(i < N - 1) upper = min(upper, (int)atoi(a[i+1].c_str()));
            }
            else{
                lower = max(lower, (int)atoi(prev.c_str()));
                if(i < N - 1) lower = max(lower, (int)atoi(a[i+1].c_str()));
            }
        }
        else if((i + 1) % 2 && prev != "x" && atoi(prev.c_str()) <= atoi(a[i].c_str())) return "none";
        else if((i + 1) % 2 == 0 && prev != "x" && atoi(prev.c_str()) >= atoi(a[i].c_str())) return "none";
        prev = a[i];
        if(upper - lower < 2){
            return "none";
        }
    }
    if(upper - lower > 2) return "ambiguous";
    stringstream ss;
    ss << (lower + upper) / 2;
    string ans;
    ss >> ans;
    return ans;
}

signed main(){
    while(input()) { cout << solve() << endl; }
    return 0;
}
