#include <iostream>
#include <queue>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int w, h;
    while(cin >> w >> h, w || h){
        int maze[40][40][4];//{l,d,r,u}
        int dis[40][40] = {0};
        rep(i,2*h-1){
            if(i%2){
                rep(j,w){
                    int t;
                    cin >> t;
                    maze[i/2][j][1] = t;
                    maze[i/2+1][j][3] = t;
                }
            }else{
                rep(j,w-1){
                    int t;
                    cin >> t;
                    maze[i/2][j][2] = t;
                    maze[i/2][j+1][0] = t;
                }
            }
        }
        queue<pair<int,int> > bfs;
        dis[0][0] = 1;
        bfs.push(make_pair(0,0));
        while(!bfs.empty()){
            int i = bfs.front().first;
            int j = bfs.front().second;
            int cnt = dis[i][j];
            bfs.pop();
            if((i < h-1) && (maze[i][j][1] == 0) && (dis[i+1][j] == 0)){
                bfs.push(make_pair(i+1,j));
                dis[i+1][j] = cnt+1;
            }
            if((i > 0) && (maze[i][j][3] == 0) && (dis[i-1][j] == 0)){
                bfs.push(make_pair(i-1,j));
                dis[i-1][j] = cnt+1;
            }
            if((j > 0) && (maze[i][j][0] == 0) && (dis[i][j-1] == 0)){
                bfs.push(make_pair(i,j-1));
                dis[i][j-1] = cnt+1;
            }
            if((j < w-1) && (maze[i][j][2] == 0) && (dis[i][j+1] == 0)){
                bfs.push(make_pair(i,j+1));
                dis[i][j+1] = cnt+1;
            }
        }
        cout << dis[h-1][w-1] << endl;
    }
}