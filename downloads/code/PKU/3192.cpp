#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int N;
vector<string> dna;

string merge(string a, string b){
    for(int i = min(a.size(), b.size()); i > 0; i--){
        string aa = a.substr(a.size()-i);
        string bb = b.substr(0,i);
        if(aa == bb) return a + b.substr(i);
    }
    return a + b;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        string tmp; cin >> tmp;
        dna.push_back(tmp);
    }
    sort(dna.begin(), dna.end());
    int ans = int(1e9);
    do{
        string seq = dna[0];
        for(int i = 1; i < N; i++)
            seq = merge(seq, dna[i]);
        ans = min(ans, (int)seq.size());
    }while(next_permutation(dna.begin(), dna.end()));

    cout << ans << endl;
    return 0;
}
