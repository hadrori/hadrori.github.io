#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string str;
    
    getline(cin,str);
    string tmp;
    
    while(str.length() > 0){
        tmp += str[str.size()-1];
        str.erase(str.size()-1);
    }
    
    cout << tmp << endl;
    
    
    return 0;
}