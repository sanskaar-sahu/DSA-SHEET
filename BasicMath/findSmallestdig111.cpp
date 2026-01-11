/*
Ninja’s favorite numbers are the numbers whose all digits are ‘1’. 
So Let's consider numbers that have only the digit ‘1’. For example, [ ‘1’, ‘11’, ‘111’ … ]
You are given an integer ‘K’, Your task is to find the number of digits in the Ninja’s smallest favorite number that is divisible by ‘K’. If there is no such number that is divisible by ‘K’, then return -1.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
Test cases = 2
k=1
k=8
Sample Output 1:
1
-1
Explanation of Sample Input 1:
Test case 1:
‘1’ is itself divided by one, that has only 1 digit, hence the answer will be 1.
Test case 2:
There is no number whose all digits are ‘1’ and divisible 8 , so the answer will be -1.
Sample Input 2:
1
11
Sample Output 2:
2
Explanation of Sample Input 2:
Test case 1:
‘11’ is itself divided by 11 which have 2 digits hence the answer will be 2.


*/


#include <bits/stdc++.h> 

int lengthOfNumber(int k)
{
	// Write your code here
    if(k%2 == 0 || k%5 == 0) return -1;
    int rem = 0;

	for(int len = 1 ; len <= k  ; len++){
		rem = (rem * 10 + 1)%k;

		if(rem== 0) return len;
	}

	return -1;
}