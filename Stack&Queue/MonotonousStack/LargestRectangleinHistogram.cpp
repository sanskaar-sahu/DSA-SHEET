class Solution {
public:
 vector<int> pseIdx(vector<int>& arr, int n) {
    vector<int> pse(n);
    stack<pair<int,int>> st; // {value, index}

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top().second;
        st.push({arr[i], i});
    }
    return pse;
}

vector<int> nseIdx(vector<int>& arr, int n) {
    vector<int> nse(n);
    stack<pair<int,int>> st; // {value, index}

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top().second;
        st.push({arr[i], i});
    }
    return nse;
}
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>pse = pseIdx(heights , n);
        vector<int>nse = nseIdx(heights , n);
        int maxi = 0;

        for(int i = 0 ; i < n ; i++){
            int area = heights[i] * (nse[i] - pse[i] - 1);
            maxi = max(maxi , area);
        }

        return maxi;
    }
};