#include <bits/stdc++.h>
using namespace std;

struct segtree
{
        struct node
        {
                int mval, l , r, added;
                node *par, *left, *right;
                node() : mval(0), l(0), r(0), added(0){}
                node(node *p, int l, int r) : mval(0), l(l), r(r), added(0){
                        par = p;
                        left = right = NULL;
                }
        };
        int N;
        node *root;
        map<int,int> vs;

        segtree(){}
        segtree(int n) {
                N = 1;
                while(N < n) N *= 2;
                root = new node(NULL,0,N);
        }

        void update(int a, int b, int x) {
                vs[a] += x;
                if(!vs[a]) vs.erase(a);
                update(a,min(b,N),x,root);
        }
        int update(int a, int b, int x, node *v) {
                if(a >= v->r or b <= v->l) return v->mval;
                if(a <= v->l and v->r <= b) {
                        v->added += x;
                        v->mval += x;
                        return v->mval;
                }
                int m = (v->l+v->r)/2;
                if(v->left == NULL) v->left = new node(v, v->l, m);
                v->mval = update(a,b,x,v->left);
                if(v->right == NULL) v->right = new node(v, m, v->r);
                v->mval = max(v->mval, update(a,b,x,v->right));
                v->mval += v->added;
                return v->mval;
        }

        void query(int x, int b) {
                int r = get_right(x, root);
                if(r < 0) {
                        cout << "NO" << endl;
                        return;
                }
                auto it = vs.upper_bound(r-1);
                it--;
                vector<int> ws;
                while(x--) {
                        while(!it->second) it--;
                        ws.push_back(it->first);
                        it->second--;
                }
                for(int i = (int)ws.size()-1; i >= 0; i--) {
                        cout << ws[i] << (i>0? " ": "");
                        update(ws[i],ws[i]+b+1,-1,root);
                } cout << endl;
        }
        int get_right(int x, node *v) {
                if(v->mval < x) return -1;
                x -= v->added;
                if(v->right != NULL and v->right->mval >= x) return get_right(x, v->right);
                if(v->left != NULL and v->left->mval >= x) return get_right(x, v->left);
                return v->r;
        }
};

int q, b, x;

void solve()
{
        segtree st(1e9);
        char c;
        while(q--) {
                cin >> c;
                if(c == 'E') break;
                cin >> x;
                if(c == 'A') st.update(x,x+b+1,1);
                else st.query(x, b);
        }
}

void input()
{
        cin >> q >> b;
}

int main()
{
        cin.tie(0);
        cin.sync_with_stdio(0);
        input();
        solve();
        return 0;
}
