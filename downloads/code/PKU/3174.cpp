#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>

using namespace std;
typedef pair<int,int> pii;
struct points{
    int x, y, z;
    points(int x, int y, int z):x(x),y(y),z(z){}
};

struct frac{
    int num, den;
    frac(int num, int den):num(num),den(den){}
    bool operator==(const frac &f) const{
        return num * f.den == den * f.num;
    }
};

int N;
pii p[1024];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d%d", &p[i].first, &p[i].second);

    vector<points> ans;

    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++)
            for(int k = j+1; k < N; k++){
                frac a = frac(p[j].second-p[i].second, p[j].first-p[i].first);
                frac b = frac(p[k].second-p[i].second, p[k].first-p[i].first);
                if(a == b) ans.push_back(points(i+1,j+1,k+1));
            }
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++)
        printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
    return 0;
}
