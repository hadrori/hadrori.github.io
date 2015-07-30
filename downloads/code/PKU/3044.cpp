#include <cstdio>
#include <stack>

using namespace std;

int N, W;

#include <iostream>
int main(){
    scanf("%d%d", &N, &W);
    stack<int> st;
    int ans = 0;
    for(int i = 0; i < N; i++){
        int x, y; scanf("%d%d", &x, &y);
        if(st.empty()){
            if(y > 0){
                ans++;
                st.push(y);
            }
        }
        else if(y > st.top()){
            st.push(y);
            ans++;
        }
        else if(y < st.top()){
            while(!st.empty() and st.top() > y)
                st.pop();
            if(y > 0 and (st.empty() or st.top() < y)){
                st.push(y);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
