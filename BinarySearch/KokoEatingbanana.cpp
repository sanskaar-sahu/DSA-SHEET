class Solution {
public:

    
    bool isValid(vector<int>& piles, int speed, int h) {
        long long time = 0;
        for (int pile : piles) {
            // ceil(pile / speed)
            time += (pile + speed - 1) / speed;
            if (time > h) return false; // too slow
        }
        return true; // possible within h hours
    }    

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isValid(piles, mid, h)) {
                ans = mid;          
                high = mid - 1;
            } else {
                low = mid + 1;      
          }
        }

        return ans;
    }
};