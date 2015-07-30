/*
 保留
 insertの使い方
 findの使い方等のstring系
 */

#include <iostream>
#include <string>

using namespace std;


int main(){
    
    int n;
    cin >> n;
    cin.ignore();
    string ans[1000];
    
    for( int i = 0; i < n; i++){
        int cnt = 0;
        string str;
        getline( std::cin, str);
        cin >> cnt;
        string::size_type loc = 0;
        cin.ignore();
        for( int j = 0; j < cnt; j++){
            string command;
            
            getline( cin, command);
            
            if( command.find("insert") != string::npos){
                string::size_type f = str.find_first_of('"',0);
                string::size_type l = str.find_last_of('"',0);
                str.insert( loc, command, f, l - f + 1);
                loc = l + 1;
                if( loc > str.length()){
                    loc = str.length();
                }
            }else{
                if( command == "forward char"){
                    if( loc <= str.length()){
                        loc++;
                    }
                }else if( command == "forward word"){
                    string::size_type f = str.find_first_of(' ',loc);
                    if( f == string::npos){
                        loc = str.length()+1;
                    }else{
                        loc = f;
                    }
                }else if( command == "backward char"){
                    if( loc > 0){
                        loc--;
                    }
                }else if( command == "backward word"){
                    string::size_type l = str.find_last_of( " ", 0, loc);
                    if( l == string::npos){
                        loc = 0;
                    }else{
                        loc = l + 1;
                    }
                }else if( command == "delete char"){
                    if( loc < str.length() + 1){
                        str.erase( loc, 1);
                    }
                }else if( command == "delete word"){
                    string::size_type f = str.find_first_of(" ",loc);
                    if( f == string::npos){
                        f = str.length();
                    }
                    if( loc < str.length() && !str.empty()){
                        str.erase( loc, loc - f);
                    }
                }
            }
           cout << str << endl;
        }
        cout << 'A' << endl;
        str.insert( loc, "^");
        ans[i] = str;
        cout << 'A' << endl;
    }
    
    cout << 'A' << endl;
    for( int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}


/*
1
A sample input
9
forward word
delete char
forward word
delete char
forward word
delete char
backward word
backward word
forward word
*/