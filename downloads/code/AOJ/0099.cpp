#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)

int n, q;

int main(){
    
    cin >> n >> q;
    vector<int> data(n+1);
    rep(i, 0, n+1) data[i] = 0;
    
    data[0] = -1;
    int maxv = 0;
    int maxa = 0;
    rep(i, 0, q){
        int a, v;
        cin >> a >> v;
        data[a] += v;
        if(a == maxa) {
            maxv += v;
            if(v < 0){
                vector<int>::iterator itr = max_element(data.begin(),data.end());
                maxa = itr - data.begin();
                maxv = data[maxa];
            }
        }
        
        if(data[a] >= maxv){
            if(maxv == data[a]){
                if(a < maxa) maxa = a;
            }else{
                maxv = data[a];
                maxa = a;
            }
        }
        cout << maxa << ' ' << maxv << endl;
    }
}