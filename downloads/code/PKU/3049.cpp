#include <algorithm>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int L, C;
char chara[32];
const string vow = "aiueo";
string seq;

bool valid(){
    int cntv = 0;
    for(int i = 0; i < L; i++){
        if(vow.find(seq[i]) != string::npos) cntv++;
        if(cntv > L - 2) return 0;
    }
    if(cntv > 0 && L - cntv > 1) return 1;
    return 0;
}

void dfs(int cur, int l){
    if(l == L){
        if(valid()) printf("%s\n", seq.c_str());
        return;
    }
    if(cur == C) return;
    seq.push_back(chara[cur]);
    dfs(cur+1, l+1);
    seq.erase(seq.end()-1, seq.end());
    dfs(cur+1, l);
    return;
}

int main(){
    char hoge;
    scanf("%d%d%c", &L, &C, &hoge);
    for(int i = 0; i < C; i++){
        scanf("%c%c", chara+i, &hoge);
    }
    sort(chara, chara+C);
    seq = "";
    dfs(0, 0);
}
