//��2sum˼·һ����2sum�����Ը��Ӷȣ�3sum��ƽ�����Ӷ�
//���ڡ�һ��Ҫ�����ظ�Ԫ�ء�������, -2 -1 -1 0 1 2 �е�-1��
//ȡ���˵�һ��-1����ڶ���-1��ȫû��Ҫ��ȡ����һ��Ԫ����
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<int> v, v_last;
        vector<vector<int> > v_res;
        if(len<3) return v_res;
		//Ϊ�˺�������ͷ�ƽ�������Ҫ�Ÿ���
        sort(num.begin(), num.end());
        for(int i=0; i<len-2; i++) {
            int target = 0-num[i]; //����target
            int head = i+1, tail = len - 1;
			//һ��Ҫ�����ظ�Ԫ��
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
			//��������2sum���㷨
            while(head < tail){
                v.clear();
				//����ҵ���һ�����
                if(num[head]+num[tail] == target){
                    v.push_back(num[i]);
                    v.push_back(num[head++]);
                    v.push_back(num[tail--]);
					//v_last��¼��һ���������Ϊ���ظ�Ԫ�أ�������Ҫ����
                    if(v_last != v){
                        v_res.push_back(v);
                        v_last = v;
                    }
                }
                else if(num[head]+num[tail] < target){
                    head++;
                }
                else if(num[head]+num[tail] > target){
                    tail--;
                }
            }
        }
        return v_res;
    }
};