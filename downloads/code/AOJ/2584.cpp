#include <bits/stdc++.h>
using namespace std;

const string f = "-.+";
string seq, ans;
int n, cur;


char genc()
{
        int pm = 0, p;
        while((p = f.find(seq[cur])) >= 0) {
                pm += p-1;
                cur++;
        }
        char c = seq[cur];
        if(c == '?') return 'A';
        return ((c-'A'+pm)%26+26)%26+'A';
}

string gens(int rev)
{
        string ret = "";
        for (++cur; cur < n; cur++) {
                char &c = seq[cur];
                if(rev and c == ']') break;
                if(c == '[') ret += gens(1);
                else ret.push_back(genc());
        }
        if(rev) reverse(begin(ret),end(ret));
        return ret;
}

string solve()
{
        n = seq.size();
        ans = "";
        cur = -1;
        return gens(0);
}

bool input()
{
        cin >> seq;
        return seq!=".";
}

int main()
{
        while(input()) cout << solve() << endl;
        return 0;
}
