class Solution {
public:

    bool isValidSerialization(string preorder) {
        int vacancy = 1;
        int n = preorder.length();
        for(int i = 0 ; i < n ;) {
            if (vacancy == 0) return false; //no slot available but still nodes left

            // move past comma if any
            if (i < n && preorder[i] == ',') i++;

            if (preorder[i] == '#') {
                vacancy -= 1;  // null node consumes one slot
                i++;           // move past '#'
            } else {
                // parse full number (multi-digit allowed)
                while (i < n && preorder[i] != ',') i++;
                vacancy -= 1;  // consume one slot
                vacancy += 2;  // non-null provides two slots
                continue;
            }
        }

        return vacancy == 0;

    }
};