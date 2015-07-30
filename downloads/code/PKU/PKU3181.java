import java.math.BigInteger;
import java.util.Scanner;

public class POJ3181{

    void solve(){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(), K = sc.nextInt();
        BigInteger dp[][] = new BigInteger[K+1][N+1];
        for(int j = 0; j <= N; j++) dp[0][j] = new BigInteger("0");
        dp[0][0] = new BigInteger("1");
        for(int i = 1; i <= K; i++){
            for(int j = 0; j <= N; j++) dp[i][j] = new BigInteger("0");
            for(int k = 0; k <= N; k += i)
                for(int j = N; j >= k; j--)
                    dp[i][j] = dp[i][j].add(dp[i-1][j-k]);
        }
        System.out.println(dp[K][N]);
    }

    public static void main(String[] args){
        new POJ3181().solve();
    }
}
