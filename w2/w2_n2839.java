package w2;
import java.util.Scanner;

public class w2_n2839 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int yes = 0;
        for(int i = 0; i < 5; i++){
            int ksub3 = k - 3*i;
            int kdiv5 =ksub3 / 5;
            if(ksub3 == 0){
                System.out.println(i);
                yes = 1;
                break;
            }
            for(int j = 1; j <= kdiv5; j++){
                if(ksub3 - 5*j == 0){
                    System.out.print(i + j);
                    yes = 1;
                    break;
                } 
            }
        }
        if(yes == 0){
            System.out.println(-1);
        }
        
    }
}

