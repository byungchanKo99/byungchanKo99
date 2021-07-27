package w2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class w2_n2869 {
    public static void main(String[] args) throws IOException{
        double count;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input); 
        double a = Double.parseDouble(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int v = Integer.parseInt(st.nextToken());
        count = (v - a) / (a - b);
        count = Math.ceil(count);
        System.out.println(Math.round(count * 10) / 10 + 1);
    }
}
