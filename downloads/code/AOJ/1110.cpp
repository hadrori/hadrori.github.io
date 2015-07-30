#include <iostream>
#include <cstdlib>
#include <vector>

#define d1 1
#define d2 5
#define d3 4
#define d4 3

using namespace std;

int mPena = 100;
int ans[100] = {0};

void solve( vector<int> array, int j, int d, int count);

int main(){
    
    int n;
    int seq[100][20] = {0};
    
    cin >> n;
    for( int i = 0; i < n; i++){
        for( int j = 0; j < 5; j++){
            cin >> seq[i][j*4] >> seq[i][j*4+1] >> seq[i][j*4+2] >> seq[i][j*4+3];
        }
    }
    
    for( int i = 0; i < n; i++){
        vector<int> array;
        mPena = 100;
        int count = 0;
        for( int j = 0; j < 20; j++){
            array[j] = seq[i][j];
        }
        for( int j = 0; j < 20; j++){
            if( j % 4 != 3 && array[j] == array[j+d1]){
                solve( array, j, d1, count + 1);
            }
            if( j % 4 != 3 && array.size() - j > 3 && array[j] == array[j+d2]){
                solve( array, j, d2, count + 1);
            }
            if( array.size() - j > 3 && array[j] == array[j+d3]){
                solve( array, j, d3, count + 1);
            }
            if( j % 4 != 0 && array.size() - j > 3 && array[j] == array[j+d4]){
                solve( array, j, d4, count + 1);
            }
        }
        ans[i] = mPena;
    }
    

    for( int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}

void solve( vector<int> array, int i, int d, int count){
    
    vector<int>::iterator f;
    vector<int>::iterator g;
    f = array.begin();
    g = f;
    for( int j = 0; j < i; j++){
        f++;
        g++;
    }
    for( int j = 0; j < d; j++){
        g++;
    }
    
    array.erase(f);
    array.erase(g);
    
    bool flag = false;

    for( int j = 0; j < array.size(); j++){
        if( j % 4 != 3 && array[j] == array[j+d1]){
            solve( array, j, d1, count + 1);
            flag = true;
        }
        if( j % 4 != 3 && array.size() - j > 3 && array[j] == array[j+d2]){
            solve( array, j, d2, count + 1);
            flag = true;
        }
        if( array.size() - j > 3 && array[j] == array[j+d3]){
            solve( array, j, d3, count + 1);
            flag = true;
        }
        if( j % 4 != 0 && array.size() - j > 3 && array[j] == array[j+d4]){
            solve( array, j, d4, count + 1);
            flag = true;
        }
    }
    
    if( !flag){
        if( 10 - count < mPena ){
            mPena = 10 - count;
        }
    }
    return;
}






