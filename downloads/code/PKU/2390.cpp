#include <iostream>

using namespace std;

double R, M;
int Y;

int main(){
    cin >> R >> M >> Y;
    R = (R + 100) / 100;
    while(Y --> 0)
        M *= R;
    cout << int(M) << endl;
    return 0;
}
