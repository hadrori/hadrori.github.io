#include <iostream>

using namespace std;

int N, S;
int table[21][21];

int main(){
    cin >> N >> S;
    for(int i = 0; i < N; i++)
        for(int j = 0; j <= i; j++){
            table[j][i] = S++;
            if(S == 10) S = 1;
        }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++){
            if(table[i][j]) cout << table[i][j];
            else cout << ' ';
            cout << (j==N-1? '\n': ' ');
        }
}
