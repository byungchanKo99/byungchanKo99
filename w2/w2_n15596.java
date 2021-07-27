package w2;
public class w2_n15596 {
    public static void main(String[] args){
        int[] k = {1, 2, 3};
        System.out.println(sum(k));
    }
    static long sum(int[] a) {
        long ans = 0;
        for(int i = 0; i < a.length; i++){
            ans += a[i];
        }
        return ans;
    }
}
