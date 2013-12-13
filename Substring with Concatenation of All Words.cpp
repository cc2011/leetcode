class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once.  
        map<string,int> words, cur;  
        vector<int> res; 
        int wordNum = L.size();  
        if(!wordNum) return res;
		int wordLen = L[0].size();
        if(S.size() < wordLen*wordNum)return res; 

        for(int i = 0; i < wordNum; i++)  
            words[L[i]]++;  //��¼��ÿ�����ʳ��ֵĸ���

        for(int i = 0; i <= (int)S.size()-wordLen*wordNum; i++)  
        {  
            cur.clear(); //������ŵ�ǰ�Ĳ������
            int j;  
            for(j = 0; j < wordNum; j++)  
            {  
                string word = S.substr(i+j*wordLen, wordLen);  
                if(words.find(word) == words.end())  //�Ҳ���
                    break;  
                cur[word]++;  
                if(cur[word]>words[word]) //ĳ���ʳ��ֵĴ�������
                    break;  
            }  
            if(j == wordNum)  
                res.push_back(i);  
        }  
        return res; 
    }
}; 