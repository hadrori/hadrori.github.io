#include <iostream>
#include <string>

using namespace std;

int y, m, d;
const string day[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

int main(){
    cin >> y >> m >> d;
    if(m < 3) y--, m += 12;
    cout << day[(y+y/4-y/100+y/400+(13*m+8)/5+d)%7] << endl;
    return 0;
}
