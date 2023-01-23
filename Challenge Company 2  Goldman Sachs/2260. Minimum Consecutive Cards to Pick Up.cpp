class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> map;
        int Min = INT_MAX;
        int k=0;
        
        for(;k<cards.size();k++){
            if(map.count(cards[k])>=1){
                Min=min(Min,k-map[cards[k]]);
            }
            map[cards[k]]=k;
        }
        
        if(Min==INT_MAX) return -1;
        else return Min+1;
    }
};
