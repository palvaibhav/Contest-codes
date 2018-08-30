public class AB {

    private static String makeString(int s, int N){
        char str[] = new char[N + 1];
        for(int i = 0; i < N/2; i++)
            str[i] = 'A';
        for(int i = N/2; i < N; i++)
            str[i] = 'B';

        int cur = N/2 - 1, prev = N/2 - 2, temp = 0;
        while(s > 0){
            str[cur] = 'B';
            str[cur + 1] = 'A';
            if(cur + 1 < N - 1 - temp)
                cur++;
            else{
                cur = prev;
                prev--;
                temp++;
            }
            s--;
        }
        String res = "";
        for(int i = 0; i < N; i++)
            res += str[i];

        return res;
    }

    public static String createString(int N, int K){
        if(N % 2 == 0){
            int mx = (N/2)*(N/2);
            if(K <= mx)
                return makeString(mx - K, N);
            else
                return "";
        }
        else{
            int mx = (N/2)*(N - (N/2));
            if(K <= mx)
                return makeString(mx - K, N);
            else
                return "";
        }
    }

    public static void main(String args[]){
        System.out.println(createString(10, 12));
    }

}