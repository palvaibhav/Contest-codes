/*---------------------------------------------------
    Author : Vaibhav Pal
    College : Northern India Engineering College
    Coding Handle : underdog_eagle
    Title :
 ----------------------------------------------------*/

import java.math.BigInteger;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static BigInteger solve(int n, HashMap<Integer, BigInteger> map){
        if(n == 0)
            return new BigInteger("1");
        if(n < 0)
            return new BigInteger("0");

        if(map.containsKey(n)) return map.get(n);

        BigInteger ans = new BigInteger("0");
        ans = ans.add(solve(n - 1, map));
        ans = ans.add(solve(n - 2, map));
        map.put(n, ans);
        return ans;
    }

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t-- > 0){
            int n = scan.nextInt();
            System.out.println(solve(n, new HashMap<>()));
        }
    }
}







