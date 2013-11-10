/**
*˼·��
*�ܼ򵥵ĵݹ飬����������������⣬����Ҫ��5����֮�ڸ㶨��һ��ͨ��Ҫ�Ƚ��������С�
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
   int maxDepth(TreeNode *root) {
       // Note: The Solution object is instantiated only once and is reused by each test case.
       int length, length_left, length_right;
       if(root){                     //����Ҫ�ж�root�Ƿ�Ϊ��
           length = 1;
       }
       else{
           return 0;
       }
       if(root->right){              //�ж��������Ƿ�Ϊ��
           length_right = maxDepth(root->right); //���������ݹ�
       }
       else{
           length_right = 0;
       }
       if(root->left){               //�ж��������Ƿ�Ϊ��           length_left = maxDepth(root->left);  //���������ݹ�
       }
       else{
           length_left = 0;
       }
       length += length_right>length_left?length_right:length_left; //�������������нϴ��
       return length;
   }
};
