class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        vector<int> dp(n,1);
        int maxi = 1;
        vector<int> hash(n);
        int lastIndex = 0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi < dp[i]){
                maxi=dp[i];
                lastIndex = i;
            }
        }
        
        cout<<lastIndex;
        
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        
        return temp;
        
    }
};
