#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const string dna = "aATGC";

struct PMA
{
        PMA* next[5];
        int matched;
        PMA(){ memset(next, 0, sizeof(next)); matched = -1;}
        ~PMA(){ for(int i = 0; i < 256; i++) if(next[i]) delete next[i];}
};

PMA *buildPMA(vector<string> &pattern)
{
        PMA *root = new PMA, *now;
        root->next[0] = root;
        int i = 0;
        for(string pat: pattern) {
                now = root;
                for(char c: pat) {
                        int p = dna.find(c);
                        if(now->next[p] == 0)
                                now->next[p] = new PMA;
                        now = now->next[p];
                }
                int &mt = now->matched;
                if(mt < 0 or pattern[mt].size() < pat.size()) mt = i;
                i++;
        }

        queue<PMA*> que;
        for(i = 1; i < 5; i++){
                if(!root->next[i]) root->next[i] = root;
                else {
                        root->next[i]->next[0] = root;
                        que.push(root->next[i]);
                }
        }
        while(!que.empty()){
                now = que.front(); que.pop();
                for(i = 1; i < 5; i++){
                        if(now->next[i]){
                                PMA *nxt = now->next[0];
                                while(!nxt->next[i]) nxt = nxt->next[0];
                                now->next[i]->next[0] = nxt->next[i];
                                int &mt1 = now->next[i]->matched, &mt2 = nxt->next[i]->matched;
                                if(mt1 < 0 or (~mt2 and pattern[mt1].size() < pattern[mt2].size())) mt1 = mt2;
                                que.push(now->next[i]);
                        }
                }
        }
        return root;
}

int n, m, dp[150010];
string s;
vector<string> pat;

int solve()
{
        m = s.size();
        PMA* pma = buildPMA(pat);
        fill(dp,dp+m,inf);
        dp[0] = 0;
        for(int i = 0; i < m; i++){
                int c = dna.find(s[i]);
                while(!pma->next[c]) pma = pma->next[0];
                pma = pma->next[c];
                if(~pma->matched)
                        for (int j = 1; j < (int)pat[pma->matched].size(); j++)
                                dp[i] = min(dp[i], dp[i-j]+1);
        }
        return dp[m-1];
}

void input()
{
        cin >> n >> s;
        pat.resize(n);
        for (int i = 0; i < n; i++) cin >> pat[i];
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        cout << solve() << endl;
        return 0;
}
