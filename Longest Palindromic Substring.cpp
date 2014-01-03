//˼·���ǣ���ÿ���ַ�Ϊ�е����������죨ֻҪ������ģ�
//����չ����ı������������Ҫ�����������ĺ�ż�����ĵ����
class Solution {
public:
    string palindrome(string s, int i, int j, int len){
        string str;
        int start, end;
        start = i;
        end = j;
        while(start >= 0 && end < len){
            if(s[start] != s[end]){
                break;
            }
			start--; end++;
        }
        start++;
        end--;
        return s.substr(start, end-start+1);
    }
    
    string longestPalindrome(string s) {
        int len = s.length();
        string longestString = "";
        for(int i=0; i<len; i++){
            string str1 = palindrome(s, i, i, len); //��������
            if(str1.length() > longestString.length()){
                longestString = str1;
            }
            if(i+1 < len && s[i] == s[i+1]){
                string str2 = palindrome(s, i, i+1, len);//ż������
                if(str2.length() > longestString.length()){
                    longestString = str2;
                }
            }
        }
        return longestString;
    }
};