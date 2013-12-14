//DFS�ⷨ
class Solution {
private:
    map<int, bool> m;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len = s.length();
        if(dict.find(s) != dict.end()){
            return true;
        }
        
        for(int i=1; i<len; i++){
            if(dict.find(s.substr(0,i)) != dict.end()){
                if(!m[i] && wordBreak(s.substr(i,len-i), dict)) {
                    return true;
                }
                else {
                    m[i] = true; //���ʹ���
                }
            }
        }
        return false;
    }
};

//DP�ⷨ
/*��״̬Ϊf(i)����ʾs[0,i] �Ƿ���Էִʣ���״̬ת�Ʒ���Ϊ
f(i) = any_of(f(j)&&s[j + 1, i] �� dict ��); 0 <= j < i
*/
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		// ����Ϊn ���ַ�����n+1 ������
		vector<bool> f(s.size() + 1, false);
		f[0] = true; // ���ַ���
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size()];
	}
};