/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,pair<int,int>> average(TreeNode* root){
        if(root==NULL) return {0,{0,0}};
    
        int r=0,l=0;
        int cnt=1;
        int ans = 0;
        if(root->left){
            pair<int,pair<int,int>> p = average(root->left);
            l+=p.first;
            cnt+=p.second.first;
            ans+=p.second.second;
        }
        if(root->right){
            pair<int,pair<int,int>> p =average(root->right);
            r+=p.first;
            cnt+=p.second.first;
            ans+=p.second.second;
        }
        int total = r+l+root->val;
        int avg = total/cnt;
        
        if(avg==root->val){
            ans++;
        }
        
        return {total,{cnt,ans}};
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        return average(root).second.second;
    }
};
