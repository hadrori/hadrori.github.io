#include <iostream>
#include <vector>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)
#define repi(i, a, b) for(int i = a; i < b; i++)

using namespace std;

bool checkpos(char c){
    if(c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'p' || c == 'h' || c == 'j' || c == 'k' || c == 'l' || c == 'n' || c == 'm')
        return true;
    else return false;
}

int main(){
    string str;
    while(cin >> str, str != "#"){
        bool pos = checkpos(str[0]);
        int cnt = 0;
        repi(i, 1, str.size()){
            bool tmp;
            if((tmp = checkpos(str[i])) != pos){
                cnt++;
                pos = tmp;
            }
        }
        cout << cnt << endl;
    }
}