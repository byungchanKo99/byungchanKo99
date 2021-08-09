package w4;
import java.util.* ;

public class n2530 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int hour = sc.nextInt();
        int minute = sc.nextInt();
        int second = sc.nextInt();
        int time = sc.nextInt();

        second += time % 60;
        minute += time / 60;
        if(second >= 60){
            minute++;
            second -= 60;
        }
        hour += minute / 60;
        minute %= 60;
        if(hour >= 24){
            hour %= 24;
        } 
        System.out.printf("%d %d %d", hour, minute, second);
    }
}
