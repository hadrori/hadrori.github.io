#include "grader.h"
#include "salt.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

void remove(int u, int v, vector<pii> &E, vector<int> &V)
{
        vector<pii> F;
        if(u == v) {
                for (__typeof(V.begin()) it = V.begin(); it != V.end(); it++) {
                        if(*it == u) {
                                V.erase(it,it+1);
                                break;
                        }
                }
                for(__typeof(E.begin()) it = E.begin(); it != E.end(); it++)
                        if(it->first != u and it->second != v) F.push_back(*it);
        }
        else {
                for(__typeof(E.begin()) it = E.begin(); it != E.end(); it++)
                        if(it->first != u or it->second != v) F.push_back(*it);
        }
        swap(E, F);
}

pii solve(vector<pii> &E, vector<int> &V)
{
        int es = E.size(), vs = V.size();
        if(es%2 and vs%2==0) return E[0];
        else {
                int cnt[1024] = {};
                for(__typeof(E.begin()) it = E.begin(); it != E.end(); it++){
                        cnt[it->first]++;
                        cnt[it->second]++;
                }
                for (__typeof(V.begin()) it = V.begin(); it != V.end(); it++)
                                if(cnt[*it]%2==es%2) return pii(*it,*it);
        }
        return pii(0,0);
}

void play(int N, int F[][2]) {
        vector<int> V;
        vector<pii> E;
        for (int i = 0; i < N; i++){
                if(i < N-1) E.push_back(pii(F[i][0]-1, F[i][1]-1));
                V.push_back(i);
        }
        while(true) {
                int ru, rv;
                pii rm = solve(E, V);
                remove(rm.first, rm.second, E, V);
                turn(rm.first+1, rm.second+1, &ru, &rv);
                if(!ru and !rv) return;
                ru--; rv--;
                remove(ru, rv, E, V);
        }
}
