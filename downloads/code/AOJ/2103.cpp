#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>

#define rep(i, a, b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

/*
 
 表1: マップの構成要素
 文字	要素
 .	平地
 *	レンガの壁
 #	鉄の壁
 -	水
 ^	戦車（上向き）
 v	戦車（下向き）
 <	戦車（左向き）
 >	戦車（右向き）
 
 
 表2: プレイヤーの入力に対する動作
 文字	動作
 U	Up: 戦車を上向きに方向転換し，さらに一つ上のマスが平地ならばそのマスに移動する
 D	Down: 戦車を下向きに方向転換し，さらに一つ下のマスが平地ならばそのマスに移動する
 L	Left: 戦車を左向きに方向転換し，さらに一つ左のマスが平地ならばそのマスに移動する
 R	Right: 戦車を右向きに方向転換し，さらに一つ右のマスが平地ならばそのマスに移動する
 S	Shoot: 戦車が現在向いている方向に砲弾を発射する

 */

int t;
int w, h, n;
int x, y;
int state;//0:<    1:>   2:^    3:v
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    cin >> t;
    bool flag = true;
    rep(z, 0, t){
        
        cin >> h >> w;
        vector<vector<char> > field(h);
        rep(i, 0, h){
            field[i] = vector<char>(w);
            rep(j, 0, w){
                cin >> field[i][j];
                if(field[i][j] == '<' || field[i][j] == '>' || field[i][j] == '^' || field[i][j] == 'v'){
                    x = j;
                    y = i;
                    if(field[i][j] == '<')state = 0;
                    else if(field[i][j] == '>')state = 1;
                    else if(field[i][j] == '^')state = 2;
                    else if(field[i][j] == 'v')state = 3;
                    
                    field[i][j] = '.';
                }
            }
        }
        cin >> n;
        vector<char> commands(n);
        
        rep(i, 0, n) cin >> commands[i];
        //cout << commands[0] << ' ' << x << ' ' << y << ' ' << state << endl;
        
        rep(i, 0, n){
            if(commands[i] == 'U'){
                state = 2;
                if((y > 0) && (field[y-1][x] == '.') ) y--;
            }else if(commands[i] == 'D'){
                state = 3;
                if((y < h-1) && (field[y+1][x] == '.')) y++;
            }else if(commands[i] == 'L'){
                state = 0;
                if((x > 0) && (field[y][x-1] == '.')) x--;
            }else if(commands[i] == 'R'){
                state = 1;
                if((x < w-1) && (field[y][x+1] == '.')) x++;
            }else if(commands[i] == 'S'){
                int k = 1;
                while((x + k * dx[state] >= 0) && (x + k * dx[state] < w) && (y + k * dy[state] >= 0) && (y + k * dy[state] < h) && (field[y + k * dy[state]][x + k * dx[state]] != '*') && (field[y + k * dy[state]][x + k * dx[state]] != '#')){
                    k++;
                }
                if((x + k * dx[state] >= 0) && (x + k * dx[state] < w) && (y + k * dy[state] >= 0) && (y + k * dy[state] < h) && (field[y + k * dy[state]][x + k * dx[state]] == '*')){
                    field[y + k * dy[state]][x + k * dx[state]] = '.';
                    //cout << x << ' ' << y << endl;
                }
            }
        }
        if(flag){
            flag = false;
        }else{
            cout << endl;
        }
        rep(i, 0, h){
            rep(j, 0, w) {
                if((i == y) && (j == x)){
                    switch(state){
                        case 0:
                            cout << '<';
                            break;
                        case 1:
                            cout << '>';
                            break;
                        case 2:
                            cout << '^';
                            break;
                        case 3:
                            cout << 'v';
                            break;
                    }
                }else{
                    cout << field[i][j];
                }
            }
            cout << endl;
        }
        /*
        cout << h << ' ' << w << endl;
        rep(i, 0, h){
            rep(j, 0, w) cout << field[i][j];
            cout << endl;
        }
        cout << n << endl;
        rep(j, 0, n) cout << commands[j];
        cout << endl;
         */
    }
}