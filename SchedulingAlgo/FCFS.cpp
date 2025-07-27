#include<bits/stdc++.h>

class Solution{

    class Process{
        int id ; //process id 
        int at; //arrival time
        int tat ; //total turn around time 
        int wt; //total waiting time 
        int ct ; //total completion time ;
        
        void input(Process  ,int  n); //taking the input parameter for the process ;
        void sort(Process)  //sort the process as per the arrival time
        void calc(Process p ,int n);
    }
     
    void calc(Process * p , int n){
        int sum = 0;
        sum = p.at[0];
        for(int i = 0 ; i < n ; i++){
            sum+= p.bt[i];
            p[i].ct = sum;
            p[i].tat = tat[i] - at[i];
            p[i].wt = tat[i] - bt[i];
             if(sum < p[i+1].at){         //additional step so that the next process is already arrived by that time 
                int t = p[i+1].at;
                sum = sum + t;
            }
        }
    }
}