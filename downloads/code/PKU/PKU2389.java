import java.math.BigInteger;
import java.util.Scanner;

public class POJ2389{
    void solve(){
        Scanner sc = new Scanner(System.in);
        String a = sc.next(), b = sc.next();
        BigInteger A = new BigInteger(a), B = new BigInteger(b);
        System.out.println(A.multiply(B));
    }
}
