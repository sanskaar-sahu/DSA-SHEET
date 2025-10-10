
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   vector<int>NSE(n , -1);
   stack<int>st;

   for(int i = n -1 ; i >= 0 ; i--){
      while(!st.empty() && st.top() >= arr[i]){
         st.pop();
      }

      if(!st.empty()){
         NSE[i] = st.top();
      }
      st.push(arr[i]);
   }

   return NSE;
}