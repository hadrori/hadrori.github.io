#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int n;
    string str[100];
    
    cin >> n;
    cin.ignore();

    
    for( int i = 0; i < n; i++){
        getline(cin,str[i]);
        while(1){
            string::size_type f = str[i].find("Hoshino",0);
            if( f == string::npos){
                break;
            }
            str[i].erase(f,7);
            str[i].insert(f,"Hoshina");
        }
    }
    
    for( int i = 0; i < n; i++){
        cout << str[i] << endl;
    }
    
    return 0;
}