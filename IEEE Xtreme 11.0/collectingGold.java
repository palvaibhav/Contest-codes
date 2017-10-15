/*---------------------------------------------------
    Author : Vaibhav Pal
    College : Northern India Engineering College
    Coding Handle : underdog_eagle
    Title : IEEE Xtreme 11.0
 ----------------------------------------------------*/



import java.util.*;

public class Main {
    final static int INF = 1000000000;
    static class Pair{
        long first;
        long second;

        public Pair(long first, long second) {
            this.first = first;
            this.second = second;
        }
    }
    static int t, n, m;
    static ArrayList<Pair> AdjList[];

    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        m = scan.nextInt();
        HashMap<Long, Integer> map = new HashMap<>();
        HashMap<Integer, Long> map2 = new HashMap<>();
        long mx_id = Integer.MIN_VALUE, mn_id = Integer.MAX_VALUE;
        int mx_node = -1, mn_node = -1;
        for(int i = 0; i < n; i++){
            long id = scan.nextLong();
            map.put(id, i);
            map2.put(i, id);
            if(id > mx_id) {
                mx_id = id;
                mx_node = i;
            }
            if(id < mn_id){
                mn_id = id;
                mn_node = i;
            }
        }

        AdjList = new ArrayList[n + 1];
        for(int i = 0; i < n; i++)
            AdjList[i] = new ArrayList<>();

        for(int i = 1; i <= m; i++){
            long id1 = scan.nextLong(), id2 = scan.nextLong(), weight = scan.nextLong();
            int u = map.get(id1);
            int v = map.get(id2);
            AdjList[u].add(new Pair(v, weight));
            AdjList[v].add(new Pair(u, weight));
        }
        //
        Vector<Integer> dist = new Vector<>();
        dist.addAll(Collections.nCopies(n, INF));
        dist.set(mn_node, 0);
        int parent[] = new int[n + 5];

        PriorityQueue<Pair> pq = new PriorityQueue<>(1,
                new Comparator< Pair >() { // overriding the compare method
                    public int compare(Pair i, Pair j) {
                        return (int)(i.first - j.first);
                    }
                }
        );
        pq.offer(new Pair(0, mn_node));

        while(!pq.isEmpty()){
            Pair top = pq.poll();
            long d = top.first, u = top.second;
            if(d > dist.get((int)u)) continue;
            for(int i = 0; i < AdjList[(int)u].size(); i++){
                Pair p = AdjList[(int)u].get(i);
                long v = p.first;
                long weight_u_v = p.second;
                if(dist.get((int)u) + weight_u_v < dist.get((int)v)){
                    dist.set((int)v, (int)(dist.get((int)u) + weight_u_v));
                    pq.offer(new Pair(dist.get((int)v), v));
                    parent[(int)v] = (int)u;
                }
            }
        }


//        System.out.println(dist.get(mx_node));
//        for(int i = 0; i < n; i++)
//            System.out.print(parent[i] + " ");

        ArrayList<Long> idsReq = new ArrayList<>();
        idsReq.add(map2.get(mn_node));
        int cur = mx_node;
        while(cur != mn_node){
            idsReq.add(map2.get(cur));
            cur = parent[cur];
        }

//        for(int i = 0; i < idsReq.size(); i++)
//            System.out.print(idsReq.get(i) + " ");

        long gold_sum = 0;
        int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
        for(int i = 0; i < idsReq.size(); i++){
            long k = idsReq.get(i);
            long num = 2;
            int cnt = 0;
            for(int j = 1; j < 16 && num <= k; j++){
                cnt++;
                num = num*arr[j];
            }
            gold_sum += cnt;
        }

        System.out.println(gold_sum);

    }



}







