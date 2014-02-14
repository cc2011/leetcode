//ò��������ظ��Ĵ�Ҳһ����Ϊ��anagram��
//���ң�ֻҪ��anagramһ�ɴ浽vector�ﲻ�õ���˳������
//˼·���Ե�������Ȼ�����map�����map���У�����ͬ
//ԭ�еĴ�һ��push��vector
//���ɣ����map��ԭ��û�У���value����ǵ�һ�����ֵĴʵ�index
//����Ϊ���ҵ��ڶ�����ʱ����ͬ��һ��һ��浽vector��
//����Ѿ����ˣ��ʹ�-1������֮ǰ�Ѿ�����
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        int size = strs.size();
        vector<string> res;
        map<string, int> mp_anagram;
        for(int i=0; i<size; i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            map<string, int>::iterator it = mp_anagram.find(tmp);
            if(it == mp_anagram.end()){
                mp_anagram[tmp] = i;
            }
            else {
                if(mp_anagram[tmp] == -1) {
                    res.push_back(strs[i]);
                }
                else {
					//mp_anagram[tmp]����ǵ�һ���ʵ�index
                    res.push_back(strs[mp_anagram[tmp]]);
                    mp_anagram[tmp] = -1;
                    res.push_back(strs[i]);
                }
            }
        }
        return res;
    }
};