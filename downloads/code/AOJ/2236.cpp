#include <bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N = 40010;

int n, h[N], a[N], d[N], s[N], id[N];

inline i64 attack(int i) { return (h[i]+a[0]-d[i]-1)/(a[0]-d[i]);}
inline i64 damage(int i) { return max(0, a[i]-d[0]);}

bool cmp(int i, int j)
{
        const i64 Ai = attack(i), Aj = attack(j);
        const i64 Di = Ai*damage(j), Dj = Aj*damage(i);
        return Di < Dj;
}

int solve()
{
        int m = 0;
        for (int i = 1; i <= n; i++) {
                if(a[0] <= d[i] and a[i] > d[0]) return -1;
                if(a[0] > d[i]) id[m++] = i;
        }
        sort(id,id+m,cmp);
        i64 turn = 0, sum = 0;
        for (int i = 0; i < m; i++) {
                i64 atk = attack(id[i]), dmg = damage(id[i]);
                sum += (turn+atk)*dmg;
                if(s[id[i]] < s[0]) sum -= dmg;
                if(h[0] <= sum) return -1;
                turn += atk;
        }
        return sum;
}

void input()
{
        scanf("%d", &n);
        for (int i = 0; i <= n; i++) scanf("%d%d%d%d", h+i, a+i, d+i, s+i);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
