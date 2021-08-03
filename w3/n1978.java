package w3;

import java.util.Scanner;

public class n1978 {
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int c = sc.nextInt();
        boolean s = true;
        int r= 0;
        for(int i = 0; i < c; i++){
            int a = sc.nextInt();
            if(a == 1){
                continue;
            }
            if(a == 2 || a == 3){
                r++;
                continue;
            }
            for(int j = (a / 2); j > 1; j--){
                if(a % j == 0){
                    s = false;
                    break;
                }
            }
            if(s){
                r++;
            }
            else{
                s = true;
            }

        }
        System.out.println(r);

    }
}
