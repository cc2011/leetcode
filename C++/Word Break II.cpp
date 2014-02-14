class Solution {
public:
	//��word break������prev��¼����Щλ�ÿ��Էִʳ���
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		// ����Ϊn ���ַ�����n+1 ������
		vector<bool> f(s.length() + 1, false);
		// prev[i][j] Ϊtrue����ʾs[j, i) ��һ���Ϸ����ʣ����Դ�j ���п�
		// ��һ��δ��
		vector<vector<bool> > prev(s.length() + 1, vector<bool>(s.length()));
		/*DP, ��״̬Ϊf(i)����ʾ�ַ���s�ӵ�0������i���ַ�֮ǰ�Ǹ�λ���Ƿ���Էִʣ�
		״̬ת�Ʒ���Ϊ��
		f(i) = any_of(f(j)&&s[j, i) �� dict ��); 0 <= j < i
		*/
		f[0] = true; // ���ַ���
		for (size_t i = 1; i <= s.length(); ++i) { //�ӵ�һ���ָ���β��Ԫ��
			for (int j = i - 1; j >= 0; --j) {
				if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
					f[i] = true; //���ֵ�i��λ��ǰ�ִܷ���ȻҪ��̽������λ��
					prev[i][j] = true; //��j��iǰ��λ����һ��dict�еĵ���
				}
			}
		}
		vector<string> result;
		vector<string> path;
		gen_path(s, prev, s.length(), path, result);
		return result;
	}
private:
	// DFS ������������·��
	void gen_path(const string &s, const vector<vector<bool> > &prev,
		int cur, vector<string> &path, vector<string> &result) {
		if (cur == 0) {
			string tmp;
			//push��ʱ��������ģ������������
			for (auto iter = path.crbegin(); iter != path.crend(); ++iter){
				tmp += *iter + " ";
			}
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}
		for (size_t i = 0; i < s.size(); ++i) {
			if (prev[i][cur]) { //�����s[cur, i)��һ��dict�еĵ���
				path.push_back(s.substr(i, cur - i)); //�Ѹõ�����ջ
				gen_path(s, prev, i, path, result); //���ַ���ʣ�ಿ�ֵݹ�
				path.pop_back(); //��ԭ�ֳ�
			}
		}
	}
};