#include <bits/stdc++.h>
using namespace std;
struct node
{
        long long val;
        int isl, idx;
        bool operator<(const node &v) const { return val < v.val;}
};

int n, m, ls[1<<20], rs[1<<20]; // [l,r)
long long s[1<<20], a[1<<20];

void merge(int l, int r, int p)
{
        int k = ls[m] = p;
        for (int i = l; i < r; i++) {
                s[k++] = a[i];
                while(k-ls[m] >= 3 and s[k-3] <= s[k-2] and s[k-2] >= s[k-1]) {
                        s[k-3] += s[k-1]-s[k-2];
                        k -= 2;
                }
        }
        rs[m++] = k;
}

long long merge2_left()
{
        int l = ls[0], r = rs[0], f = 0;
        long long val = 0;
        while(l+1 < r and s[l] > s[l+1]) {
                val += s[l+1]-s[l];
                l += 2;
                f = 1;
        }
        if(!f) return 0;
        ls[0] = l;
        return val;
}

long long merge2_right()
{
        int l = ls[m-1], r = rs[m-1], f = 0;
        long long val = 0;
        while(l+1 < r and s[r-1] > s[r-2]) {
                val += s[r-2]-s[r-1];
                r -= 2;
                f = 1;
        }
        if(!f) return 0;
        rs[m-1] = r;
        return val;
}

void solve()
{
        // merge phase
        int l = 0, r = 0, pr = 0;
        long long t = 0;
        priority_queue<node> q;
        while(r < n) {
                l = r;
                while(!a[l] and l < n) l++;
                r = l;
                while(a[r] and r < n) r++;
                if(l < r) {
                        merge(l,r,pr);
                        pr = rs[m-1];
                        // prepare for greedy
                        if(l == 0) { // left stack
                                t += merge2_left();
                                if(rs[0] > ls[0]) q.push((node){s[rs[0]-1], 0, 0});
                                ls[0]--; // guard
                        }
                        else if(r == n) { // right stack
                                t += merge2_right();
                                if(rs[m-1] > ls[m-1]) q.push((node){s[ls[m-1]], 1, m-1});
                                rs[m-1]++; // guard
                        }
                        else { // deque
                                if(rs[m-1] > ls[m-1]) q.push((node){s[ls[m-1]], 1, m-1});
                                if(rs[m-1] > ls[m-1]+1) q.push((node){s[rs[m-1]-1], 0, m-1});
                        }
                }
        }

        // greedy phase
        long long x = 0, sig = 1;
        while(!q.empty()) {
                node v = q.top(); q.pop();
                x += sig*v.val;
                sig *= -1;
                if(v.isl) {
                        ls[v.idx]++;
                        if(rs[v.idx] - ls[v.idx] > 1) q.push((node){s[ls[v.idx]], 1, v.idx});
                }
                else {
                        rs[v.idx]--;
                        if(rs[v.idx] - ls[v.idx] > 1) q.push((node){s[rs[v.idx]-1], 0, v.idx});
                }
        }
        x += sig*t;
        long long y = (accumulate(a,a+n,0)-x)/2;
        printf("%lld %lld\n", x+y, y);
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lld", a+i);
}

int main()
{
        input();
        solve();
        return 0;
}
