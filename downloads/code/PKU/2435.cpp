#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> pii;
typedef pair<char,int> pci;

const int dx[] = {-2, 2, 0, 0};
const int dy[] = {0, 0, -2, 2};
const string dir = "WENS";

int H, W;
string field[64];
char from[128][128];
int sx, sy;
int ex, ey;
vector<pci> ans;


inline int av(int a, int b){ return (a + b) / 2;}
inline bool in(int x, int y){ return x >= 0 && y >= 0 && x < 2*W-1 && y < 2*H-1;}
inline bool can(int x, int y, int tx, int ty){ return in(tx, ty) && field[ty][tx] == '+' && field[av(y,ty)][av(x,tx)] != '.';}

void bfs(){
    queue<pii> que;
    que.push(pii(sx, sy));
    from[sy][sx] = 'A';
    while(!que.empty()){
        int x = que.front().first, y = que.front().second;
        if(x == ex && y == ey) break;
        que.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(can(x, y, nx, ny) && (from[ny][nx] < 'A' || from[ny][nx] > 'Z')){
                from[ny][nx] = dir[i];
                que.push(pii(nx, ny));
            }
        }
    }
}

void make_answer(){
    int x = ex, y = ey;
    while(x != sx || y != sy){
        if(ans.size() > 0 && ans.back().first == from[y][x])
            ans.back().second++;
        else ans.push_back(pci(from[y][x], 1));
        switch(from[y][x]){
        case 'W': x += 2; break;
        case 'E': x -= 2; break;
        case 'N': y += 2; break;
        case 'S': y -= 2; break;
        }
    }
    reverse(ans.begin(), ans.end());
}

int main(){
    cin >> H >> W;
    for(int i = 0; i < 2 * H - 1; i++)
        cin >> field[i];
    for(int i = 0; i < 2 * H - 1; i++)
        for(int j = 0; j < 2 * W - 1; j++)
            if(field[i][j] == 'S') {
                sx = j; sy = i;
                field[i][j] = '+';
            } else if(field[i][j] == 'E'){
                ex = j; ey = i;
                field[i][j] = '+';                
            }
    bfs();
    make_answer();
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
