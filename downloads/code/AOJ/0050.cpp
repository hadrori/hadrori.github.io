#include <bits/stdc++.h>
using namespace std;
int main()
{
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        string s, t;
        getline(cin, s);
        int n = s.size();
        for (int i = 0; i < n; i++) {
                if(n-i < 5) cout << s[i];
                else {
                        t = s.substr(i,5);
                        if(t == "apple") cout << "peach";
                        else if(t == "peach") cout << "apple";
                        else cout << s[i], i-=4;
                        i += 4;
                }
        }
        cout << endl;
        return 0;
}
