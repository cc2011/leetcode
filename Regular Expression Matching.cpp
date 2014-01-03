/*p是正则表达式，s为字符串
1.如果p为空串 则s必须为空串才匹配
2.如果非空, 则分2种情况讨论
  a.如果下一个字符非*号，则当前的字符要么相等要么p以.来取代s中的字符，且s中必须有字符（.不能匹配/0）
    如果满足以上条件，则递归从s+1，p+1进行判断
  b.如果下一个字符是*号，则当前p的字符也要与s的字符相同或以.取代，不同的是p中的*号可以不断蚕食s中的字符直到/0
    因此递归是s++，p+2，直到s为\0时
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {  
        if(*p == '\0') return *s == '\0';
        if(*(p+1) != '*') {
            //当前的字符要么相等要么以.来取代
            if(*p == *s || (*p == '.' && *s != '\0')){
                return isMatch(s+1, p+1);
            }
            else{
                return false;
            }
        }
        else{
            //若下个字符为*，当前p的字符也要与s的字符相同或以.取代
            while(*p == *s || (*p == '.' && *s != '\0')){
                //取代的字符个数尝试增加
                if(isMatch(s++, p+2)){
                    return true;
                }
            }
            //当*s == '\0'时
            return isMatch(s, p+2);
        }
    }  
};