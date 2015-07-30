#include <iostream>
#include <string>

using namespace std;

string lake[128];

int h, w;
int di[] = {1,1,1,0,-1,-1,-1,0};
int dj[] = {-1,0,1,1,1,0,-1,-1};

inline bool in(int i, int j){ return i < h && i >= 0 && j < w && j >= 0;}

void dfs(int i, int j){
    lake[i][j] = '.';
    for(int k = 0; k < 8; k++){
        int ni = i + di[k], nj = j + dj[k];
        if(in(ni, nj) && lake[ni][nj] == 'W') dfs(ni, nj);
    }
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++)
        cin >> lake[i];
    int ans = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(lake[i][j] == 'W') ans++, dfs(i, j);
    cout << ans << endl;
}
