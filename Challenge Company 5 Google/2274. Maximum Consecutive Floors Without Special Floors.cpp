class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        
        int ans = INT_MIN;
        for(int i=0;i<special.size()-1;i++){
            ans = max(ans,(special[i+1]-special[i]-1));
        }
        
        int i = 0;
        int j = special.size()-1;
        return max(ans,max((special[i]-bottom),(top-special[j])));
    }
};
