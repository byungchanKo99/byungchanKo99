package w3;
import java.io.*;

// sout pln 하니까 시간 초과
// 버퍼라이터 써봤는데 엄청빠르다. static global로 쓰는거 맞으려나
public class n11729 {
    private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(bf.readLine());
        bf.close();
        System.out.println((int) Math.pow(2, num) - 1);
        hanoi(num, 1, 2, 3);
        bw.flush();
        bw.close();

    }
    static void hanoi(int n, int start, int mid, int end) throws IOException {
        if(n == 1){
            bw.write(String.format("%d %d\n", start, end));
            return;
        }
        hanoi(n-1, start, end, mid);
        bw.write(String.format("%d %d\n", start, end));
        hanoi(n-1, mid, start, end);
    }


}

