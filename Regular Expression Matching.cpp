class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        if(*p == '\0') return *s == '\0';
        if(*(p+1) != '*') {
            //��ǰ���ַ�Ҫô���Ҫô��.��ȡ��
            if(*p == *s || (*p == '.' && *s != '\0')){
                return isMatch(s+1, p+1);
            }
            else{
                return false;
            }
        }
        else{
            //���¸��ַ�Ϊ*����ǰp���ַ�ҲҪ��s���ַ���ͬ����.ȡ��
            while(*p == *s || (*p == '.' && *s != '\0')){
                //ȡ�����ַ�������������
                if(isMatch(s++, p+2)){
                    return true;
                }
            }
            //��*s == '\0'ʱ
            return isMatch(s, p+2);
        }
    }  
};