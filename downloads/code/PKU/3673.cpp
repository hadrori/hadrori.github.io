#include <iostream>
#include <string>

using namespace std;
string a, b;

int main(){
    cin >> a >> b;
    int ans = 0;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            ans += int(a[i]-'0') * int(b[j]-'0');
    printf("%d\n", ans);
    return 0;
}
