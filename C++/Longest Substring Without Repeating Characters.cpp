//Since leetcode changed the test input, the first version does not work
//�����Ӵ��ﺬ���ظ��ַ����򸸴�һ�������ظ��ַ�������������Ϳ��Ծ��������⣬��˿�
//����̰�ķ��������治ͬ�����������������ֻ��Ӱ�츸���⣬�����Ծ��������⡣
//��������ɨ�裬�������ظ���ĸʱ������һ���ظ���ĸ��index+1����Ϊ�µ�������ʼλ�ã�
//ֱ�����һ����ĸ�����Ӷ���O(n)��
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool flag[32];
        int head=0, tail=head, len = s.length(), max = 1;
        if(!len){
            return 0;
        }
        for(int i=0; i<32; i++){
            flag[i] = false;
        }
        flag[s[head]-'a'] = true;
        while(tail < len-1){
            while(flag[s[tail+1]-'a']){ //existed
                flag[s[head++]-'a'] = false;
            }
            flag[s[++tail]-'a'] = true;
            if(tail-head+1>max){
                max = tail-head+1;
            }
        }
        return max;
    }
};

//Second try:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int longest = 0;
        int len = 0;
        for(int i=0; i<s.size();) {
            if(m.find(s[i]) == m.end() || m[s[i]] == 0) {
                m[s[i]] = 1;
                i++;
                len++;
                longest = max(longest, len);
            }
            else {
                while(m[s[i]] > 0) {
                    m[s[i-len]]--;
                    len--;
                }
            }
        }
        return longest;
    }
};