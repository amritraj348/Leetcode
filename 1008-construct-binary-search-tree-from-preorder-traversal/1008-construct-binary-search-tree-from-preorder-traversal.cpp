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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildTree(preorder,i,INT_MAX);
    }

    TreeNode* buildTree(vector<int>&root,int& i,int ub){
        if(i==root.size()||root[i]>ub) return NULL;
        TreeNode * node=new TreeNode(root[i++]);
        node->left=buildTree(root,i,node->val);
        node->right=buildTree(root,i,ub);
        return node;
    }
};