#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#define rep(i,a) for(int i = 0;i < (a); i++)
#define all(u) (u).begin(),(u).end()
using namespace std;

//-1はm1とする
int ston(string num){
    int ret = 0;
    bool minus = false;
    if(num[0] == 'm') minus = true;
    rep(i,num.size()){
        if(num[i]=='m') continue;
        ret *= 10;
        ret += num[i] -'0';
    }
    if(minus) ret *= -1;
    return ret;
}

string ntos(int num){
    string ret = "";
    bool minus = false;
    if(num<0){
        minus = true;
        num *= -1;
    }
    if(num==0) return "0";

    while(num){
        ret += num%10 + '0';
        num /= 10;
    }
    if(minus) ret += 'm';
    reverse(all(ret));
    return ret;
}

bool isnum(char c){
    return ((c>='0' && c <='9') || c=='m');
}

int calc(int a, int b, char c){
    if(c=='+') return a+b;
    if(c=='*') return a*b;
    if(c=='/') return a/b;
    if(c=='-') return a-b;
}

void solve(string s){

    set<string> ans;
    stack<string> dfs;
    dfs.push(s);
    while(!dfs.empty()){
        string str = dfs.top();
        dfs.pop();
        rep(i,str.size()){
            if(str[i]=='('){
                int j = i+1;
                bool flag = true;
                int kakko = 1;
                bool che = false;
                while(kakko){
                    if(str[j] == '(') kakko++;
                    if(str[j] == ')'){
                        kakko--;
                        che = true;
                    }
                    if(che && str[j]!=')'){
                        flag = false;
                        break;
                    }
                    if(str[j]=='+' || str[j]=='-' || str[j]=='*' || str[j]=='/'){
                        flag = false;
                        break;
                    }
                    j++;
                }
                if(flag){
                    int k = i;
                    str.erase(str.begin()+k,str.begin()+k+1);
                    int kakko = 1;
                    while(kakko){
                        if(str[k] == '(') kakko++;
                        if(str[k] == ')') kakko--;
                        if(str[k]=='(' || str[k]==')') str.erase(str.begin()+k,str.begin()+k+1);
                        else k++;
                    }
                }                
            }
        }
        bool ok = true;

        rep(j,str.size()){
            if(str[j]=='+' || str[j]=='-' || str[j]=='*' || str[j]=='/'){
                ok = false;
                break;
            }
        }

        if(ok){
            ans.insert(str);
            goto roop;
        }

        rep(i,str.size()){
            if((str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/') &&
               isnum(str[i-1]) && isnum(str[i+1])){
                string args[2] = {};
                int nums[2];
                int cur = i-1, left, right;
                while(cur>=0 && isnum(str[cur])) args[0] += str[cur--];
                reverse(all(args[0]));
                left = ++cur;
                cur = i+1;

                while(cur<str.size() && isnum(str[cur])) args[1] += str[cur++];
                right = --cur;

                nums[0] = ston(args[0]);
                nums[1] = ston(args[1]);

                if(nums[1]==0 && str[i]=='/') continue;

                if(left>0 && right<str.size()-1){
                    if(str[left-1]=='(' && str[right+1]==')'){
                        left--;
                        right++;   
                    }
                }
                string tmp = str;
                string b = ntos(calc(nums[0],nums[1],str[i]));
                tmp.replace(tmp.begin()+left,tmp.begin()+right+1,b);
                dfs.push(tmp);
            }
        }
    roop:;
    }
    cout << ans.size() << endl;
}

int main(){
    string str;
    while(cin>>str,str!="#"){
        solve(str);
    }
}
