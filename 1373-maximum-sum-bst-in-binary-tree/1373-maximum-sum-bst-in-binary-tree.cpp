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
class NodeValue{
    public:
    int mini,maxi,sum;

    NodeValue(int mn,int mx,int s){
        mini=mn;
        maxi=mx;
        sum=s;
    }
 };
class Solution {
public:
int ans=0;

NodeValue solve(TreeNode* root){
    if(root==NULL) return NodeValue(INT_MAX,INT_MIN,0);
    NodeValue left=solve(root->left);
    NodeValue right=solve(root->right);

    if(left.maxi<root->val&&right.mini>root->val){
        int currSum=left.sum+right.sum+root->val;
        ans=max(currSum,ans);
        return NodeValue(min(left.mini,root->val),max(right.maxi,root->val),currSum);
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.sum,right.sum));
}
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};