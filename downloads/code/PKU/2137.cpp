#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <vector>

using namespace std;

typedef complex<double> point;

const double inf = 1e6;

int N;
vector<point> p[128];
double dp[128][64];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int n; scanf("%d", &n);
        for(int j = 0; j < n; j++){
            double x, y;
            scanf("%lf%lf", &x, &y);
            p[i].push_back(point(x,y));
        }
    }

    int ans = int(inf*100);
    for(int s = 0; s < p[0].size(); s++){
        for(int i = 0; i <= N; i++)
            for(int j = 0; j < 64; j++)
                dp[i][j] = inf;
        for(int i = 0; i < p[1].size(); i++)
            dp[1][i] = abs(p[0][s] - p[1][i]);
        for(int i = 2; i < N; i++)
            for(int j = 0; j < p[i].size(); j++){
                if(!i) dp[i][j] = 0;
                else for(int k = 0; k < p[i-1].size(); k++)
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(p[i][j]-p[i-1][k]));
            }
        for(int i = 0; i < p[N-1].size(); i++)
            ans = min(ans, int(100*(dp[N-1][i]+abs(p[0][s] - p[N-1][i]))));
    }
    printf("%d\n", ans);
    return 0;
}
