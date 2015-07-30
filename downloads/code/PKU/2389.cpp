#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int A[128], B[128];
string a, b;

int main(){    
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
        A[a.size()-i-1] = atoi(a[i]);
    for(int i = 0; i < b.size(); i++)
        B[b.size()-i-1] = atoi(b[i]);
}
