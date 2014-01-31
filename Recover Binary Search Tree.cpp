/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/*
O(n) �ռ�Ľⷨ�ǣ���һ��ָ�����飬������������ڵ�ָ�����δ�ŵ������Ȼ��Ѱ����
�������λ�ã��ȴ�ǰ�����ҵ�һ�������λ�ã�Ȼ��Ӻ���ǰ�ҵڶ��������λ�ã�����������
ָ���ֵ��
*/

/*
O(log n) �ռ�Ľⷨ���£�
�õݹ��������������������ص���Ԫ�ط����ǰ��մ�С���󱻷��ʵģ��������һ������ģ�
������������������һ���϶��Ǵ��˵ģ���ô�������ĸ��أ�
������������ص��֪����һ������Ľڵ�϶���������еĽϴ�ģ��ڶ�������������н�С��
*/
class Solution { 
public : 
    TreeNode *first, *second, *pre; 
    void inorder(TreeNode *root) {  
		if(root->left) inorder(root->left);
		if(pre == NULL) pre = root;
		else if(pre->val > root->val) {
            if(first == NULL)   //���first��û����ֵ���򽫴���Ǹ�����first
                first = pre;    
            second = root; //���first�Ѿ���ֵ���ˣ���С���Ǹ�����second
        } 
        pre = root; 
        if(root->right) inorder(root->right); 
    } 
    void recoverTree(TreeNode *root) { 
        if(!root) return;
        first = second = pre = NULL; 
        inorder(root);
        swap(first->val, second->val); //������������ڵ�
    }
};  

/*
O(1) �ռ�Ľⷨ��Morris �������
*/
