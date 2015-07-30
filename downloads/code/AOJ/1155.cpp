#include <bits/stdc++.h>
#define rep(i, b) for(int i = 0; i < b; i++)
using namespace std;

int calc(int x, char c, int y){
    if( c == '-'){
        if(y == 0) return 2;
        else if(y == 1) return 1;
        else return 0;
    }
    if(c == '+'){
        if(x == 0) return y;
        else if(x == 1){
            if(y == 0) return x;
            else return y;
        }
        else if(x == 2) return x;
    }
    if(c == '*'){
        if(x == 0 || y == 0) return 0;
        else if(x == 1 || y == 1) return 1;
        else return 2;
    }
}

int main(){
    string str;
    while(cin >> str, str != "."){
        rep(i,str.size()){
            if(str[i] == '-' && str[i+1] == '-'){
                i = str.erase(str.begin() + i, str.begin() + i + 2) - str.begin();
            }
        }
        int cnt = 0;
        rep(p,3) rep(q,3) rep(r,3){
            string tmp = str;
            bool flag = true;
            while(1){
                int x = -1, y = -1;
                char c;
                int i = 0;
                while(tmp[i++] != ')'){
                    if(i >= tmp.size()){
                        flag = false;
                        break;
                    }
                }
                if(!flag)break;
                i--;
                tmp.erase(tmp.begin() + i, tmp.begin() + i + 1);
                int j = i;
                char command;
                while(tmp[j] != '('){
                    if(tmp[j] >= '0' && tmp[j] <= '2'){
                        if(y == -1) y = tmp[j] - '0';
                        else x = tmp[j] - '0';
                    }
                    else if(tmp[j] == 'P'){
                        if(y == -1) y = p;
                        else x = p;
                        tmp[j] = p + '0';
                    }
                    else if(tmp[j] == 'Q'){
                        if(y == -1) y = q;
                        else x = q;
                        tmp[j] = q + '0';
                    }
                    else if(tmp[j] == 'R'){
                        if(y == -1) y = r;
                        else x = r;
                        tmp[j] = r + '0';
                    }
                    else if(tmp[j] == '-') {
                        char t = calc(0,'-',tmp[j+1]-'0') + '0';
                        tmp.replace(tmp.begin() + j, tmp.begin() + j + 2, 1, t);
                        if(x != -1) x = t - '0';
                        else y = t - '0';
                    }
                    else if(tmp[j] == '+' || tmp[j] == '*') command = tmp[j];
                    j--;
                }
                tmp.erase(tmp.begin() + j,tmp.begin() + j + 1);
                char t = calc(x,command,y) + '0';
                tmp.replace(tmp.begin() + j, tmp.begin() + j + 3, 1, t);
            }
            int y = -1;
            if( tmp[0] < '0' || tmp[0] > '2'){
                if(tmp[tmp.size()-1] == 'P') tmp[tmp.size()-1] = p + '0';
                else if(tmp[tmp.size()-1] == 'Q') tmp[tmp.size()-1] = q + '0';
                else if(tmp[tmp.size()-1] == 'R') tmp[tmp.size()-1] = r + '0';
                
                if(tmp[0] == '-'){
                    char t = calc(0,'-',tmp[1]-'0') + '0';
                    tmp.replace(tmp.begin(), tmp.begin() + 2, 1, t);
                }
            }
            if(tmp == "2") cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
