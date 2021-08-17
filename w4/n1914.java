package w4;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

// printf랑 println이랑 메모리 차이가 난다.
// pinrtf가 미묘하게 더 씀.
// bufferedwriter 효율 굿.
public class n1914 {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(bf.readLine());
        bf.close();
        BigInteger totalCase = new BigInteger("2");
        System.out.println(totalCase.pow(num).subtract(BigInteger.ONE));
        if(num <= 20){
            hanoi(num, 1, 2, 3);
        }
    }
    static void hanoi(int n, int start, int mid, int end){
        if(n == 1){
            System.out.println(start + " " + end);
            return;
        }
        hanoi(n-1, start, end, mid);
        System.out.println(start + " " + end);
        hanoi(n-1, mid, start, end);
    }


}
