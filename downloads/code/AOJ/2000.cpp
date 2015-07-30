#include <iostream>
#include <vector>

#define rep(i,a,b) for(int i = a; i < b; i++)

typedef long long ll;

using namespace std;

int n, m;

int main(){

    while( cin >> n, n){
        
        pair< int, int> machine;
        machine = make_pair(10,10);
        
        vector< pair< int, int> > juels;
        rep(i, 0, n){
            int x, y;
            cin >> x >> y;
            juels.push_back(make_pair(x,y));
        }

        cin >> m;
        
        vector< pair< char, int> > commands;
        rep(i, 0, m){
            char d;
            int l;
            cin >> d >> l;
            commands.push_back(make_pair( d, l));
        }
        bool planets[21][21] = {false};
        planets[10][10] = true;
        
        rep(i, 0, m){
            if( commands[i].first == 'N'){
                for( int j = 1; j <= commands[i].second; j++){
                    planets[machine.first][machine.second + j] = true;
                }
                machine.second += commands[i].second;
            }else if( commands[i].first == 'S'){
                for( int j = 1; j <= commands[i].second; j++){
                    planets[machine.first][machine.second - j] = true;
                }
                machine.second -= commands[i].second;
            }else if( commands[i].first == 'E'){
                for( int j = 1; j <= commands[i].second; j++){
                    planets[machine.first + j][machine.second] = true;
                }
                machine.first += commands[i].second;
            }else{
                for( int j = 1; j <= commands[i].second; j++){
                    planets[machine.first - j][machine.second] = true;
                }
                machine.first -= commands[i].second;
            }
        }
        
        int cnt = 0;
        rep(i, 0, n){
            if( planets[juels[i].first][juels[i].second]){
                cnt++;
            }
        }

        if( cnt == n){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}