package w2;

import java.util.Arrays;

public class w2_n4673 {
    public static void main(String[] args) {
        boolean[] isSelf = new boolean[10001];
        int tmp;
        Arrays.fill(isSelf, false);
        for(int i = 1; i < 10000; i++){
            tmp = selfNumGen(i);
            if(tmp < 10000){
                isSelf[tmp] = true;
            }
        }
        for(int i = 1; i < 10000; i++){
            if(isSelf[i] == false){
                System.out.println(i);
            }
        }
    }

    static int selfNumGen (int tmp){
        int modulo;
        int result = tmp;
        while(tmp != 0){
            modulo = tmp % 10;
            tmp = tmp / 10;
            result += modulo;
        }
        return result;
    }
}
