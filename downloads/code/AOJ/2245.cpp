#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
const int INF = 1e9;
string dice[6][3];

int main()
{
    while(1){
        cin >> dice[0][0];
        if(dice[0][0] == "#") break;
        cin >> dice[0][1] >> dice[0][2];
        rep(i,5)rep(j,3) cin >> dice[i+1][j];
        int ans = INF;
        bool exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[0][2][i] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[2][2][i] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 0);
        
        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[0][0][i] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[2][0][i] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 2);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[0][i][0] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[2][i][2] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 1);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[0][i][2] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[2][i][0] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 1);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[1][i][0] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[3][i][2] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 2);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[1][i][2] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[3][i][0] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 2);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[1][0][i] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[3][0][i] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 3);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[1][2][i] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[3][2][i] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 3);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[4][2][i] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[5][0][i] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 1);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[4][0][i] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[5][2][i] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 1);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[4][i][0] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[5][i][0] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 2);

        exist1 = 0, exist2 = 0;
        rep(i,3)if(dice[4][i][2] == '*'){ exist1 = 1; break;}
        rep(i,3)if(dice[5][i][2] == '*'){ exist2 = 1; break;}
        if(exist1 && exist2) ans = min(ans, 2);
        cout << ans << endl;
    }
    return 0;
}
