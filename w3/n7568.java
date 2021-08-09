package w3;

import java.util.Scanner;

public class n7568 {
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int c = sc.nextInt();
        int[] h = new int[c];
        int[] w = new int[c];
        int[] r = new int[c];
        for(int i = 0; i < c; i++){
            h[i] = sc.nextInt();// 키
            w[i] = sc.nextInt();// 몸무게
            r[i] = 1;// 순위
        }
        for(int i = 0; i < c; i++){ // i번째부터 등수 매기기
            for(int j = 0; j < c; j++ ){ // 전체 순회
                if(h[j] > h[i] && w[j] > w[i]){
                    r[i]++;
                }
            }
            System.out.printf("%d ", r[i]);
        }
    }
}
