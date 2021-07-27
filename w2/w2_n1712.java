package w2;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class w2_n1712 {
    public static void main(String[] args) throws NumberFormatException, IOException{
        int count = 1;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input); 
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        if(b - c >= 0){
            System.out.println(-1);
        }
        else{
            while(a + ((b - c) * count) >= 0){
                count++;
            }
            System.out.println(count);
        }
        
    }
}
