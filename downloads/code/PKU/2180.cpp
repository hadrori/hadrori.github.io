#include <cstdio>
#include <cstring>

using namespace std;

struct cube{
    int x, y, z;
    cube(){}
};

int N;
cube bales[25010]; // 0 is ground
int field[64][64][64];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};


inline int getdir(char c){
    if(c == 'F') return 0;
    if(c == 'B') return 1;
    if(c == 'R') return 2;
    if(c == 'L') return 3;
    if(c == 'O') return 4;
    if(c == 'U') return 5;
}

inline void getpos(int &x, int &y, int &z, int id, int d){
    x = bales[id].x + dx[d];
    y = bales[id].y + dy[d];
    z = bales[id].z + dz[d];
}
int solve(){
    scanf("%d", &N);
    memset(bales, -1, sizeof(bales));
    memset(field, -1, sizeof(field));
    bales[1].x = bales[1].y = 32;
    bales[1].z = 0;
    field[32][32][0] = 1;

    int area = 5;
    for(int i = 2; i <= N; i++){
        int id; char c;
        scanf("%d %c", &id, &c);

        int d = getdir(c);
        int x, y, z; getpos(x, y, z, id, d);
        bales[i].x = x; bales[i].y = y; bales[i].z = z;
        if(z < 0 || field[x][y][z] >= 0) return -1;
        field[x][y][z] = i;

        area += 6;
        for(int j = 0; j < 5; j++)
            if(field[x+dx[j]][y+dy[j]][z+dz[j]] >= 0) area -= 2;
        if(z == 0) area--;
        else if(field[x][y][z-1] >= 0) area -= 2;
    }
    return area;
}

int main(){
    printf("%d\n", solve());
    return 0;
}
