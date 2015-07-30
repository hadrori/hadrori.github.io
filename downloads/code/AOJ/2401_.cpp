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
#include <bitset>

#define rep(i, b) for(int i = 0; i < b; i++)

#define pb push_back
#define mp make_pair

using namespace std;

int cnt;
bool ok;

pair<string, string> equation(string str){
    string f[2];
    int t = 0;
    rep(i,str.size()){
        if(str[i] == '='){
            t++;
            continue;
        }
        if(str[i] == '-'){
            if(str[i+1] == '-')str.erase(str.begin()+i,str.begin()+i+2);
            if(str[i+1] == '>')str.erase(str.begin()+i,str.begin()+i+1);
        }
        f[t] += str[i];
    }

    return mp(f[0],f[1]);
}

string formula(string f){

//    cout << f << endl;
    string a, b, op, mi;
    int i = 0, bal;

    if(f[0] == '-'){
        i++;
        mi = "-";
    }
    else mi.clear();

    if(f[i] != '('){
        string ret;
        ret += f[i];
        ret += mi;
        return ret;
    }

    f.erase(f.begin()+i,f.begin()+i+1);
    f.erase(f.end()-1,f.end());

    bal = 0;
    string tmp = "";
    if(f[i] == '('){
        bal++;
        i++;
        tmp += "(";
    }else if(f[i] == '-'){
        tmp += f[i++];
        tmp += f[i++];
    }
    else tmp += f[i++];

    for( ; bal; i++){
        if(f[i] == '(') bal++;
        else if(f[i] == ')') bal--;
        tmp += f[i];
    }
    a = formula(tmp);

    op = f[i++];

    tmp.clear();
    bal = 0;
    if(f[i] == '('){
        bal++;
        i++;
        tmp += "(";
    }else if(f[i] == '-'){
        tmp += f[i++];
        tmp += f[i++];
    }
    else tmp += f[i++];

    for( ; bal; i++){
        if(f[i] == '(') bal++;
        else if(f[i] == ')') bal--;
        tmp += f[i];
    }
    b = formula(tmp);

    string ret = a + b + op + mi;
    return ret;
}

char calc(char a, char b, char op){
    bool x = (a=='1')? 1:0;
    bool y = (b=='1')? 1:0;
    if(op == '-') return (!y) + '0';
    if(op == '+') return (x||y) + '0';
    if(op == '*') return (x&&y) + '0';
    if(op == '>') return (x>=y) + '0';
}

int main(){
    string str;
 
    while(cin>>str,str!="#"){
        map<char,int> id;
        cnt = -1;
        ok = true;
        string l, r;
        
        rep(i,str.size()) if(str[i]>='a' && str[i] <= 'k'){
            if(id.find(str[i]) != id.end()) id[str[i]] = ++cnt;
        }
        cnt++;
        pair<string,string> f = equation(str);
        
        l = formula(f.first);
        r = formula(f.second);
        vector<char> wariate(cnt);
        rep(S,1<<cnt){
            rep(i,cnt){
                wariate[i] = (S & (1<<i)) + '0';
            }
            for(int i = 0; l.size() != 1; i++){
                if(l[i] == 'T') l[i] = '1';
                else if(l[i] == 'F') l[i] = '0';
                else if(l[i] >= 'a' && l[i] <= 'k') l[i] = wariate[id[l[i]]];
                else if(l[i] == '-'){
                    char t = calc('0',l[i-1],l[i]);
                    l.replace(l.begin()+i-1,l.begin()+i+1,1,t);
                    i = 0;
                }
                else if(l[i] == '+' || l[i] == '*' || l[i] == '>'){
                    char t = calc(l[i-2],l[i-1],l[i]);
                    l.replace(l.begin()+i-2,l.begin()+i+1,1,t);
                    i = 0;
                }
            }
            for(int i = 0; r.size() != 1; i++){
                if(r[i] == 'T') r[i] = '1';
                else if(r[i] == 'F') r[i] = '0';
                else if(r[i] >= 'a' && r[i] <= 'k') r[i] = wariate[id[r[i]]];
                else if(r[i] == '-'){
                    char t = calc('0',r[i-1],r[i]);
                    r.replace(r.begin()+i-1,r.begin()+i+1,1,t);
                    i = 0;
                }
                else if(r[i] == '+' || r[i] == '*' || r[i] == '>'){
                    char t = calc(r[i-2],r[i-1],r[i]);
                    r.replace(r.begin()+i-2,r.begin()+i+1,1,t);
                    i = 0;
                }
            }
            if(l!=r){
                ok = false;
                break;
            }
            cout << (ok?"YES":"NO") << endl;
        }
    }
}
