#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i,a) repi(i,0,a)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

struct PMA{
    PMA* next[256];
    int matched;
    PMA(){memset(next, 0, sizeof(next)); matched = 0;}
    ~PMA(){for(int i = 0; i < 256; i++) if(next[i]) delete next[i];}
};

PMA *buildPMA(vector<string> pattern){
    PMA *root = new PMA, *now;
    root->next[0] = root;
    for(int i = 0; i < (int)pattern.size(); i++){
        now = root;
        for(int j = 0; j < (int)pattern[i].size(); j++){
            if(now->next[(int)pattern[i][j]] == 0)
                now->next[(int)pattern[i][j]] = new PMA;
            now = now->next[(int)pattern[i][j]];
        }
        now->matched++;
    }
    return root;
}

int rec(PMA *pma){
    int win = 0, lose = 0, cnt = 0;
    rep(i,26) {
        int ni = i + int('a');
        if(pma->next[ni]){
            ++cnt;
            int f = rec(pma->next[ni]);
            win |= (f^2)&2;
            lose |= (f^1)&1;
        }
    }
    if(!cnt) return 1;
    assert((win&1)==0);
    return win | lose;
}

int n, k;
vector<string> ss;

int solve(){
    PMA *root = buildPMA(ss);
    int f = rec(root);
    int win = f&2, lose = f&1;
    return (win and lose) or (win and k%2);
}

void input(){
    scanf("%d%d", &n, &k);
    ss.resize(n);
    rep(i,n) cin >> ss[i];
}

int main(){
    input();
    if(solve()) puts("First");
    else puts("Second");
    return 0;
}
