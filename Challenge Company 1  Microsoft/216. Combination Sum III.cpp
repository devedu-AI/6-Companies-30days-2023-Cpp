class Solution {
public:
    vector<vector<int>> ans;
    void helper(int k,int target,vector<int> &temp,vector<int> &arr,int i){
        
        if(i<0){
            if(target==0 && k==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(target==0 && k==0){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(arr[i]);
        helper(k-1,target-arr[i],temp,arr,i-1);
        temp.pop_back();
        helper(k,target,temp,arr,i-1);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        helper(k,n,temp,arr,8);
        return ans;
    }
};
