#include <bits/stdc++.h>
using namespace std;

int n;
string seq[1024];

void solve()
{
        for (int i = 0; i < n; i++) {
                int j = 0;
                while (j < (int)seq[i].size() and seq[i][j] == '.') {
                        seq[i][j++] = ' ';
                }
                if(!j) continue;
                seq[i][--j] = '+';
                int pi = i-1;
                while(pi >= 0 and j < (int)seq[pi].size() and seq[pi][j] == ' ') {
                        seq[pi--][j] = '|';
                }
        }
        for (int i = 0; i < n; i++) {
                cout << seq[i] << endl;
        }
}

bool input()
{
        cin >> n;
        for (int i = 0; i < n; i++) {
                cin >> seq[i];
        }
        return n;
}

int main()
{
        while(input()) solve();
        return 0;
}
