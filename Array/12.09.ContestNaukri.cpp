#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int>& nums) {
    int n= nums.size();
    unordered_map<int,int> freq;
    for (int x : nums) freq[x]++;

    // max-heap: {points, num}
    priority_queue<pair<int,int>> pq;
    for (auto &it : freq) {
        pq.push({it.first * it.second, it.first});
    }

    int total = 0;
    int el = pq.top().second;
    cout<<el<<endl;
    total+= pq.top().first;

    
     for(int i=0; i<n; i++){
        if(el%nums[i] == 0){
            continue;
                        cout<<total<<endl;

        }
        else if (nums[i]%el == 0 ){
            continue;
            cout<<total<<endl;
        }
            total+=nums[i];

    }
    return total;
}

int main() {
    vector<int> nums = {2,3,3,4,4,6,6};
    cout << maxPoints(nums) << endl; // Expected 10
    return 0;
}