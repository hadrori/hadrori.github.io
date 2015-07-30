#include <bits/stdc++.h>
using namespace std;

int t, n, a[1<<22];

void right(int &r, deque<int> &lb, deque<int> &ub)
{
        while(!lb.empty() and a[lb.back()]>=a[r]) lb.pop_back();
        while(!ub.empty() and a[ub.back()]<=a[r]) ub.pop_back();
        lb.push_back(r); ub.push_back(r);
        r++;
}

void left(int &l, deque<int> &lb, deque<int> &ub)
{
        if(lb.front() == l) lb.pop_front();
        if(ub.front() == l) ub.pop_front();
        l++;
}

int solve()
{
        deque<int> lb, ub;
        int l = 0, r = 0, ans = 1;
        while(l < n) {
                if(l == r) right(r,lb,ub);
                else if(a[ub.front()]-a[lb.front()] > t) left(l,lb,ub);
                else {
                        ans = max(ans, r-l);
                        if(r == n) break;
                        right(r,lb,ub);
                }
        }
        return ans;
}

void input()
{
        scanf("%d%d", &t, &n);
        for (int i = 0; i < n; i++) scanf("%d", a+i);
}

int main()
{
        input();
        printf("%d\n", solve());
        return 0;
}
