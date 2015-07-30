#include <iostream>
#include <vector>
#include <string>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1};

vector<string> board(8);

//マミさんのターン
bool turnm(){
    
    int maxa = 0;
    int x = -1;
    int y = -1;
    rep(i, 0, 8){
        rep(j, 0, 8){
            if(board[i][j] == '.'){
                int tmax = 0;
                rep(k, 0, 8){
                    int cnt = 0;
                    int l = 1;
                    while((i + l * dx[k] < 8) && (i + l * dx[k] >= 0) && (j + l * dy[k] >= 0) && (j + l * dy[k] < 8) ){
                        if(board[i+l*dx[k]][j+l*dy[k]] == 'x') cnt++;
                        else if(board[i+l*dx[k]][j+l*dy[k]] == '.') break;
                        else if( board[i+l*dx[k]][j+l*dy[k]] == 'o'){
                            tmax += cnt;
                            break;
                        }
                        l++;
                    }
                }
                if(maxa < tmax){
                    maxa = tmax;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if( x >= 0){
        board[x][y] = 'o';
        rep(k, 0, 8){
            int l = 1;
            while((x + l * dx[k] < 8) && (x + l * dx[k] >= 0) && (y + l * dy[k] >= 0) && (y + l * dy[k] < 8)){
                if(board[x+l*dx[k]][y+l*dy[k]] == 'x') l++;
                else if(board[x+l*dx[k]][y+l*dy[k]] == '.') break;
                else if( board[x+l*dx[k]][y+l*dy[k]] == 'o'){
                    int n = l;
                    while(n > 0){
                        board[x+n*dx[k]][y+n*dy[k]] = 'o';
                        n--;
                    }
                    break;
                }
            }
        }
        return true;
    }
    return false;
}

//シャルロッテのターン
bool turnc(){
    
    int maxa = 0;
    int x = -1;
    int y = -1;
    for(int i = 7; i >= 0; i--){
        for(int j = 7; j >= 0; j--){
            if(board[i][j] == '.'){
                int tmax = 0;
                rep(k, 0, 8){
                    int cnt = 0;
                    int l = 1;
                    while((i + l * dx[k] < 8) && (i + l * dx[k] >= 0) && (j + l * dy[k] >= 0) && (j + l * dy[k] < 8) ){
                        if(board[i+l*dx[k]][j+l*dy[k]] == 'o') cnt++;
                        else if(board[i+l*dx[k]][j+l*dy[k]] == '.') break;
                        else if( board[i+l*dx[k]][j+l*dy[k]] == 'x'){
                            tmax += cnt;
                            break;
                        }
                        l++;
                    }
                }
                if(maxa < tmax){
                    maxa = tmax;
                    x = i;
                    y = j;
                }
            }
        }
    }
    if( x >= 0){
        board[x][y] = 'x';
        rep(k, 0, 8){
            int l = 1;
            while((x + l * dx[k] < 8) && (x + l * dx[k] >= 0) && (y + l * dy[k] >= 0) && (y + l * dy[k] < 8)){
                if(board[x+l*dx[k]][y+l*dy[k]] == 'o') l++;
                else if(board[x+l*dx[k]][y+l*dy[k]] == '.') break;
                else if( board[x+l*dx[k]][y+l*dy[k]] == 'x'){
                    int n = l;
                    while(n > 0){
                        board[x+n*dx[k]][y+n*dy[k]] = 'x';
                        n--;
                    }
                    break;
                }
            }
        }
        return true;
    }
    return false;
}

int main(){
    rep(i, 0, 8){
        cin >> board[i];
    }
    bool turn = true;
    bool mflag = true;
    bool cflag = true;
    while(1){
        
        if(turn) mflag = turnm();
        else cflag = turnc();
        
        if(!mflag && !cflag) break;
        turn = !turn;
    }
    
    rep(i, 0, 8){
        cout << board[i] << endl;
    }
}