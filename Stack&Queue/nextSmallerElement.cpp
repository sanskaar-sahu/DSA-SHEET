
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   stack<int>st;
   vector<int>res(n,-1);

   for(int i = n - 1 ; i>=  0 ; i--){
      if(!st.empty()){
         while(!st.empty() && st.top() >= arr[i]) st.pop();
      }

      if(!st.empty() && st.top() < arr[i]){
         res[i] = st.top();
      }

      st.push(arr[i]);

   }

   return res;
}