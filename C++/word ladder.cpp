/*
��Ҫȥ��ÿ�����ʲ�ʵ����Ƿ��о���Ϊ1�ĵ���
����Ҫȥ����õ��ʾ���Ϊ1�ĵ����Ƿ��ڴʵ���

����BFS��current�ǵ�ǰ����У�next����һ�����
��΢�޸���д�����о��ȴ����ڰ�ĺ����һ���
*/
class Solution {
public:
int ladderLength(string start, string end,
	const unordered_set<string> &dict) {
		if (start.size() != end.size()) return 0;
		if (start.empty() || end.empty()) return 0;
		queue<string> current, next; // ��ǰ�㣬��һ��
		unordered_set<string> visited; // ����
		int level = 0; // ���
		bool found = false;
		current.push(start);
		while (true) { //���϶�ÿ�����
			++level;
			while (!current.empty() && !found) { //�Ե�ǰ���е����е��ʱ���
				const string str(current.front()); //ȡ������ͷ
				current.pop();
				for (size_t i = 0; i < str.size(); ++i) {
					string new_word(str);
					//ͨ���ı�һ���ַ����õ�һ���µ��ַ���
					for (char c = 'a'; c <= 'z'; c++) {
						if (c == new_word[i]) continue;
						swap(c, new_word[i]); //����һ����ͬ���ַ�
						if (new_word == end) {
							found = true; //�ҵ���
							break;
						}
						if (dict.count(new_word) > 0 //����ֵ������������
							&& !visited.count(new_word)) { //�����������֮ǰû���ʹ�
							next.push(new_word); //�Ѹõ���push��next����
							visited.insert(new_word); //���Ϊ���ʹ�
						}
						swap(c, new_word[i]); // �ָ��õ���
					}
				}
			}
			if(!next.empty() && !found)
				swap(next, current); //!!! ������������
			else break;
		}
		if (found) return level+1;
		else return 0;
	}
};
