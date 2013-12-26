My solution:
//�Ӻ���ǰ�����ȰѺ���Ŀո񶪵�
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = strlen(s), len_last = 0;
        int cur = len-1;
        if(!len){
            return 0;
        }
        while(s[cur]==' ' && cur-->=0);
        while(s[cur]!=' ' && cur-->=0){
            len_last++;
        }
        return len_last;
    }
};

Other solution:
//��ǰ�����, ʵ�ֱȽ����
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = 0;
		while (*s) {
			if (*s++ != ' ')
				++len;
			else if (*s && *s != ' ')
				len = 0;
		}
		return len;
	}
};

//��STL
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		const string str(s);
		//�Ӻ���ǰ�ҵ�һ����ĸ
		auto first = find_if(str.rbegin(), str.rend(), ::isalpha);
		//�����һ����ĸ��ǰ�ҵ�һ������ĸ
		auto last = find_if_not(first, str.rend(), ::isalpha);
		//�������߲��
		return distance(first, last);
	}
};