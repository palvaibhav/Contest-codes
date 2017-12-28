/*---------------------------------------------------
    Author : Vaibhav Pal
    College : Northern India Engineering College
    Coding Handle : underdog_eagle
    Title : Rabin-Karp String Matching ---> O(nm) uses hashing
 ----------------------------------------------------*/


import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

    final static long prime = 101; // Prime used for hashing

    public static long createHash(char[] str, int end){
        long hash = 0;
        int strLen = str.length;
        for(int i = 0; i <= Math.min(strLen - 1, end); i++){
            hash += str[i]*Math.pow(prime, i);
        }
        return hash;
    }

    public static long recalculateHash(char[] str, long oldHash, int oldIdx, int newIdx, int patternLen){
        long newHash = oldHash - str[oldIdx];
        newHash /= prime;
        newHash += str[newIdx] * Math.pow(prime, patternLen - 1);
        return newHash;
    }

    public static boolean checkEqual(char[] T, char[] P, int startIdx, int patternLen){

        for(int i = 0; i < patternLen; i++){
            if(P[i] != T[startIdx + i])
                return false;
        }
        return true;
    }

    public static ArrayList<Integer> rabinKarpSearch(char[] T, char[] P){
        int n = T.length, m = P.length;
        long patternHash = createHash(P, m - 1);
        long textHash = createHash(T, m - 1);
        ArrayList<Integer> positions = new ArrayList<>();

        for(int i = 1; i <= n - m + 1; i++){
            if(patternHash == textHash && checkEqual(T, P, i - 1, m))
                positions.add(i - 1);
            if(i < n - m + 1) // Edge case
                textHash = recalculateHash(T, textHash,  i - 1, i + m - 1, m);
        }
        return positions;
    }

    public static void main(String args[]) throws IOException{

        //Reader r = new Reader();

        char[] T = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'b'}, P = {'a', 'a', 'a', 'a', 'b'};

        ArrayList<Integer> matchedPositions = rabinKarpSearch(T, P);

        for(int i = 0; i < matchedPositions.size(); i++)
            System.out.println(matchedPositions.get(i));
    }
}

/* Nothing to look below just Fast I/O Class */

class Reader
{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    public Reader()
    {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public Reader(String file_name) throws IOException
    {
        din = new DataInputStream(new FileInputStream(file_name));
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }

    public String readLine() throws IOException
    {
        byte[] buf = new byte[64]; // line length
        int cnt = 0, c;
        while ((c = read()) != -1)
        {
            if (c == '\n')
                break;
            buf[cnt++] = (byte) c;
        }
        return new String(buf, 0, cnt);
    }

    public int nextInt() throws IOException
    {
        int ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do
        {
            ret = ret * 10 + c - '0';
        }  while ((c = read()) >= '0' && c <= '9');

        if (neg)
            return -ret;
        return ret;
    }

    public long nextLong() throws IOException
    {
        long ret = 0;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');
        if (neg)
            return -ret;
        return ret;
    }

    public double nextDouble() throws IOException
    {
        double ret = 0, div = 1;
        byte c = read();
        while (c <= ' ')
            c = read();
        boolean neg = (c == '-');
        if (neg)
            c = read();

        do {
            ret = ret * 10 + c - '0';
        }
        while ((c = read()) >= '0' && c <= '9');

        if (c == '.')
        {
            while ((c = read()) >= '0' && c <= '9')
            {
                ret += (c - '0') / (div *= 10);
            }
        }

        if (neg)
            return -ret;
        return ret;
    }

    private void fillBuffer() throws IOException
    {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }

    private byte read() throws IOException
    {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }

    public void close() throws IOException
    {
        if (din == null)
            return;
        din.close();
    }
}