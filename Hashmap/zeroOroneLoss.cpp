

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int>players;
        unordered_map<int,int>loses;

        for(auto it : matches){
            int winner = it[0];
            int loser = it[1];
            
            //mark each player we have
            players.insert(winner);
            players.insert(loser);
            
            //count of runner up losing the match
            loses[loser]++;
        }

        vector<int>zeroLoss;
        vector<int>oneLoss;

        for(int i : players){
            if(loses.find(i) == loses.end()){
                zeroLoss.push_back(i);
            }else if(loses[i] == 1){
                 oneLoss.push_back(i);
            }
        }
        vector<vector<int>>res;
        sort(oneLoss.begin(), oneLoss.end());
        sort(zeroLoss.begin() , zeroLoss.end());
        res.push_back(zeroLoss);
        res.push_back(oneLoss);
        return res;
    }
};