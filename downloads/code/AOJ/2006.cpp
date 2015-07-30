#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <string>

#define ll long long int

using namespace std;

int main(){
    
    int n;
    string inp[100000];
    string ans[100000];
    
    cin >> n;
    
    for( int i = 0; i < n; i++){
        cin >> inp[i];
    }
    
    for( int i = 0; i < n; i++){
        for( int j = 0; j < inp[i].size(); j++){
            int c = 0;
            int t = inp[i][j] - '0';
            while( inp[i][j] != '0'){
                c++;
                j++;
            }
            if( c != 0){
                switch (t) {
                    case 1:
                        switch (c%5) {
                            case 0:
                                ans[i] += ' ';
                                break;
                            case 1:
                                ans[i] += '.';
                                break;
                            case 2:
                                ans[i] += ',';
                                break;
                            case 3:
                                ans[i] += '!';
                                break;
                            case 4:
                                ans[i] += '?';
                                break;
                        }
                        break;
                    case 2:
                        switch (c%3) {
                            case 0:
                                ans[i] += 'c';
                                break;
                            case 1:
                                ans[i] += 'a';
                                break;
                            case 2:
                                ans[i] += 'b';
                                break;
                        }
                        break;
                    case 3:
                        switch (c%3) {
                            case 0:
                                ans[i] += 'f';
                                break;
                            case 1:
                                ans[i] += 'd';
                                break;
                            case 2:
                                ans[i] += 'e';
                                break;
                        }
                        break;
                    case 4:
                        switch (c%3) {
                            case 0:
                                ans[i] += 'i';
                                break;
                            case 1:
                                ans[i] += 'g';
                                break;
                            case 2:
                                ans[i] += 'h';
                                break;
                        }
                        break;
                    case 5:
                        switch (c%3) {
                            case 0:
                                ans[i] += 'l';
                                break;
                            case 1:
                                ans[i] += 'j';
                                break;
                            case 2:
                                ans[i] += 'k';
                                break;
                        }
                        break;
                    case 6:
                        switch (c%3) {
                            case 0:
                                ans[i] += 'o';
                                break;
                            case 1:
                                ans[i] += 'm';
                                break;
                            case 2:
                                ans[i] += 'n';
                                break;
                        }
                        break;
                    case 7:
                        switch (c%4) {
                            case 0:
                                ans[i] += 's';
                                break;
                            case 1:
                                ans[i] += 'p';
                                break;
                            case 2:
                                ans[i] += 'q';
                                break;
                            case 3:
                                ans[i] += 'r';
                                break;
                        }
                        break;
                    case 8:
                        switch (c%3) {
                            case 0:
                                ans[i] += 'v';
                                break;
                            case 1:
                                ans[i] += 't';
                                break;
                            case 2:
                                ans[i] += 'u';
                                break;
                        }
                        break;
                    case 9:
                        switch (c%4) {
                            case 0:
                                ans[i] += 'z';
                                break;
                            case 1:
                                ans[i] += 'w';
                                break;
                            case 2:
                                ans[i] += 'x';
                                break;
                            case 3:
                                ans[i] += 'y';
                                break;
                        }
                        break;
                }
            }
        }
    }
    
    for( int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}