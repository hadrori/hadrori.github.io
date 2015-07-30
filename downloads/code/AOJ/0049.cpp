#include <bits/stdc++.h>
using namespace std;

int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        int _;
        map<string,int> cnt;
        while(cin >> _) {
                char __; cin >> __;
                string s; cin >> s;
                cnt[s]++;
        }
        cout << cnt["A"] << endl;
        cout << cnt["B"] << endl;
        cout << cnt["AB"] << endl;
        cout << cnt["O"] << endl;
        return 0;
}
