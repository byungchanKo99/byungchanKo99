package w2;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class w2_n10818 {
    
    public static void main(String[] args) throws NumberFormatException, IOException{
        int max;
        int min;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        String input = br.readLine();
       
        StringTokenizer st = new StringTokenizer(input); 
        int[] a = new int[num];

        for(int i  = 0; i < a.length; i++){
            a[i] = Integer.parseInt(st.nextToken());;
        }
        max = a[0];
        min = a[0];

        for(int i = 0; i < a.length; i++){
            if(a[i] > max){
                max = a[i];
            }
            else if(a[i] < min){
                min = a[i];
            }
        }
        System.out.printf("%d %d", min, max);
    }
}
