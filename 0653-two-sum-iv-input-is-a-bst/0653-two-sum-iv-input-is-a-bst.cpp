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
 class BSTIterator{
    stack<TreeNode*>st;
    bool reverse;
 public:
 BSTIterator(TreeNode* root,bool isReverse){
    reverse=isReverse;
    pushAll(root);
 }
 void pushAll(TreeNode* root){
    while(root){
        st.push(root);
        if(!reverse) root=root->left; //for next();
        else root=root->right;
    }
 }
 int next(){
    TreeNode* node=st.top();
    st.pop();
    if(!reverse) pushAll(node->right);
    else pushAll(node->left);
    return node->val;
 }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;

        BSTIterator l(root,false);//for next()
        BSTIterator r(root,true);//for before();
        int i=l.next();
        int j=r.next();

        while(i<j){
            int sum=i+j;
            if(sum==k)
            return true;
            else if(sum<k)
            i=l.next();
            else
            j=r.next();
        }
        return false;
    }
};