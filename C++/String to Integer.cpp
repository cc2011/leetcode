//��ϸ����
class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str), i = 0;
        long long value = 0;
        bool b_negative = false;
		//�Ȱ�ǰ���ո�ȥ��
        while(str[i] == ' ') i++;
		//���жϵ�һ���ַ��ǲ��Ƿ���
        if(str[i] == '-' || str[i] == '+'){
            if(str[i] == '-') {
                b_negative = true;
            }
            i++;
        }
		//��ǰ��0��ȥ��
        while(str[i] == '0') i++;
		//��ÿ���ַ�ѭ�������������־ͽ���
        for(; i<len; i++){
            if(str[i] < '0' || str[i] > '9'){
                break;
            }
            value = value*10+str[i]-'0';
			//�ж��Ƿ����
            if(value > INT_MAX){
                return b_negative? INT_MIN : INT_MAX;
            }
        }
		//����Ǹ�2147483648�򷵻�-2147483648
        if(b_negative && (value == 2147483648)) return INT_MIN;
		//������ݷ��ŷ���
        return b_negative? 0-value:value;
    }
};