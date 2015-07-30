#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<string> pattern;

struct PMA{
    PMA* next[256];
    PMA(){ memset(next,0,sizeof(next));}
    ~PMA(){ for(int i = 0; i < 256; i++)if(next[i]) delete next[i];}
};

PMA *buildPMA(){
    PMA *root = new PMA, *now;
    root->next[0] = root;
    for(int i = 0; i < pattern.size(); i++){
        now = root;
        for(int j = 0; j < pattern[i].size(); j++){
            if(!now->next[pattern[i][j]])
                now->next[pattern[i][j]] = new PMA;
            now = now->next[pattern[i][j]];
        }
    }
    return root;
}

int match(PMA *root, const string a){
    PMA *pma = root;
    for(int i = 0; i < a.size(); i++){
        int c = a[i];
        if(!pma->next[c]) return 0;
        pma = pma->next[c];
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin >> M >> N;
    cin.ignore();
    for(int i = 0; i < M; i++){
        string a; getline(cin, a);
        pattern.push_back(a);
    }
    PMA *pma = buildPMA();
    int ans = 0;
    for(int i = 0; i < N; i++){
        string a; getline(cin, a);
        ans += match(pma, a);
    }
    cout << ans << endl;
    return 0;
}
