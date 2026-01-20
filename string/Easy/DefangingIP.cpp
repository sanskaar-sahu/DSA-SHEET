class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        int i = 0  , n = address.length();

        while(i < n){
            if(address[i]== '.'){
                res+="[.]";
            }else{
                res.push_back(address[i]);
            }
            i++;
        }

        return res;
    }

};