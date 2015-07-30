#include <iostream>
#include <string>

#define rep(i, b) for(int i = 0; i < b; i++)

using namespace std;

int main(){
    int n;
    cin >> n;
    rep(z,n){
        string mcxi[2];
        int num[2] = {0};
        
        cin >> mcxi[0] >> mcxi[1];
        
        rep(k,2){
            rep(i,mcxi[k].size()){
                if((mcxi[k][i] > '0') && (mcxi[k][i] <= '9')){
                    if(mcxi[k][i+1] == 'm'){
                        num[k] += (mcxi[k][i] - '0') * 1000;
                    }else if(mcxi[k][i+1] == 'c'){
                        num[k] += (mcxi[k][i] - '0') * 100;
                    }else if(mcxi[k][i+1] == 'x'){
                        num[k] += (mcxi[k][i] - '0') * 10;
                    }else if(mcxi[k][i+1] == 'i'){
                        num[k] += (mcxi[k][i] - '0');
                    }
                    i++;
                }else{
                    if(mcxi[k][i] == 'm'){
                        num[k] += 1000;
                    }else if(mcxi[k][i] == 'c'){
                        num[k] += 100;
                    }else if(mcxi[k][i] == 'x'){
                        num[k] += 10;
                    }else if(mcxi[k][i] == 'i'){
                        num[k] += 1;
                    }
                }
            }
        }
        int ans = num[0] + num[1];
        
        string sum = "";
        int k = 0;
        while(ans > 0){
            if( ans / 1000){
                if( ans / 1000 > 1){
                    sum.insert(k+sum.begin(),ans/1000 + '0');
                    k++;
                }
                sum.insert(k+sum.begin(),'m');
                k++;
                ans %= 1000;
            }else if( ans / 100){
                if( ans / 100 > 1){
                    sum.insert(k+sum.begin(),ans/100 + '0');
                    k++;
                }
                sum.insert(k+sum.begin(),'c');
                k++;
                ans %= 100;
            }else if( ans / 10){
                if( ans / 10 > 1){
                    sum.insert(k+sum.begin(),ans/10 + '0');
                    k++;
                }
                sum.insert(k+sum.begin(),'x');
                k++;
                ans %= 10;
            }else if( ans){
                if( ans > 1){
                    sum.insert(k+sum.begin(),ans + '0');
                    k++;
                }
                sum.insert(k+sum.begin(),'i');
                k++;
                ans %= 1;
            }
        }
        cout << sum << endl;
    }
}
