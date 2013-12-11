class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        bool star = false;  
        const char* starPtr = NULL;  
        const char* starDelPtr = NULL;  
        while(*s != '\0') {  
            if(*p == '?') s++, p++;  
            else if(*p == '*') {  
                while(*p == '*') p++;  
                starPtr = p-1;  //ָ��p���һ��*
                starDelPtr = s; //ָ��*������n(0,1..)���ַ����λ��
                star = true;    //˵��������*
            }  
            else {  
                if(*s == *p) s++, p++;  
                else {  
                    //����ַ������,����p֮ǰ������*
                    //����p��*�������һ���ַ��ٽ��к���ƥ��
                    if(star == true){
                        //pָ���ϸ�*��λ��֮��,sָ������һ���ַ�֮���λ��
                        s = ++starDelPtr, p = starPtr+1;
                    }
                    else return false;  //���û�г���*
                }  
            }  
        }  
        while(*p == '*') p++; //ȥ����β������*
        return *p == '\0';  
    }  
};