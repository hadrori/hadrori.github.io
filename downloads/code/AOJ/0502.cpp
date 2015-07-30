#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int n;
    int ans[10000] = {0};
    
    cin >> n;
    int t = 0;
    
    while( n != 0){
        int nums[3];
        ans[t]++;
        nums[0] = 1;
        nums[1] = 2;
        nums[2] = 3;
        for( int i = 0; i < n; i++){
            string command;
            cin >> command;
            if( command == "North"){
                int tmp = nums[0];
                nums[0] = nums[1];
                nums[1] = 7 - tmp;
            }else if( command == "East"){
                int tmp = nums[2];
                nums[2] = nums[0];
                nums[0] = 7 - tmp;
            }else if( command == "West"){
                int tmp = nums[0];
                nums[0] = nums[2];
                nums[2] = 7 - tmp;
            }else if( command == "South"){
                int tmp = nums[1];
                nums[1] = nums[0];
                nums[0] = 7 - tmp;
            }else if( command == "Right"){
                int tmp = nums[1];
                nums[1] = nums[2];
                nums[2] = 7 - tmp;
            }else if( command == "Left"){
                int tmp = nums[2];
                nums[2] = nums[1];
                nums[1] = 7 - tmp;
            }
            ans[t] += nums[0];
        }
        t++;
        cin >> n;
    }
    
    for( int i = 0; i < t; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}



