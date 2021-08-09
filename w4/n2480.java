package w4;

import java.util.*;

public class n2480 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] dice = new int[3];
        int prize;
        dice[0] = sc.nextInt();
        dice[1] = sc.nextInt();
        dice[2] = sc.nextInt();
        if(dice[0] == dice[1] && dice[0] == dice[2] && dice[1] == dice[2]){
            prize = 10000 + dice[0] * 1000;
        }
        else if(dice[0] == dice[1]){
            prize = 1000 + dice[0] * 100;
        }
        else if(dice[0] == dice[2]){
            prize = 1000 + dice[0] * 100;
        }
        else if(dice[1] == dice[2]){
            prize = 1000 + dice[1] * 100;
        }
        else{
            int a = Math.max(dice[0], dice[1]);
            prize = Math.max(a, dice[2]) * 100;
        }
        System.out.println(prize);
    }
}