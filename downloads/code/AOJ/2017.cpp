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

#define ll long long int

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int W, H;
vector<string> room(17);
vector<bool> dir(1000);
vector<vector<bool> > p(17);

bool KtoM();
bool MtoK();

int main(){
    for(int i = 0; i < 17; i++) p[i] = vector<bool>;
    while(1){
        //input
        cin >> W >> H;
        if( W == 0 && H == 0) break;

        for(int i = 0; i < H; i++){
            cin >> room[i];
        }
        //init
        dir.clear();
        for(int i = 0; i < 17; i++){
            for(int j = 0; j < 65; j++) p[i][j] = false;
        }
        //solve
        if( KtoM()){
            if( MtoK()){
                cout << "He can accomplish his mission." << endl;
            }else{
                cout << "He cannot return to the kitchen." << endl;
            }
        }else{
            cout << "He cannot bring tea to his master." << endl;
        }
    }
    
    
    return 0;
}

bool KtoM(){
    queue<pair<pair<int,int>,bool> > robo;
    int x, y, k;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if( room[i][j] == 'K'){
                mflag = true;
                x = i;
                y = j;
                if( room[i-1][j] == '.'){
                    k = 3;
                }else if( room[i][j-1] == '.'){
                    k = 2;
                }else if( room[i+1][j] == '.'){
                    k = 1;
                }else{
                    k = 0;
                }
                break;
            }
        }
        if(mflag) break;
    }
    
    
    
    
}

bool MtoK(){
    
}