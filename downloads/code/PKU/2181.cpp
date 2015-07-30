#include <algorithm>
#include <cstdio>

using namespace std;

int P, portion[150010];

int main(){
    scanf("%d", &P);
    for(int i = 0; i < P; i++)
        scanf("%d", portion + i);
    portion[P] = 0;
    P++;
    bool plus = 1;
    int ans = 0, prev = 0;
    for(int i = 0; i < P; i++){
        if(plus && prev > portion[i]) {
            ans += prev;
            plus = 0;
        }
        else if(!plus && prev < portion[i]){
            ans -= prev;
            plus = 1;
        }
        prev = portion[i];
    }
    printf("%d\n", ans);
    return 0;
}
