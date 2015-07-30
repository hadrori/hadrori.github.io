#include <iostream>
#include <vector>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;
int w, h;
vector<vector<int> > maps(60);

void dfs(int i, int j){
    maps[i][j] = 0;
    
    if((i > 0) && maps[i-1][j]) dfs(i-1,j);
    if((i < h-1) && maps[i+1][j]) dfs(i+1,j);
    if((j > 0) && maps[i][j-1]) dfs(i,j-1);
    if((j < w-1) && maps[i][j+1]) dfs(i,j+1);
    if((j > 0) && (i > 0) && maps[i-1][j-1]) dfs(i-1,j-1);
    if((j < w-1) && (i > 0) && maps[i-1][j+1]) dfs(i-1,j+1);
    if((j > 0) && (i < h-1) && maps[i+1][j-1]) dfs(i+1,j-1);
    if((j < w-1) && ( i < h-1 ) && maps[i+1][j+1]) dfs(i+1,j+1);
    
    return;
}

int main(){
    while(cin >> w >> h, w || h){
        rep(i, h) maps[i] = vector<int>(w);
        
        rep(i, h){
            rep(j, w){
                cin >> maps[i][j];
            }
        }
        int cnt = 0;
        rep(i, h){
            rep(j, w){
                if(maps[i][j]){
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}