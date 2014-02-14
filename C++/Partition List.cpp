/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
�����ݷֳ�2������С��x�ķŵ�smaller�У�����x�ķŵ�bigger��
��Ϊ��������˳��ŵģ���������֮������˳���ǲ�����
smaller_head��biger_head��ͷָ�룬smaller_ptr��biger_ptr������������ָ��
���ص�ʱ��ע�����������Ƿ�Ϊ�յ��������
*/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *smaller_head, *biger_head, *smaller_ptr, *biger_ptr;
        smaller_head = biger_head = smaller_ptr = biger_ptr = NULL;
        while(head) {
			//��С��x��Ԫ�طŵ�smaller���������
            if(head->val < x){
				//����smaller�Ƿ�Ϊ������������
                if(!smaller_head) smaller_head = smaller_ptr = head;
                else{
                    smaller_ptr->next = head;
                    smaller_ptr = smaller_ptr->next;
                } 
            }
			//�Ѵ��ڵ���x��Ԫ�طŵ�bigger���������
            else{
				//����biger�Ƿ�Ϊ������������
                if(!biger_head) biger_head = biger_ptr = head;
                else{
                    biger_ptr->next = head;
                    biger_ptr = biger_ptr->next;
                } 
            }
            head = head->next;
        }
		//��������Ϊ�յ�������ؽ��
        if(!smaller_head && !biger_head) return NULL;
        if(biger_head) biger_ptr->next = NULL;
        if(smaller_head){
            smaller_ptr->next = biger_head;
            return smaller_head;
        }
        return biger_head;
    }
};