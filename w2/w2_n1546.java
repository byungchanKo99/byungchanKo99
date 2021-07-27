package w2;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class w2_n1546 {
    public static void main(String[] args) throws NumberFormatException, IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        String input = br.readLine();
        StringTokenizer st = new StringTokenizer(input); 
        double[] grades = new double[count];
        double max = 0;
        double sum = 0;
        double min = 0;
        for(int i = 0; i < count; i++){
            grades[i] = Double.parseDouble(st.nextToken());
            if(grades[i]>max){
                max = grades[i];
            }
        }
        for(int i = 0; i < count; i++){
            grades[i] = grades[i] / max * 100;
            sum += grades[i];
        }
        min = sum / count;
        min = Math.round(min * 100) / 100.0;
        System.out.println(min);
    }
}
