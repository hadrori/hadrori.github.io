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
#define repi(i, a, b) for(int i = a; i < b; i++)
#define repd(i, a, b) for(int i = a; i > b; i--)

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

string decode(string str, char ch){

    if(ch == 'J'){
        char c = str[str.size()-1];
        str.erase(str.end()-1,str.end());
        str = c + str;
    }else if(ch == 'C'){
        char c = str[0];
        str.erase(str.begin(),str.begin()+1);
        str += c;
    }else if(ch == 'E'){
        char c = 'A';
        int len = str.size();
        if(len % 2) c = str[len/2];
        string tmp = str.substr(len/2);
        str.erase(str.begin()+len/2,str.end());
        if(len % 2){
            tmp.erase(tmp.begin(),tmp.begin()+1);
            str = tmp + c + str;
        }
        else str = tmp + str;
    }else if(ch == 'A'){
        reverse(str.begin(),str.end());
    }else if(ch == 'P'){
        rep(i,str.size()){
            if(str[i]>='0' && str[i]<='9'){
                if(str[i] == '0') str[i] = '9';
                else str[i]--;
            }
        }
    }else if(ch == 'M'){
        rep(i,str.size()){
            if(str[i]>='0' && str[i]<='9'){
                if(str[i] == '9') str[i] = '0';
                else str[i]++;
            }
        }
    }
    return str;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string ord, mes;
        cin >> ord >> mes;
        rep(i,ord.size()){
            mes = decode(mes,ord[ord.size()-i-1]);
        }
        cout << mes << endl;
    }
}
