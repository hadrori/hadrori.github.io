#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    while(1){
        if(str.empty()){
            cout << "Cat" << endl;
            break;
        }
        string::size_type f = str.find("mew",0);
        if( f == string::npos){
            cout << "Rabbit" << endl;
            break;
        }else {
            
            if( !(str.size() == 3 || (str[f-1] == 'm' && str[f+3] == 'e') || (str[f-1] == 'e' && str[f+3] == 'w'))){
                cout << "Rabbit" << endl;
                break;
            }
            str.erase(f,3);
        }
    }
}