//�ܼ򵥣���TCP��������ÿ������һ��
class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0, multior = 0;
		//һ��Ҫ��ת��long long, ��Ȼ�ᱻINT_MIN����
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        while(a >= b){
            if(a >= (b<<multior)) {
                res += (1<<multior);
                a -= (b<<multior);
                ++multior;
            }
            else {
                multior = 0;
            }
        }
		//�ж������������Ƿ���ͬ������ͬ�򷵻ظ���
        return ((dividend^divisor)>>31)? 0-res:res;
    }
};