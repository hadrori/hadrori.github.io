#include <bits/stdc++.h>
using namespace std;
bool isValid(int value, int N)
{
    bool last = false;
    for (int shift = 0; shift < N; ++shift) {
        if (last && (value & (1 << shift)) != 0) {
            return false;
        }
        last = (value & (1 << shift)) != 0;
    }
    return true;
}

static const int MOD = 100000000;

int main()
{
    int M, N;
    cin >> M >> N;

    vector<int> patterns;
    for (int i = 0; i < (1 << N); ++i) {
        if (isValid(i, N)) {
            patterns.push_back(i);
        }
    }

    vector<int> dp(patterns.size());
    dp[0] = 1;
    for (int m = 0; m < M; ++m) {
        int mask = 0;
        for (int n = 0; n < N; ++n) {
            int in;
            cin >> in;
            mask |= ((1 - in) << n);
        }

        vector<int> dp2(patterns.size());
        for (int from = 0; from < patterns.size(); ++from) {
            if (!dp[from]) {
                continue;
            }
            for (int to = 0; to < patterns.size(); ++to) {
                if ((patterns[from] & patterns[to]) != 0 || (mask & patterns[to]) != 0) {
                    continue;
                }
                dp2[to] += dp[from];
                dp2[to] %= MOD;
            }
        }

        swap(dp, dp2);
    }

    int answer = 0;
    for (vector<int>::iterator it = dp.begin(); it != dp.end(); ++it) {
        answer += *it;
        answer %= MOD;
    }

    cout << answer << endl;
}
