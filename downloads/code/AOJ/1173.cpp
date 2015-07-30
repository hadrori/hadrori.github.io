#include <iostream>
#include <stack>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    string str;
    while(getline(cin,str), str != "."){
        stack<char> kakko;
        bool cflag = true;
        rep(i,str.size()){
            if(str[i] == '(' || str[i] == '['){
                kakko.push(str[i]);
            }
            else if(str[i] == ')'){
                if(kakko.empty() || kakko.top() != '('){
                    cflag = false;
                    break;
                }else{
                    kakko.pop();
                }
            }else if(str[i] == ']'){
                if(kakko.empty() || kakko.top() != '['){
                    cflag = false;
                    break;
                }else{
                    kakko.pop();
                }
            }
        }
        
        if(cflag && !kakko.empty()) cflag = false;
        
        if(cflag) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}