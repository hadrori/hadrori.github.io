#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define rep(i,a) for(int i = 0; i < a; i++)
#define repi(i,a,b) for(int i = a; i < b; i++)
#define repd(i,a,b) for(int i = a; i > b; i--)

#define pb push_back


using namespace std;

string cube[6] = {"..rr....",
    "..rr....",
    "ggyybbww",
    "ggyybbww",
    "..oo....",
    "..oo...."};

void rot(char cmd){
    if(cmd == 'U'){
        char l1 = cube[2][0], l2 = cube[2][1];
        cube[2].erase(cube[2].begin(),cube[2].begin() + 2);
        cube[2] += l1;
        cube[2] += l2;
        l1 = cube[0][2];
        cube[0][2] = cube[1][2];
        cube[1][2] = cube[1][3];
        cube[1][3] = cube[0][3];
        cube[0][3] = l1;
    }else if(cmd == 'F'){
        char l1 = cube[1][2], l2 = cube[1][3];
        cube[1][2] = cube[3][1];
        cube[1][3] = cube[2][1];
        cube[3][1] = cube[4][3];
        cube[2][1] = cube[4][2];
        cube[4][3] = cube[2][4];
        cube[4][2] = cube[3][4];
        cube[2][4] = l1;
        cube[3][4] = l2;
        l1 = cube[2][2];
        cube[2][2] = cube[3][2];
        cube[3][2] = cube[3][3];
        cube[3][3] = cube[2][3];
        cube[2][3] = l1;
    }else if(cmd == 'R'){
        char l1 = cube[0][3], l2 = cube[1][3];
        cube[0][3] = cube[2][3];
        cube[1][3] = cube[3][3];
        cube[2][3] = cube[4][3];
        cube[3][3] = cube[5][3];
        cube[4][3] = cube[3][6];
        cube[5][3] = cube[2][6];
        cube[3][6] = l1;
        cube[2][6] = l2;
        l1 = cube[2][4];
        cube[2][4] = cube[3][4];
        cube[3][4] = cube[3][5];
        cube[3][5] = cube[2][5];
        cube[2][5] = l1;
    }else if(cmd == 'D'){
        char l1 = cube[3][6], l2 = cube[3][7];
        cube[3].erase(cube[3].begin() + 6, cube[3].begin() + 8);
        string str = "";
        str += l1;
        str += l2;
        str += cube[3];
        cube[3] = str;
        l1 = cube[4][2];
        cube[4][2] = cube[5][2];
        cube[5][2] = cube[5][3];
        cube[5][3] = cube[4][3];
        cube[4][3] = l1;
    }else if(cmd == 'B'){
        char l1 = cube[0][2], l2 = cube[0][3];
        cube[0][2] = cube[2][5];
        cube[0][3] = cube[3][5];
        cube[2][5] = cube[5][3];
        cube[3][5] = cube[5][2];
        cube[5][3] = cube[3][0];
        cube[5][2] = cube[2][0];
        cube[2][0] = l2;
        cube[3][0] = l1;
        l1 = cube[2][6];
        cube[2][6] = cube[3][6];
        cube[3][6] = cube[3][7];
        cube[3][7] = cube[2][7];
        cube[2][7] = l1;
    }else if(cmd == 'L'){
        char l1 = cube[5][2], l2 = cube[4][2];
        cube[5][2] = cube[3][2];
        cube[4][2] = cube[2][2];
        cube[3][2] = cube[1][2];
        cube[2][2] = cube[0][2];
        cube[1][2] = cube[2][7];
        cube[0][2] = cube[3][7];
        cube[2][7] = l1;
        cube[3][7] = l2;
        l1 = cube[2][0];
        cube[2][0] = cube[3][0];
        cube[3][0] = cube[3][1];
        cube[3][1] = cube[2][1];
        cube[2][1] = l1;
    }
    
}

int main(){
    string command;
    cin >> command;
    
    rep(i,command.size()){
        rot(command[i]);
    }
    
    rep(i,6) cout << cube[i] << endl;
}
