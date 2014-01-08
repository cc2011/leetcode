/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, int h1, int t1, vector<int> &postorder, int h2, int t2){
        TreeNode *node;
        if(h1 > t1) return NULL;
        node = new TreeNode(postorder[t2]);
        int index, left_len;
        for(int i=h1; i<=t1; i++){
            if(inorder[i] == postorder[t2]){
                index = i;
            }
        }
        left_len = index-h1;
        node->left = buildTree(inorder, h1, index-1, postorder, h2, h2+left_len-1);
        node->right = buildTree(inorder, index+1, t1, postorder, h2+left_len, t2-1);
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int size1 = inorder.size(), size2 = postorder.size();
        int size = size1;
        if(size1 == 0 || size1 != size2){
            return NULL;
        }
        return buildTree(inorder, 0, size-1, postorder, 0, size-1);
    }
};