First Try:  �ǵݹ飬��ջʵ��
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�������ֻ��Ҫһ��ջ
 //�ȷ��ʵ�ǰ�ڵ㣬Ȼ��ѵ�ǰ�ڵ���ջ
 //���ŷ�����ڵ㲢��ջֱ��������ڵ�
 //��ջ��ʼ���ҽڵ�ķ��ʣ��������Ҫ��������
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> v;
        v.clear();
        while(root || !s.empty()){
            while(root){
                v.push_back(root->val); 
                s.push(root);
                root = root->left;
            }
            if(!s.empty()){
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return v;
    }
};

Second Try��
class Solution {
public:
	void preorderTraversal(TreeNode *root, vector<int> &v) {
		v.push_back(root->val);
		if(root->left != nullptr) preorderTraversal(root->left, v);
		if(root->right != nullptr) preorderTraversal(root->right, v);
	}

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        v.clear();
		if(root == nullptr) return v;
        preorderTraversal(root, v);
        return v;
    }
};