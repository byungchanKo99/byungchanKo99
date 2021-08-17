package w5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 마지막 keySet 순서보장 안해줬는데 우연히 맞았다.
// 웬만하면 순서대로 나오는 것 같긴 함.
// 마찬가지 10만개 정렬보단 Set 100개가 낫지 않나.
public class n10814 {
    public static void main(String[] args) throws IOException {
        int n;
        int index;
        String name;
        Map<Integer,ArrayList<String>> hm = new HashMap<>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            index = Integer.parseInt(st.nextToken());
            name = st.nextToken();
            if(!hm.containsKey(index)){
                ArrayList<String> tmp = new ArrayList<>();
                tmp.add(name);
                hm.put(index,tmp);
            }else{
                hm.get(index).add(name);
            }
        }
        for(Integer tmp : hm.keySet()){
            hm.get(tmp).forEach(p -> System.out.println(tmp + " " + p));
        }
    }
}
