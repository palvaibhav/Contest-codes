/*
    Author : Vaibhav Pal
    College : Northern India Engineering College
    Coding Handle : underdog_eagle
    Title : KosaRaju algorithm for finding Strongly Connected Components.
 */


import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

public class Main {

    static int V, E;
    static ArrayList<Integer> adjList[], adjListTranspose[];
    static boolean visited[];
    static Stack<Integer> finishingVertices;

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        V = scan.nextInt();  // No. of vertices
        E = scan.nextInt();  // No. of edges

        // Initializing Adjacency List
        adjList = new ArrayList[V + 1];
        adjListTranspose = new ArrayList[V + 1];
        for(int i = 1; i <= V; i++) {
            adjList[i] = new ArrayList<>();
            adjListTranspose[i] = new ArrayList<>();
        }

        for(int i = 1; i <= E; i++){
            int u = scan.nextInt();
            int v = scan.nextInt();
            adjList[u].add(v);
        }

        ArrayList<ArrayList<Integer>> SCCs = getSCCs();

        for(int i = 1; i < SCCs.size(); i++){
            System.out.print(i + " : ");
            ArrayList<Integer> scc = SCCs.get(i);
            for(int j = 0; j < scc.size(); j++)
                System.out.print(scc.get(j) + " ");
            System.out.println();
        }

    }

    public static void dfs1(int u){
        visited[u] = true;
        for(int i = 0; i < adjList[u].size(); i++){
            int child = adjList[u].get(i);
            if(!visited[child])
                dfs1(child);
            adjListTranspose[child].add(u); // for making the Transposed graph
        }

        finishingVertices.push(u);
    }

    public static void dfsUtil1(){
        for(int u = 1; u <= V; u++){
            if(!visited[u])
                dfs1(u);
        }
    }

    public static void dfs2(int u, ArrayList<Integer> scc){
        visited[u] = true;
        scc.add(u);

        for(int i = 0; i < adjListTranspose[u].size(); i++){
            int child = adjListTranspose[u].get(i);
            if(!visited[child])
                dfs2(child, scc);
        }
    }

    public static ArrayList<ArrayList<Integer>> getSCCs(){
        visited = new boolean[V + 1];
        finishingVertices = new Stack<>();
        dfsUtil1();

        for(int i = 1; i <= V; i++)
            visited[i] = false;

        ArrayList<ArrayList<Integer>> SCCs = new ArrayList<>();
        SCCs.add(new ArrayList<>()); // for 1 indexing.

        while (!finishingVertices.empty()){
            int u = finishingVertices.pop();
            if(!visited[u]){
                ArrayList<Integer> scc = new ArrayList<>();
                dfs2(u, scc);
                SCCs.add(scc);
            }
        }

        return SCCs;
    }

}







