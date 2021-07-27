import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class n1110 {
    public static void main(String[] args) throws NumberFormatException, IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int first = num;
        int nextNum = -1;
        int ten, one;
        int temp;
        int count = 0;
        while(true){
            ten = num / 10;
            one = num % 10;
            temp = ten + one;
            nextNum = (one * 10) + (temp %10);
            if(first == nextNum){
                count++;
                break;
                
            }
            num = nextNum;
            count++;
            System.out.println(count);
        }
        System.out.println(count);
    }
}
