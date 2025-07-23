#include<iostream>
#include<vector>
using namespace std;

int main(){
    int fib= 5;
    vector<int>mem(fib+ 1 , -1);

    mem[0] = 0;
    mem[1] = 1;
    cout<<mem[0]<<" "<< mem[1]<<" ";

    for(int i = 2 ; i <= fib; i++){
        mem[i] = mem[i-1] + mem[i-2];
        cout<<mem[i] <<" ";
    }
    return 0;
}