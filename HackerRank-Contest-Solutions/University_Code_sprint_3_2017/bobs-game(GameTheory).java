import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {

    static int n;
    static char grid[][];
    static int grundy[][];
    static Scanner scan;
    static int dr[] = {-1, 0, -1}, dc[] = {0, -1, -1};

    static class Pair<T, Z>{
        T x;
        Z y;

        public Pair(T x, Z y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String args[]) {
        scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            init();

            ArrayList<Pair<Integer, Integer>> coordinates = new ArrayList<>();
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] == 'K')
                        coordinates.add(new Pair<>(i, j));
                }
            }

            int xor = 0;
            for (int i = 0; i < coordinates.size(); i++){
                Pair<Integer, Integer> temp = coordinates.get(i);
                int res = calculateGrundy(temp.x, temp.y);
                xor ^= res;
            }

            int cnt = 0;
//            System.out.println(xor);
//            for(int i = 0; i < n; i++){
//                for(int j = 0; j < n; j++)
//                    System.out.print(grundy[i][j] + " ");
//                System.out.println();
//            }

            if(xor > 0){
                for(int i = 0; i < coordinates.size(); i++){
                    Pair<Integer, Integer> temp = coordinates.get(i);
                    for(int j = 0; j < 3; j++){
                        int grundyNum1 = calculateGrundy(temp.x + dr[j], temp.y + dc[j]);
                        int grundyNum2 = calculateGrundy(temp.x, temp.y);
                        if((xor ^ grundyNum1 ^ grundyNum2) == 0)
                            cnt++;
                    }
                }
            }

            System.out.println((xor > 0) ? "WIN " + cnt : "LOSE");
        }

        scan.close();
    }

    public static void init(){
        n = scan.nextInt();
        grid = new char[n + 5][n + 5];
        for(int i = 0; i < n; i++){
            String str = scan.next();
            for(int j = 0; j < n; j++)
                grid[i][j] = str.charAt(j);
        }

        grundy = new int[n + 5][n + 5];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                grundy[i][j] = -1;
    }

    public static int calculateMEX(HashSet<Integer> s){
        int mex = 0;
        while(s.contains(mex))
            mex++;
        return mex;
    }

    public static int calculateGrundy(int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 'X')
            return -1;
        if(grundy[x][y] != -1)
            return grundy[x][y];

        HashSet<Integer> s = new HashSet<>();

        s.add(calculateGrundy(x, y - 1));
        s.add(calculateGrundy(x - 1, y));
        s.add(calculateGrundy(x - 1, y - 1));

        int mex = calculateMEX(s);
        grundy[x][y] = mex;

        return mex;
    }



}




/*

....XKKKKK
..........
..........
..........
..........
..........
..........
..........
..........
..........



 */



