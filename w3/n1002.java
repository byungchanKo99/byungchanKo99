package w3;

import java.util.Scanner;

public class n1002 {
    static void func(int x1, int y1, int r1, int x2, int y2, int r2){
        int xDis = Math.abs(x1 - x2);
        int yDis = Math.abs(y1 - y2);
        double distance = Math.sqrt(xDis*xDis + yDis*yDis);
        int result;
        if(distance == 0){
            if(r1 == r2){
                result = -1;
            }
            else{result = 0;}
        }
        else if(r1 + r2 == distance){ // 외접
            result = 1;
        }
        else if (r1 + r2 > distance){
            if(r1 == r2 + distance || r2 == r1 + distance){ // 내접
                result = 1;
            }
            else if (r1 > r2 + distance || r2 > r1 + distance){
                result = 0;
            }
            else{
                result = 2;
            }
        }
        else{ // r1 + r2 < distance
            result = 0;
        }
        System.out.println(result);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int count = sc.nextInt();
        int x1, y1, r1, x2, y2, r2;
        for(int i =0; i < count; i++){
            x1= sc.nextInt();
            y1=sc.nextInt();
            r1=sc.nextInt();
            x2=sc.nextInt();
            y2=sc.nextInt();
            r2=sc.nextInt();
            func(x1, y1, r1, x2, y2, r2);

        }

    }
}