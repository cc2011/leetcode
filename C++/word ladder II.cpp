/*
��һ���work ladder����������Ҫ��һ��map��¼ladder��·��
���map���õĺ����key��string����ǰ�ڵ㣬
value��һ��vector<string>������¼����Щ�ڵ���Ե���ǰ�ڵ�

*/
class Solution {
	public:
	vector<vector<string> > findLadders(string start, string end,
		const unordered_set<string> &dict) {
		unordered_set<string> visited; // ����
		unordered_map<string, vector<string> > father; // ��
		unordered_set<string> current, next; // ��ǰ�㣬��һ�㣬�ü�����Ϊ��ȥ��
		bool found = false;
		current.insert(start);
		while (!current.empty() && !found) {
			// �Ƚ�����ȫ����Ϊ�ѷ��ʣ���ֹͬ��֮�以��ָ��
			for (auto word : current)
				visited.insert(word); 
			for (auto word : current) { //�Ե�ǰ��ÿ�����ʱ���
				for (size_t i = 0; i < word.size(); ++i) {
					string new_word = word;
					//�滻�ַ����������ַ������ж��Ƿ���dict��
					for (char c = 'a'; c <= 'z'; ++c) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]);
						if (new_word == end) {
							found = true; //�ҵ���, ����Ҫ�ŵ�next������
							father[new_word].push_back(word);
							break;
						}
						if (visited.count(new_word) == 0
						&& (dict.count(new_word) > 0 || new_word == end)) {
							next.insert(new_word);
							father[new_word].push_back(word);
						}
						swap(c, new_word[i]); // restore
					}
				}
			}
			current.clear();
			swap(current, next);
		}
		vector<vector<string> > result;
		if (found) {
			vector<string> path;
			buildPath(father, path, start, end, result);
		}
		return result;
	}
	private:
	//��father����·��
	//param: father����ÿ���ڵ�ĸ��ڵ���У�path��
	//result�����������ս��(��start��end��·��)��
	void buildPath(unordered_map<string, vector<string> > &father, vector<string> &path,
			 const string &start, const string &word, vector<vector<string> > &result )
	{
		path.push_back(word);
		if (word == start) {
			result.push_back(path); //����ŵ�result���
			//����Ƿ��ģ�����Ҫ����
			reverse(result.back().begin(), result.back().end());
		} 
		else {
			for (auto f : father[word]) { //�ѽڵ��ÿ��father�������
				buildPath(father, path, start, f, result);
			}
		}
		path.pop_back();
	}
};