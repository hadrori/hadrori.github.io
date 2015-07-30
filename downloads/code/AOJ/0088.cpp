#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i = (a); i >= (b); i--)
#define repit(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF 1e9
#define EPS 1e-10
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> P;
typedef vector<P> G;

map<char,string> ctos;
map<string,char> stoc;

int main(){
    ctos[' '] = "101";
    ctos['\''] = "000000";
    ctos[','] = "000011";
    ctos['-'] = "10010001";
    ctos['.'] = "010001";
    ctos['?'] = "000001";
    ctos['A'] = "100101";
    ctos['B'] = "10011010";
    ctos['C'] = "0101";
    ctos['D'] = "0001";
    ctos['E'] = "110";
    ctos['F'] = "01001";
    ctos['G'] = "10011011";
    ctos['H'] = "010000";
    ctos['I'] = "0111";
    ctos['J'] = "10011000";
    ctos['K'] = "0110";
    ctos['L'] = "00100";
    ctos['M'] = "10011001";
    ctos['N'] = "10011110";
    ctos['O'] = "00101";
    ctos['P'] = "111";
    ctos['Q'] = "10011111";
    ctos['R'] = "1000";
    ctos['S'] = "00110";
    ctos['T'] = "00111";
    ctos['U'] = "10011100";
    ctos['V'] = "10011101";
    ctos['W'] = "000010";
    ctos['X'] = "10010010";
    ctos['Y'] = "10010011";
    ctos['Z'] = "10010000";
    rep(i,26){
        string num = "00000";
        rep(j,5) num[j] = (i>>j)&1 ? '1': '0';
        reverse(all(num));
        stoc[num] = char('A'+i);
    }
    stoc["11010"] = ' ';
    stoc["11011"] = '.';
    stoc["11100"] = ',';
    stoc["11101"] = '-';
    stoc["11110"] = '\'';
    stoc["11111"] = '?';
    string str;
    while(getline(cin,str)){
        string tmp = "";
        rep(i,str.size()) tmp += ctos[str[i]];
        while(tmp.size()%5) tmp += "0";
        string ret = "";
        rep(i,tmp.size()/5)
            ret += stoc[tmp.substr(i*5,5)];
        cout << ret << endl;
    }
    return 0;
}
