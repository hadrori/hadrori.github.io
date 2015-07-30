#include <bits/stdc++.h>
using namespace std;
 
const int inf = INT_MAX;
int dat[1<<23];
struct segtree
{
        int H, W;
        segtree(){}
        segtree(int h, int w, int f[]) {
                H = W = 1;
                while(H < h) H <<= 1;
                while(W < w) W <<= 1;
                for (int i = 0; i < 1<<21; i++) dat[i] = inf;
                init(h,w,f);
        }
        void init(int h, int w, int f[])
        {
                for (int i = 0; i < h; i++)
                        for (int j = 0; j < w; j++)
                                dat[(i+H-1)*(2*W-1)+j+W-1] = f[i*w+j];
                for (int i = 2*H-2; i > H-2; i--)
                        for (int j = W-2; j >= 0; j--)
                                dat[i*(2*W-1)+j] = min(dat[i*(2*W-1)+2*j+1], dat[i*(2*W-1)+2*j+2]);
                for (int i = H-2; i >= 0; i--)
                        for (int j = 0; j < 2*W-1; j++)
                                dat[i*(2*W-1)+j] = min(dat[(2*i+1)*(2*W-1)+j], dat[(2*i+2)*(2*W-1)+j]);
        }
        int minimum(int li, int lj, int ri, int rj) { return minimum_h(li,lj,ri,rj,0,H,0);}
        int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
                if(ri <= si or ti <= li) return inf;
                if(li <= si and ti <= ri) return minimum_w(lj,rj,0,W,k,0);
                const int mi = (si+ti)/2;
                return min(minimum_h(li,lj,ri,rj,si,mi,2*k+1), minimum_h(li,lj,ri,rj,mi,ti,2*k+2));
        }
        int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
                if(rj <= sj or tj <= lj) return inf;
                if(lj <= sj and tj <= rj) return dat[i*(2*W-1)+k];
                const int mj = (sj+tj)/2;
                return min(minimum_w(lj,rj,sj,mj,i,2*k+1),minimum_w(lj,rj,mj,tj,i,2*k+2));
        }
};
// struct segtree
// {
//         int H, W;
//         vector<vector<int>> dat;
//         segtree(){}
//         segtree(int h, int w, int f[]) {
//                 H = W = 1;
//                 while(H < h) H <<= 1;
//                 while(W < w) W <<= 1;
//                 dat.assign(2*H-1,vector<int>(2*W-1,inf));
//                 init(h,w,f);
//         }
//         void init(int h, int w, int f[])
//         {
//                 for (int i = 0; i < h; i++)
//                         for (int j = 0; j < w; j++)
//                                 dat[i+H-1][j+W-1] = f[i*w+j];
//                 for (int i = 2*H-2; i > H-2; i--)
//                         for (int j = W-2; j >= 0; j--)
//                                 dat[i][j] = min(dat[i][2*j+1], dat[i][2*j+2]);
//                 for (int i = H-2; i >= 0; i--)
//                         for (int j = 0; j < 2*W-1; j++)
//                                 dat[i][j] = min(dat[2*i+1][j], dat[2*i+2][j]);
//         }
//         int minimum(int li, int lj, int ri, int rj) { return minimum_h(li,lj,ri,rj,0,H,0);}
//         int minimum_h(int li, int lj, int ri, int rj, int si, int ti, int k) {
//                 if(ri <= si or ti <= li) return inf;
//                 if(li <= si and ti <= ri) return minimum_w(lj,rj,0,W,k,0);
//                 const int mi = (si+ti)/2;
//                 return min(minimum_h(li,lj,ri,rj,si,mi,2*k+1), minimum_h(li,lj,ri,rj,mi,ti,2*k+2));
//         }
//         int minimum_w(int lj, int rj, int sj, int tj, int i, int k) {
//                 if(rj <= sj or tj <= lj) return inf;
//                 if(lj <= sj and tj <= rj) return dat[i][k];
//                 const int mj = (sj+tj)/2;
//                 return min(minimum_w(lj,rj,sj,mj,i,2*k+1),minimum_w(lj,rj,mj,tj,i,2*k+2));
//         }
// };
 
int r, c, q, f[1<<20], li, lj, ri, rj;
segtree st;
 
void solve()
{
        st = segtree(r,c,f);
        for (int i = 0; i < q; i++) {
                scanf("%d%d%d%d", &li, &lj, &ri, &rj);
                printf("%d\n", st.minimum(li,lj,ri+1,rj+1));
        }
}
 
bool input()
{
        scanf("%d%d%d", &r, &c, &q);
        for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                        scanf("%d", f+i*c+j);
        return r or c or q;
}
 
int main()
{
        while(input()) solve();
        return 0;
}