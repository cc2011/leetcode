/*
����stl��next_permutation����������ȥ�أ�
next_permutation��prev_permutationҪ���������Լ�ʵ��
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        do {
            result.push_back(num);
        } while(next_permutation(num.begin(), num.end()));
        result.erase(unique(result.begin(),result.end()), result.end());
        return result;
    }
};

/*
���ݷ������ڵ�LC�ϻᳬʱ�ˣ���ǰ����
*/
class Solution {
public:
    void permute(vector<vector<int> > &v_res, vector<int> num, int k, int len){
        if(k == len){
            v_res.push_back(num);
        }
        else{
            for(int i=k; i<=len; i++){
                swap(num[k], num[i]);
                permute(v_res, num, k+1, len);
                swap(num[k], num[i]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > v_res;
        permute(v_res, num, 0, num.size()-1);
		v_res.erase(unique(v_res.begin(),v_res.end()), v_res.end());
        return v_res;
    }
};