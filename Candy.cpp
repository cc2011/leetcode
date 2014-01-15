/*
�Ӳ�ͬ����ɨ�����鼴��
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        int size = ratings.size();
		//��ÿ����һ����
        vector<int> candy(size, 1);
		//�ȴ�������ɨ��
        for(int i=1; i<size; i++){
           if(ratings[i] > ratings[i-1]){
               candy[i] = candy[i-1] + 1;
           } 
        }
        int res = candy[size-1];
		//�ٴ�������ɨ��
        for(int i=size-2; i>=0; i--){
           if(ratings[i] > ratings[i+1] && candy[i] <= candy[i+1]){
               candy[i] = candy[i+1] + 1;
           }
           res += candy[i];
        }
        return res;
    }
};