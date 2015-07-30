#include <algorithm>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N;
pii dots[256];

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int x, y; scanf("%d%d", &x, &y);
        dots[i] = pii(x, y);
    }

    set<pii> args;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++){
            int dx = dots[i].first - dots[j].first;
            int dy = dots[i].second - dots[j].second;
            if(dy == 0) args.insert(pii(0,0));
            else if(dx == 0) args.insert(pii(0,1));
            else {
                int g = __gcd(dx, dy);
                dx /= g; dy /= g;
                if(dx < 0){
                    dx *= -1;
                    dy *= -1;
                }
                args.insert(pii(dx, dy));
            }
        }
    printf("%d\n", int(args.size()));
    return 0;
}
