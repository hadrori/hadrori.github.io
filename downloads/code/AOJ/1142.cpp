#include <iostream>
#include <algorithm>
#include <string>
#include <set>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

pair<string,string> splitstr(string str, int a){
    string str1, str2;
    rep(i,str.size()){
        if(i <= a) str1.push_back(str[i]);
        else str2.push_back(str[i]);
    }
    return make_pair(str1, str2);
}

int main(){
    int m;
    cin >> m;
    rep(z,m){
        string train;
        cin >> train;
        set<string> pattern;
        
        rep(i,train.size()-1){
            pair<string,string> tmp = splitstr(train,i);
            
            pattern.insert(tmp.first + tmp.second);
            pattern.insert(tmp.second + tmp.first);
            
            reverse(tmp.first.begin(),tmp.first.end());
            
            pattern.insert(tmp.first + tmp.second);
            pattern.insert(tmp.second + tmp.first);
            
            reverse(tmp.second.begin(),tmp.second.end());
            
            pattern.insert(tmp.first + tmp.second);
            pattern.insert(tmp.second + tmp.first);
            
            reverse(tmp.first.begin(),tmp.first.end());
            
            pattern.insert(tmp.first + tmp.second);
            pattern.insert(tmp.second + tmp.first);
            
        }
        
        cout << pattern.size() << endl;
    }
    
}