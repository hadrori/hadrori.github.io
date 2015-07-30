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

char area[60][60];
int cnt[60][60];
int w, h;
int cntb, cntw;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void srch(int i, int j, char bw){
    for(int a = 0; a < 4; a++){
        if((j + dx[a] >= 0) && (j + dx[a] < w) && (i + dy[a] < h) && (i + dy[a] >= 0) && (area[i+dy[a]][j+dx[a]] == '.') && (cnt[i+dy[a]][j+dx[a]] != (int)bw) && (cnt[i+dy[a]][j+dx[a]] != (int)'B' + (int)'W')){
            cnt[i+dy[a]][j+dx[a]] += (int)bw;
            srch(i+dy[a], j+dx[a], bw);
        }
    }
}

int main(){
    
    while(cin >> w >> h, w){
        rep(i, 0, h){
            cin >> area[i];
        }
        
        rep(i, 0, 60){
            rep(j, 0, 60){
                cnt[i][j] = 0;
            }
        }
        
        rep(i, 0, h){
            rep(j, 0, w){
                if( area[i][j] == 'W' || area[i][j] == 'B'){
                    srch(i, j, area[i][j]);
                }
            }
        }
        cntb = 0;
        cntw = 0;
        rep(i, 0, h){
            rep(j, 0, w){
                if( cnt[i][j] == (int)'B'){
                    cntb++;
                }
                else if( cnt[i][j] == (int)'W'){
                    cntw++;
                }
            }
        }
        
        cout << cntb << ' ' << cntw << endl;
    }
    
    
    return 0;
}