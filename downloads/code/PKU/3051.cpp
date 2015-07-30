#include <algorithm> 
#include <iostream>
#include <string>

using namespace std;

int w, h;
string field[1024];

inline bool in(int i, int j){return i >= 0 && i < h && j >= 0 && j < w;}

const int di[] = {-1,1,0,0};
const int dj[] = {0,0,-1,1};

int dfs(int i, int j){
    field[i][j] = '.';
    int ret = 1;
    for(int k = 0; k < 4; k++){
        int ni = i + di[k], nj = j + dj[k];
        if(in(ni,nj) && field[ni][nj] == '*')
            ret += dfs(ni, nj);
    }
    return ret;
}

int main(){
    cin >> w >> h;
    for(int i = 0; i < h; i++)
        cin >> field[i];
    int ans = 0;
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            if(field[i][j] == '*')
                ans = max(ans, dfs(i, j));
    cout << ans << endl;
    return 0;
}
