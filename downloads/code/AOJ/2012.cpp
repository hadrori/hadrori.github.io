#include <iostream>

using namespace std;

int e;

int main(){
    while(cin >> e, e){
        int mimm = 1000000, z, y;
        int maxa = 0;
        for(int i = 0; i * i * i <= e; i++){
            for(int j = 0; j * j + i * i * i <= e; j++){
                if(mimm > i + j + e - i * i * i - j * j){
                    mimm = i + j + e - i * i * i - j * j;
                    z = i;
                    y = j;
                }
            }
        }
        
        cout << y + z + e - z * z * z - y * y << endl;
    }
    
}