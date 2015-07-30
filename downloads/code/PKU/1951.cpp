#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

bool used[26];
string str;
string punc = ".,?", vowels = "AEIOU";

string solve(){
    getline(cin, str);
    string ans = "";
    for(int i = 0; i < str.size(); i++){
        if(punc.find(str[i]) != string::npos) {
            ans.push_back(str[i]);
            continue;
        }
        if(str[i] != ' '){
            if(vowels.find(str[i]) != string::npos || used[str[i]-'A']) continue;
            used[str[i]-'A'] = 1;
            ans.push_back(str[i]);
        }
        else if(ans.size() > 0 && ans[ans.size()-1] != ' ') ans.push_back(' ');
    }
    if(ans.size() > 0 && ans[ans.size()-1] == ' ') ans.erase(ans.end()-1, ans.end());
    for(int i = 1; i < ans.size(); i++)
        if(ans[i] == ' ' && punc.find(ans[i+1]) != string::npos) 
            ans.erase(ans.begin()+i, ans.begin()+i+1);
    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}
