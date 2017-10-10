public class ZigZag{
   public static int longestZigZag(int[] sequence){
        int n = sequence.length;
        int sol[] = new int[n];
        for(int i = 0; i < n; i++)
            sol[i] = 1;

        if(n > 1)
            sol[1] = 2;
        for(int i = 2; i < n; i++){
            for(int j = 0; j < i; j++){
                if(j - 1 >= 0){
                    if((((sequence[j] - sequence[j-1] < 0) && (sequence[i] - sequence[j] > 0))) || ((sequence[j] - sequence[j-1] > 0) && (sequence[i] - sequence[j] < 0)))
                        sol[i] = Math.max(sol[i], sol[j] + 1);
                }
            }
        }
		
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans = Math.max(ans, sol[i]);
        return ans;
    }
}