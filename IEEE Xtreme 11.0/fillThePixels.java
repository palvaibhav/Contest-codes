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

    static int t, w, h, ans1, ans2, ans3;
    static int dr1[] = {-1, 0, 1, 0};
    static int dc1[] = {0, 1, 0, -1};
    static int dr2[] = {-1, -1, 1, 1};
    static int dc2[] = {-1, 1, 1, -1};
    static int dr3[] = {1, 1, 0, -1, -1, -1, 0, 1};
    static int dc3[] = {0, 1, 1, 1, 0, -1, -1, -1};
    static char grid[][];
    static boolean vis[][];

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        t = scan.nextInt();
        while(t-- > 0){
            w = scan.nextInt();
            h = scan.nextInt();
            grid = new char[h + 1][w + 1];
            for(int i = 0; i < h; i++){
                String input = scan.next();
                for(int j = 0; j < input.length(); j++)
                    grid[i][j] = input.charAt(j);
            }

            vis = new boolean[h + 1][w + 1];
            ans1 = 0;
            findAns1();
            //System.out.println(ans1);

            vis = new boolean[h + 1][w + 1];
            ans2 = 0;
            findAns2();
            //System.out.println(ans2);

            vis = new boolean[h + 1][w + 1];
            ans3 = 0;
            findAns3();
            //System.out.println(ans3);

            System.out.println(ans1 + " " + ans2 + " " + ans3);
        }
    }

    public static void dfs1(int x, int y){
        if(x < 0 || x >= h || y < 0 || y >= w || grid[x][y] == '0' || vis[x][y])
            return;
        vis[x][y] = true;
        for(int i = 0; i <= 3; i++)
            dfs1(x + dr1[i], y + dc1[i]);
    }

    public static void findAns1(){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs1(i, j);
                    ans1++;
                }
            }
        }
    }

    public static void dfs2(int x, int y){
        if(x < 0 || x >= h || y < 0 || y >= w || grid[x][y] == '0' || vis[x][y])
            return;
        vis[x][y] = true;
        for(int i = 0; i <= 3; i++)
            dfs2(x + dr2[i], y + dc2[i]);
    }

    public static void findAns2(){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs2(i, j);
                    ans2++;
                }
            }
        }
    }

    public static void dfs3(int x, int y){
        if(x < 0 || x >= h || y < 0 || y >= w || grid[x][y] == '0' || vis[x][y])
            return;
        vis[x][y] = true;
        for(int i = 0; i <= 7; i++)
            dfs3(x + dr3[i], y + dc3[i]);
    }

    public static void findAns3(){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs3(i, j);
                    ans3++;
                }
            }
        }
    }

}







