#include<bits/stdc++.h>
using namespace std;

class Factorial{

public:
    int MAX = 10001; // max number of digs
    int N, msp;
    vector<int> arr;

    Factorial(int n){
        N = n;
        arr.assign(MAX, 0);
        arr[0] = 1;
        msp = 0;
        calc();
    }

    void multiply(int x){
        int carry = 0;
        int pos = 0;
        for(int pos = 0; pos <= msp; pos++){
            int product = (x * arr[pos]) + carry;
            int lastdig = product % 10;
            product /= 10;
            carry = product;
            arr[pos] = lastdig;
        }
        while (carry > 0){
            arr[++msp] = carry % 10;
            carry /= 10;
        }
    }

    void calc(){
        for(int i = 2; i <= N; i++){
            multiply(i);
        }
    }

    void show(){
        for(int i = msp; i >= 0; i--) cout << arr[i];
        cout << '\n';
    }
};

int main(){

    Factorial fac(14);

    fac.show();

    return 0;
}
