#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
 
struct cube
{
        int p[3];
        cube(int x, int y, int z){
                p[0] = x;
                p[1] = y;
                p[2] = z;
        }
        bool operator<(const cube &c)const{ return p[2] > c.p[2];}
};
 
int n;
pii seq[1<<19];
vector<cube> cs;
set<pii> ps;

void gen_cube()
{
        sort(seq, seq+n);
        int l = 0, r = 0;
        cube c(1,1,1);
        while(r < n) {
                c.p[seq[r].second]++;
                while(l < r and seq[l].first*2 <= seq[r].first) c.p[seq[l++].second]--;
                r++;
                cs.push_back(c);
        }
        cs.push_back(cube(0,0,0));
        sort(begin(cs),end(cs));
}
 
long long solve()
{
        gen_cube();
        ps.insert(pii(0,1000000001));
        ps.insert(pii(1000000001,0));
        long long ans = -1, pz = 0, area = 0;
        for(auto &e: cs) {
                int x = e.p[0], y = e.p[1], z = e.p[2];
                ans += (pz-z)*area;
                pz = z;
                auto lb = ps.lower_bound(pii(x,y)), ub = lb;
                int py = lb->second, px = x;
                if(py >= y) continue;
                while(lb-- != begin(ps)) {
                        int nx = lb->first, ny = lb->second;
                        area += 1LL*(px-nx)*(y-py);
                        if(ny > y) break;
                        py = ny;
                        px = nx;
                }
                ps.erase(++lb,ub);
                ps.insert(ub, pii(x,y));
        }
        
        return ans;
}
 
void input()
{
        cin >> n;
        char c; int x, y;
        for (int i = 0; i < n; i++) {
                cin >> x >> c;
                y = (c == 'R')? 0: (c == 'G')? 1: 2;
                seq[i] = pii(x,y);
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
