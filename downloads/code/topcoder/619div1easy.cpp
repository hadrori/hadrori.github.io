
class SplitStoneGame {
public:
    string win = "WIN", lose = "LOSE";
    string winOrLose( vector <int> number ) {
        int cnt = 0, n = number.size();
        rep(i,n) if(number[i] > 1) cnt++;
        if(cnt == 0 or n < 3) return lose;
        if(n%2) return win;
        return lose;
    }
};
