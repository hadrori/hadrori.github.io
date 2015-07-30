#include <iostream>

#define rep(i, a, b) for(int i = a; i < b; i++)

using namespace std;

int n;

int main(){
    while(cin >> n, n){
        int cnt = 0, left = 1, right =  2;
        int sum = left + right;
        while(right < n){
            if(sum < n){
                right++;
                sum += right;
            }else if(sum > n){
                sum -= left;
                left++;
            }else{
                cnt++;
                right++;
                sum += right;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
