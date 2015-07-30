#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

typedef pair<int,int> pii;

const int inf = int(1e9);
int N, M, L;
string str;
int cst[26];

int memo[2048][2048];

int rec(int l, int r){
    if(memo[l][r] >= 0) return memo[l][r];
    if(r - l < 1) return memo[l][r] = 0;
    if(str[l] == str[r]) return memo[l][r] = rec(l+1,r-1);
    return memo[l][r] = min(rec(l ,r-1)+cst[str[r]-'a'], rec(l+1,r)+cst[str[l]-'a']);
}

int main(){
    cin >> N >> M;
    cin >> str;
    int L = str.size();
    for(int i = 0; i < N; i++){
        char c; int a, d;
        cin >> c >> a >> d;
        cst[c-'a'] = min(a, d);
    }
    memset(memo,-1,sizeof(memo));
    cout << rec(0, L-1) << endl;
    return 0;
}
