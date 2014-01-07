class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        dfs(s, 0, 0, ip, res);
        return res;
    }
private:
    //start: ��s�����￪ʼ step: ��ǰip�κ�, ip: �м�ip���
    void dfs(string s, int start, int step, string ip, vector<string> &res){
        int len = s.length();
        //dfs��ֹ����
		if(len == start && step == 4){
            ip.resize(ip.size()-1); //ȥ�����һ��'.'
            res.push_back(ip);
            return;
        }
        
        //��֦:���ʣ���ִ�����̫��������̫�̣��Ͳ��ü�������
        if((len - start > (4-step)*3) || (len - start < 4 - step)){
            return;
        }
        //dfs���Ĵ���
		//ipһ��ֻ��3λ������ѭ��ֻ��3��
        int num = 0;
        for(int i=start; i<start+3; i++){
            num = num*10 + (s[i]-'0');
            ip += s[i]; //��ǰip
            if(num <= 255){ //����С�ڵ���255�������ǺϷ���ip��
                dfs(s, i+1, step+1, ip+'.', res); //�Ϸ�ip�κ����.������һ���ݹ�
            }
            if(!num) break;  //������0��������ǰ׺0
        }
    }
};