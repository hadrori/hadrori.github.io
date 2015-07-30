#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char,char> cnv;
string mess;

void input(){
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
        cnv['a'+i] = str[i];
    cin.ignore();
    getline(cin, mess);
}

void solve(){
    for(int i = 0; i < mess.size(); i++){
        if(mess[i] == ' ') cout << ' ';
        else if('A' <= mess[i] && mess[i] <= 'Z')
            cout << char(cnv['a'+mess[i]-'A']+'A'-'a');
        else cout << cnv[mess[i]];
    }
    cout << endl;
}

signed main(){
    input();
    solve();
}
