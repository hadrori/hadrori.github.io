#include <iostream>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    string flic;
    cin >> flic;
    
    rep(i,flic.size()){
        bool nflag = false;
        switch ((int)(flic[i]-'0')) {
            case 1:
                break;
            case 2:
                cout << 'k';
                break;
            case 3:
                cout << 's';
                break;
            case 4:
                cout << 't';
                break;
            case 5:
                cout << 'n';
                break;
            case 6:
                cout << 'h';
                break;
            case 7:
                cout << 'm';
                break;
            case 8:
                cout << 'y';
                break;
            case 9:
                cout << 'r';
                break;
            case 0:
                if(flic[i+1] == 'U'){
                    cout << 'n';
                    nflag = true;
                }else cout << 'w';
        }
        i++;
        if(nflag) cout << 'n';
        else{
            if(flic[i] == 'T') cout << 'a';
            else if(flic[i] == 'L') cout << 'i';
            else if(flic[i] == 'U') cout << 'u';
            else if(flic[i] == 'R') cout << 'e';
            else if(flic[i] == 'D') cout << 'o';
        }
    }
    cout << endl;
    
}