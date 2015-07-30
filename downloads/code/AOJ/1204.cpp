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

int ans, n;
bool rsv[5][20];
vector< vector<bool> > crsv(5);


bool mCheck( int head){
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < n; b++){
            if(crsv[a][head+b] && rsv[a][b]) return false;
        }
    }
    return true;
}

void set_crsv( int head){
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < n; b++){
            if(rsv[a][b]) crsv[a][head+b] = true;
        }
    }
}

void clear_crsv( int head){
    for(int a = 0; a < 5; a++){
        for(int b = 0; b < n; b++){
            if(rsv[a][b]) crsv[a][head+b] = false;
        }
    }
}

void aSearch( int task, int clocks){

    if( clocks >= ans || !mCheck( clocks)){
        return;
    }else{
        set_crsv( clocks);
    }
    
    if( task == 9){
        if( clocks < ans + n){
            ans = clocks;
        }
        clear_crsv( clocks);
        return;
    }

    for( int i = 0; i < n; i++){
        aSearch( task + 1, clocks + i + 1);
        if( clocks >= ans){
            clear_crsv( clocks);
            return;
        }
    }
    
    clear_crsv( clocks);
    return;
}

int main(){
    
    for( int i = 0; i < crsv.size(); i++) crsv[i] = vector<bool>(201);
    while(1){
        
        cin >> n;
        if( n == 0) break;
    
        ans = 99999;
        
        //初期化
        for( int i = 0; i < 5; i++){
            for( int j = 0; j < 201; j++){
                crsv[i][j] = false;
            }
        }
        
        for( int i = 0; i < 5; i++){
            for( int j = 0; j < n; j++){
                rsv[i][j] = false;
            }
        }
        
        //入力
        for( int i = 0; i < 5; i++){
            string str;
            cin >> str;
            for( int j = 0; j < n; j++){
                if( str[j] == 'X') {
                    rsv[i][j] = true;
                    crsv[i][j] = true;
                    
                }
                else {
                    rsv[i][j] = false;
                    crsv[i][j] = false;
                }
            }
            
        }
        
        //探索
        for( int i = 0; i < n; i++){
            aSearch( 1, i+1);
        }
        ans += n;
        cout << ans << endl;
    }
    
    return 0;
}