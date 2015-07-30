#include <bits/stdc++.h>
using namespace std;

struct event
{
        int u, v;
        double t;
        event(int u, int v, double t):u(u),v(v),t(t){}
        bool operator<(const event &e) const { return t < e.t;}
};

struct star
{
        double x, y, z, vx, vy, vz, r, vr;
};

int n;
vector<event> events;
vector<star> stars;
double die[256];

inline bool valid(double a, double b, double c){ return b*b-a*c+1e-8 > 0;}

double collide_time(const star &s, const star &t)
{
        double x = s.x-t.x, y = s.y-t.y, z = s.z-t.z, r = s.r+t.r;
        double vx = s.vx-t.vx, vy = s.vy-t.vy, vz = s.vz-t.vz, vr = s.vr+t.vr;
        double a = vx*vx+vy*vy+vz*vz-vr*vr;
        double b = x*vx+y*vy+z*vz+r*vr;
        double c = x*x+y*y+z*z-r*r;
        if(!valid(a,b,c)) return -1;
        
        double p[] = {(-b+sqrt(b*b-a*c))/a, (-b-sqrt(b*b-a*c))/a}, ret = 1e9;
        int f = 0;
        for (int i = 0; i < 2; i++) {
                if(p[i]*s.vr < s.r and p[i]*t.vr < t.r and p[i] > 0) {
                        ret = min(ret, p[i]);
                        f = 1;
                }
        }
        return f? ret: -1;
}

void solve()
{
        for (int i = 0; i < n; i++) {
                star &s = stars[i];
                events.push_back(event(i,i,s.r/s.vr));
                for (int j = i+1; j < n; j++) {
                        double t = collide_time(s, stars[j]);
                        if(t > 0) events.push_back(event(i,j,t));
                }
        }
        sort(begin(events),end(events));

        for(auto &e: events) {
                if(die[e.u] < 0 and die[e.v] < 0){
                        die[e.u] = die[e.v] = e.t;
                }
        }
        for (int i = 0; i < n; i++) {
                printf("%.12f\n", die[i]);
        }
}

void init()
{
        for (int i = 0; i < n; i++) {
                die[i] = -1;
        }
        events.clear();
        stars.clear();
}

bool input()
{
        cin >> n;
        init();
        for (int i = 0; i < n; i++) {
                double x, y, z, vx, vy, vz, r, vr;
                cin >> x >> y >> z >> vx >> vy >> vz >> r >> vr;
                stars.push_back((star){x,y,z,vx,vy,vz,r,vr});
        }
        return n;
}

int main()
{
        while(input()) solve();
        return 0;
}
