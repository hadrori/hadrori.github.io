#include <iostream>

using namespace std;

int cnt[26];
int maxa;

int main(){
    char c;
    while(~scanf("%c", &c))
        if('A' <= c && c <= 'Z')
            maxa = max(++cnt[c-'A'], maxa);

    for(int i = maxa; i > 0; i--)
        for(int j = 0; j < 26; j++)
            cout << (cnt[j] >= i? '*': ' ') << (j==25? '\n': ' ');

    for(int j = 0; j < 26; j++)
        cout << char(j+'A') << (j==25? '\n': ' ');
    return 0;
}
