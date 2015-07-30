#include <bits/stdc++.h>
using namespace std;
#define rep(i,a) for(int i = 0;i < (a); i++)
#define mp make_pair

map<char,int> id;
int cnt;

char rogic(char a, char b, char op){
    bool x = (a=='T')? true: false;
    bool y = (b =='T')? true: false;
    if(op == '-') return (!x? 'T': 'F');
    if(op == '*') return (x&y? 'T': 'F');
    if(op == '+') return (x|y? 'T': 'F');
    if(op == '>') return (x<=y? 'T': 'F');
}

bool calc(pair<string,string> eq){
    rep(i,1<<cnt){
        string left = eq.first;
        string right = eq.second;
        char l, r;
        rep(cur,left.size()){
            if(left[cur]>='a' && left[cur]<='k')
                left[cur] = (i&(1<<id[left[cur]]))? 'T': 'F';
            else if(left[cur]=='-'){
                char res = rogic(left[cur-1],'T','-');
                left.replace(cur-1,2,1,res);
                cur--;
            }else if(left[cur]=='+' || left[cur]=='*' || left[cur]=='>'){
                char res = rogic(left[cur-2],left[cur-1],left[cur]);
                left.replace(cur-2,3,1,res);
                cur-=2;
            }
        }
        rep(cur,right.size()){
            if(right[cur]>='a' && right[cur]<='k')
                right[cur] = (i&(1<<id[right[cur]]))? 'T': 'F';
            else if(right[cur]=='-'){
                char res = rogic(right[cur-1],'T','-');
                right.replace(cur-1,2,1,res);
                cur--;
            }else if(right[cur]=='+' || right[cur]=='*' || right[cur]=='>'){
                char res = rogic(right[cur-2],right[cur-1],right[cur]);
                right.replace(cur-2,3,1,res);
                cur-=2;
            }
        }
        if(left!=right) return false;
    }
    return true;
}

string formula(string str){
    string ret = "";
    int cur = 0;
    char op;

    while(cur < str.size()){
        if((str[cur]>='a' && str[cur]<='k') || str[cur]=='T' || str[cur]=='F') ret += str[cur++];
        else if(str[cur]=='-' && str[cur+1]!='>'){
            int mcnt = 0;
            while(str[cur]=='-'){
                mcnt++;
                cur++;
            }
            if(str[cur]=='('){
                string form = "(";
                int kakko = 1;
                cur++;
                while(kakko){
                    if(str[cur]=='(') kakko++;
                    else if(str[cur]==')') kakko--;
                    form += str[cur];
                    cur++;
                }
                ret += formula(form);
            }else ret += str[cur++];
            if(mcnt%2) ret += '-';
        }else if(str[cur]=='('){
            int mcnt = 0;
            string form = "";
            cur++;
            while(str[cur]=='-'){
                mcnt++;
                cur++;
            }
            if(mcnt%2) form += '-';
            if(str[cur]=='('){
                form += '(';
                int kakko = 1;
                cur++;
                while(kakko){
                    if(str[cur]=='(') kakko++;
                    else if(str[cur]==')') kakko--;
                    form += str[cur];
                    cur++;
                }
                ret += formula(form);
            }else{
                form += str[cur++];
                ret += formula(form);
            }
            
            op = str[cur++];
            if(op == '-') op = str[cur++];

            mcnt = 0;
            form = "";
            while(str[cur]=='-'){
                mcnt++;
                cur++;
            }
            if(mcnt%2) form += '-';
            if(str[cur]=='('){
                form += '(';
                int kakko = 1;
                cur++;
                while(kakko){
                    if(str[cur]=='(') kakko++;
                    else if(str[cur]==')') kakko--;
                    form += str[cur];
                    cur++;
                }
                ret += formula(form);
            }else{
                form += str[cur++];
                ret += formula(form);
            }
            ret += op;
            cur++;
        }
    }
    return ret;
}

pair<string,string> equation(string str){
    string retl = "", retr = "";
    int cur = 0;
    while(str[cur] != '='){
        retl += str[cur];
        if(str[cur]>='a' && str[cur]<='k' && id.find(str[cur])==id.end()){
            id[str[cur]] = cnt++;
        }
        cur++;
    }
    cur++;
    while(cur<str.size()){
        retr += str[cur];
        if(str[cur]>='a' && str[cur]<='k' && id.find(str[cur])==id.end()){
            id[str[cur]] = cnt++;
        }
        cur++;
    }
    retl = formula(retl);
    retr = formula(retr);

    return mp(retl,retr);
}

int main(){
    string str;
    while(cin>>str,str!="#"){
        id.clear(); cnt = 0;
        pair<string,string> eq = equation(str);
        cout << (calc(eq)? "YES\n": "NO\n");
    }
    return 0;
}
