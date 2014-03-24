//��3sumûʲô��һ��
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        int sum = 0, head, tail;
        int diff, diff_min = (1<<31)-1;
        if(len<=3){
            for(int i=0; i<len; i++){
                sum += num[i];
            }
            return sum;
        }
		//������
        sort(num.begin(),num.end());
        for(int i=0; i<len-2; i++){
            head = i+1;
            tail = len-1;
			//2sum���ұƽ�
            while(head < tail){
                sum = num[i]+num[head]+num[tail];
                diff = target - sum;
                if(diff == 0){
                    return target;
                }
                if(diff<0){
                    tail--;
                }
                else if(diff>0){
                    head++;
                }
				//������С���
                if(abs(diff_min)>abs(diff)){
                    diff_min = diff;
                }
            }
        }
        return target - diff_min;
    }
};