#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> pdi;
const double pi = acos(-1.);
const double eps = 1e-7;
int n, x[1024], y[1024];
double d;

inline double sq(double a){ return a*a;}
inline double fit(double th){
        while(th < 0) th += 2*pi;
        while(th > 2*pi) th -= 2*pi;
        return th;
}

int solve()
{
        d *= 2;
        int ans = 1;
        for (int i = 0; i < n; i++) {
                vector<pdi> events;
                int sat = 1;
                for (int j = 0; j < n; j++) {
                        if(j == i) continue;
                        const int px = x[j]-x[i], py = y[j]-y[i];
                        const double r = sqrt(sq(px)+sq(py)), th = atan2(py,px), dth = asin(d/r);
                        const double in1 = fit(th-dth-eps), in2 = fit(th+pi-eps),
                                     out1 = fit(th+eps), out2 = fit(th+pi+dth+eps);
                        
                        if(r < d+eps) {
                                events.push_back(pdi(in2,1));
                                events.push_back(pdi(out1,-1));
                        }
                        else {
                                events.push_back(pdi(in1,1));
                                events.push_back(pdi(out1,-1));
                                events.push_back(pdi(in2,1));
                                events.push_back(pdi(out2,-1));
                        }
                        if(0 <= py and py <= d) sat++;
                }
                sort(begin(events),end(events));
                ans = max(ans, sat);
                for(auto &e: events) {
                        sat += e.second;
                        ans = max(ans, sat);
                }
        }

        return ans;
}

void input()
{
        cin >> n >> d;
        for (int i = 0; i < n; i++)
                cin >> x[i] >> y[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
