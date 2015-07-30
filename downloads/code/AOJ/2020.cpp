#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <set>

typedef long long ll;

using namespace std;

string str;

bool boin(int i){
    //cout << str[i] << endl;
    if(str[i] == 'a' ||str[i] == 'i' ||str[i] == 'u' ||str[i] == 'e' ||str[i] == 'o')return true;
    else return false;
}
bool museiC(int i){
    if(str[i] == 'k' || str[i] == 's' || str[i] == 't' || str[i] == 'h' || str[i] == 'p') return true;
    else if(str[i] == 'y' && museiC(i-1)) return true;
    else return false;
}

int main(){
    
    while(cin >> str, str != "#"){
        bool mflag = false;
        for(int i = 0; i < str.size(); i++){
            //cout << str[i] << endl;
            if(boin(i)){
                //cout << str[i] << endl;
                if(!mflag){
                    if((str[i] == 'i' || str[i] == 'u') && ((museiC(i-1) && (i == str.size() - 1)) || (museiC(i-1) && museiC(i+1)))){
                        char ch = str[i];
                        //cout << 'A' << str[i] << endl;
                        str.erase(str.begin()+i);
                        string t = "(";
                        t += ch;
                        t += ")";
                        str.insert(str.begin()+i,t.begin(),t.end());
                        i+=2;
                        mflag = true;
                    }else if(str[i] == 'a' || str[i] == 'o'){
                        if( (museiC(i+1) && (str[i+2] == str[i])) || (museiC(i+1) && (str[i+2] != str[i+1]) && (str[i+3] == str[i])) ){
                            char ch = str[i];
                            //cout << 'A' << str[i] << endl;
                            str.erase(str.begin()+i);
                            string t = "(";
                            t += ch;
                            t += ")";
                            str.insert(str.begin()+i,t.begin(),t.end());
                            i+=2;
                        }
                    }
                }else{
                    //cout << 'B' << str[i] << endl;
                    mflag = false;
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}