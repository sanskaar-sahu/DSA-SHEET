int calcGCD(int n, int m){
  int large = n;
    int small = m;

    if(m > n) {
        large = m;
        small = n;
    }

    while(small != 0) {
        int temp = large % small;
        large = small;
        small = temp;
    }

    return large;  // this is the GCD
}

Time Complexity: O(log(min(a,b)))