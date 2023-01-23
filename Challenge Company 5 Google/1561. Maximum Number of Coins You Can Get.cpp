class Solution {
public:
    int maxCoins(vector<int>& piles) {
        priority_queue <int, vector<int>, greater<int>> pq;
        for(auto i:piles) pq.push(i);
        
        int n = piles.size()/3;
        int temp=n;
        while(temp--){
            pq.pop();
        }
        
        int ans=0;
        while(n--){
            ans+=pq.top();
            pq.pop();
            pq.pop();
        }
        
        return ans;
    }
};
