#include <bits/stdc++.h>
using namespace std;

struct point
{
        int x, y;
        point(){}
        point(int x, int y):x(x),y(y){}
        int msb(const int &k) const {
                int x = -1, y = k;
                while(y) {
                        x = y&-y;
                        y -= x;
                }
                return x;
        }
        bool operator<(const point &p) const {
                int tx = msb(x^p.x), ty = msb(y^p.y);
                if(tx < 0 and ty < 0) return 0;
                int mx = ((x&p.x)&(-1^(tx-1)))|tx, my = ((y&p.y)&(-1^(ty-1)))|ty;
                if(tx > ty) my = ((y&p.y)&(-1^(tx-1)))|tx;
                else mx = ((x&p.x)&(-1^(ty-1)))|ty;
                return (((y>=my)<<1)|(x>=mx)) < (((p.y>=my)<<1)|(p.x>=mx));
        }
};

const string joi = "JOI";
int k, n;
vector<point> ps[3];

int rec(int lv, int lx, int ly)
{
        if(lv == 0) return 0;
        int memo[4][4], d = 1<<(lv-1);
        memset(memo,-1,sizeof(memo));
        const int x[] = {lx, lx+d}, y[] = {ly, ly+d};
        vector<int> fs = {0,1,2,3};
        int ret = -1;
        do {
                int tmp = 0;
                for (int i = 0; i < 4; i++) {
                        int &res = memo[i][fs[i]];
                        if(~res) {
                                tmp += res;
                                continue;
                        }
                        res = 0;
                        if(fs[i] == 3) res = rec(lv-1,x[i%2],y[i/2]);
                        else {
                                for (int j = (fs[i]+1)%3; j != fs[i]; j=(j+1)%3) {
                                        res += upper_bound(begin(ps[j]),end(ps[j]), point(x[i%2]+d-1,y[i/2]+d-1))
                                              -lower_bound(begin(ps[j]),end(ps[j]), point(x[i%2],y[i/2]));
                                }
                        }
                        tmp += res;
                }
                ret = ret<0? tmp: min(ret, tmp);
                if(!ret) return ret;
        } while(next_permutation(begin(fs),end(fs)));
        return ret;
}

int solve()
{
        for (int i = 0; i < 3; i++) sort(begin(ps[i]),end(ps[i]));
        return rec(k,0,0);
}

void input()
{
        cin >> k >> n;
        int x, y; char c;
        for (int i = 0; i < n; i++) {
                cin >> x >> y >> c;
                x--; y--;
                ps[joi.find(c)].push_back(point(x,y));
        }
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
