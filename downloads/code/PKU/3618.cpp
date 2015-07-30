#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

struct dist{
    int x;
    dist(){}
    dist(int x): x(x){}
    bool operator<(const dist &d)const{ return abs(x) < abs(d.x);}
};

int T, N, ans, tmp, pos;
vector<dist> v;

int main(){
    scanf("%d%d", &T,&N);
    v.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i].x);
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++){
        T -= abs(v[i].x-pos);
        pos = v[i].x;
        if(T < 0) break;
        ans++;
    }
    printf("%d\n", ans);
}
