/*
�����뵽����O(N2) �Ľⷨ����ÿ�������ģ�⡣
O(N) �Ľⷨ�ǣ���������������sum �жϵ�ǰ������Ч�ԣ�total ���ж����������Ƿ��н⣬
�оͷ���ͨ��sum �õ����±꣬û���򷵻�-1��
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size(), total_gas=0, sum=0, index = -1;
        for(int i=0; i<len; i++){
            gas[i] -= cost[i];
            sum += gas[i];
            if(sum < 0) { //���sumΪ0��˵����ǰ�����Ч
                sum = 0;
                index = i;
            }
            total_gas += gas[i]; //���������ж��Ƿ��н�
        }
        return total_gas >= 0? index+1:-1;
    }
};