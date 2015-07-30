#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 15000000, BOUND = 14000000;
template<class T> class prbtree
{
public:
        enum COL { BLACK, RED,};
        struct node
        {
                T val;
                int color;
                int rnk, size;
                node *left, *right;
 
                node(){}
                node(T v) : val(v), color(BLACK), rnk(0), size(1)
                {
                        left = right = NULL;
                }
                node(node *l, node *r, int c) : color(c)
                {
                        left = l;
                        right = r;
                        rnk = max((l? l->rnk+(l->color==BLACK): 0),(r? r->rnk+(r->color==BLACK): 0));
                        size = !l and !r? 1: !l? r->size: !r? r->size: l->size+r->size;
                }
        };
 
        node *root;
        node nodes[MAX];
        int called;
 
        prbtree()
        {
                root = NULL;
                called = 0;
        }
 
        prbtree(T val)
        {
                called = 0;
                root = new_node(val);
        }
 
        node *new_node(T v) { return &(nodes[called++] = node(v));}
        node *new_node(node *l, node *r, int c) { return &(nodes[called++] = node(l,r,c));}
 
        node *build(const vector<T> &vs)
        {
                if(!vs.size()) return NULL;
                if((int)vs.size() == 1) return new_node(vs[0]);
                int m = vs.size()/2;
                return merge(build(vector<T>(begin(vs),begin(vs)+m)), build(vector<T>(begin(vs)+m,end(vs))));
        }
 
        int size() { return root->size;}
        void clear()
        {
                called = 0;
                root = NULL;
        }
 
        void print() { print(root,0,0);}
        void print(node *v, int dep, int lr)
        {
                if(!v) return;
                print(v->right,dep+1,1);
                for(int i = 0; i < dep; i++) cerr << "  ";
                if(!lr) cerr << "--";
                else if(lr == 1) cerr << "「";
                else cerr << "Ｌ";
                if(v->color == RED) cerr << "\x1b[31m";
                if(!v->left and !v->right) cerr << v->val << endl;
                else cerr << "nd" << endl;
                cerr << "\x1b[0m";
                print(v->left,dep+1,2);
        }
 
        void get(vector<T> &vs) { get(root,vs);}
        void get(node *v, vector<T> &vs)
        {
                if(!v->left and !v->right) vs.push_back(v->val);
                else {
                        if(v->left) get(v->left,vs);
                        if(v->right) get(v->right,vs);
                }
        }
 
        node *add(T val)
        {
                node *v = new_node(val);
                return root = merge(root,v);
        }
        node *merge(node *u, node *v)
        {
                if(!u) return v;
                if(!v) return u;
                u = merge_sub(u,v);
                if(u->color == RED) return new_node(u->left,u->right,BLACK);
                return u;
        }
 
        node *merge_sub(node *u, node *v)
        {
                if(u->rnk < v->rnk) {
                        node *w = merge_sub(u,v->left);
                        if(v->color == BLACK and w->color == RED and w->left->color == RED){
                                if(v->right->color == BLACK)  return new_node(w->left,new_node(w->right,v->right,RED),BLACK);
                                else return new_node(new_node(w->left,w->right,BLACK),new_node(v->right->left,v->right->right,BLACK),RED);
                        }
                        else return new_node(w,v->right,v->color);
                }
                else if(u->rnk > v->rnk) {
                        node *w = merge_sub(u->right,v);
                        if(u->color == BLACK and w->color == RED and w->right->color == RED){
                                if(u->left->color == BLACK)  return new_node(new_node(u->left,w->left,RED),w->right,BLACK);
                                else return new_node(new_node(u->left->left,u->left->right,BLACK),new_node(w->left,w->right,BLACK),RED);
                        }
                        else return new_node(u->left,w,u->color);
                }
                else return new_node(u,v,RED);
        }
 
        pair<node*,node*> split(node *v, int k)
        {
                if(!k) return pair<node*,node*>(NULL,v);
                if(k == v->size) return pair<node*,node*>(v,NULL);
                if(k < v->left->size) {
                        auto p = split(v->left,k);
                        return pair<node*,node*>(p.first,merge(p.second,v->right));
                }
                else if(k > v->left->size) {
                        auto p = split(v->right,k-v->left->size);
                        return pair<node*,node*>(merge(v->left,p.first),p.second);
                }
                else return pair<node*,node*>(v->left,v->right);
        }
        // copy [l,r)
        node *copy(int l, int r)
        {
                return split(split(root, l).second, r-l).first;
        }
 
        // insert tree v at k
        node *insert(node *v, int k)
        {
                auto p = split(root,k);
                return root = merge(merge(p.first,v),p.second);
        }
 
        node *copy_paste(int l, int r, int k)
        {
                return insert(copy(l,r),k);
        }
};
 
int n, m, l, r, k, len;
prbtree<char> t;
char line[1000010];
 
void build_tree(vector<char> &vc)
{
        t.clear();
        t.root = t.build(vc);
}
 
void solve()
{
        vector<char> vc;
        for (int i = 0; i < len; i++) vc.push_back(line[i]);
        build_tree(vc);
        vc.clear();
        while(n--) {
                scanf("%d%d%d", &l, &r, &k);
                t.copy_paste(l,r,k);
                if(t.size() > m) t.root = t.split(t.root,m).first;
                if(t.called > BOUND) {
                        t.get(vc);
                        build_tree(vc);
                        vc.clear();
                }
        }
        t.get(vc);
        for(auto &c: vc) printf("%c", c); puts("");
}
 
void input()
{
        scanf("%d\n", &m);
        fgets(line,sizeof(line),stdin);
        len = strlen(line);
        while(len > 0 and line[len-1]=='\n') len--;
        scanf("%d", &n);
}
 
int main()
{
        input();
        solve();
        return 0;
}