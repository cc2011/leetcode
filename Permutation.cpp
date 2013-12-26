First Try:
//���ý�����DFS
class Solution {
public:    
    void permute(vector<vector<int> > &v_res, vector<int> &num, int k, int len){
        vector<int> v;
        if(k == len){
            for(int i=0; i<=len; i++){
                v.push_back(num[i]);
            }
            v_res.push_back(v);
        }
        else{
            for(int i=k; i<=len; i++){ 
                swap(num+k, num+i); //��k��Ԫ�ظ������������Ԫ��(����k)���ν���
                permute(v_res, num, k+1, len);
                swap(num+k, num+i); //���ν�������
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > v_res;
        permute(v_res, num, 0, num.size()-1);
        return v_res;
    }
};

Second Try:
//����next_permutation
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        return result;
    }
};