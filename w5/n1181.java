package w5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// HashMap keySet은 순서보장 X -> TreeMap으로 바꿔주는 등 key값 순서 보장 해줘야함.
// 최대 2만개 정렬할 바엔 set 최대 50개 생기는게 낫지 않을까.
public class n1181 {
    public static void main(String[] args) throws IOException {
        int n;
        int index;
        String word;
        Map<Integer, HashSet<String>> hm = new HashMap<Integer, HashSet<String>>();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            word = br.readLine();
            index = word.length();
            if(!hm.containsKey(index)){
                HashSet<String> tmp = new HashSet<>();
                tmp.add(word);
                hm.put(index, tmp);
            } else {
                hm.get(index).add(word);
                }
            }
        for(int tmp : new TreeSet<Integer>(hm.keySet())){
            hm.get(tmp).stream().sorted().forEach(e -> System.out.println(e));
        }
        }



}
