#include <iostream>
#include <vector>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

vector<string> room(30);
int cnt;
int w, h;

void dfs(int a, int b){
    cnt++;
    room[a][b] = '#';
    if((a > 0) && (room[a-1][b] == '.')) dfs(a-1, b);
    if((a < h-1) && (room[a+1][b] == '.')) dfs(a+1, b);
    if((b > 0) && (room[a][b-1] == '.')) dfs(a, b-1);
    if((b < w-1) && (room[a][b+1] == '.')) dfs(a, b+1);
    
    return;
}

int main(){
    
    while(cin >> w >> h, w || h){
        
        rep(i,h) cin >> room[i];
        cnt = 0;
        rep(i, h){
            rep(j, w){
                if(room[i][j] == '@'){
                    dfs(i, j);
                    break;
                }
            }
            if(cnt > 0) break;
        }
        cout << cnt << endl;
    }
    
}