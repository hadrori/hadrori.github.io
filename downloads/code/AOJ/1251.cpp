#include <bits/stdc++.h>
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,a) repi(i,0,a)
#define pb push_back
using namespace std;

int N, M;
set<string> urls;
set<string> dirs;

void normalize(string &url){
    vector<string> dir;
    string hoge = "";
    rep(i,url.size()){
        if(url[i] == '/'){
            if(hoge == ".."){
                if(dir.size() == 0){
                    url = "";
                    return;
                }
                dir.pop_back();
            }
            else if(hoge != "."){
                if(hoge == "") continue;
                dir.pb(hoge);
                string tmp = "";
                rep(j,dir.size()){
                    tmp += "/";
                    tmp += dir[j];
                }
                if(dirs.find(tmp) == dirs.end()){
                    url = "";
                    return;
                }
            }
            hoge = "";
        }
        else hoge += url[i];
    }
    if(hoge == "..") {
        if(dir.size() == 0){
            url = "";
            return;
        }
        dir.pop_back();
    }
    else if(hoge != "." && hoge != "") dir.pb(hoge);
    url = "";
    rep(i,dir.size()) {
        url += "/";
        url += dir[i];
    }
    if(dirs.find(url) != dirs.end()){
        url += "/index.html";
    }
    if(url == "") url = "/index.html";
    return;
}

int main(){
    int cnt = 0;
    while(cin >> N >> M, N || M){
        urls.clear();
        dirs.clear();
        while(N--){
            string str; cin >> str;
            urls.insert(str);
            string dir = "";
            string hoge = "/";
            repi(i,1,str.size()){
                if(str[i]=='/') {
                    dir += hoge;
                    dirs.insert(dir);
                    hoge = "/";
                }
                else hoge += str[i];
            }
        }
        while(M--){
            string a, b;
            cin >> a >> b;
            normalize(a); normalize(b);
            cerr << "Case " << cnt++ << ": " << a << ' ' << b << endl;
            if(a == "" || b == "" || urls.find(a) == urls.end() || urls.find(b) == urls.end())
                cout << "not found\n";
            else if(a == b) cout << "yes\n";
            else cout << "no\n";
        }
    }
    return 0;
}
