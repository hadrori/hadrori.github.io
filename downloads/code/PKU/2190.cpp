#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string a;

int main(){
    cin >> a;
    int sum = 0, pos;
    for(int i = 0; i < 10; i++)
        if(a[i] == 'X') sum += 10 * (10-i);
        else if('0' <= a[i] && a[i] <= '9') sum += int(a[i]-'0') * (10-i);
        else pos = 10-i;

    for(int i = 0; i < (pos==1? 11: 10); i++)
        if((pos * i + sum) % 11 == 0){
            if(i == 10) cout << 'X' << endl;
            else cout << i << endl;
            return 0;
        }
    cout << -1 << endl;
    return 0;
}
