#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    
    double a, b, c, d, e, f;
    double ans[1000][2] = {0};
    int cnt = 0;
    
    while(!cin.eof()){
        cin >> a >> b >> c >> d >> e >> f;
        ans[cnt][0] = ( c * e - b * f) / ( a * e - b * d);
        ans[cnt][1] = ( a * f - c * d) / ( a * e - b * d);
        ans[cnt][0] = (int)(ans[cnt][0] * 1000);
        ans[cnt][1] = (int)(ans[cnt][1] * 1000);
        ans[cnt][0] = round(ans[cnt][0]) / 1000;
        ans[cnt][1] = round(ans[cnt][1]) / 1000;
        cnt++;
    }
    for( int i = 0; i < cnt - 1; i++){
        cout << setprecision(3);
        cout << setiosflags(ios::fixed);
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    return 0;
}