class Solution {
public:
    void swap(vector<int> &num, int i, int j)  
    {  
        int temp = num[i];  
        num[i] = num[j];  
        num[j] = temp;  
    } 
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size(), index = -1;
        //�Ӻ���ǰ�ҳ��ֵĵ�һ���������е����ԣ���һ����������ԣ�
        for(int i=len-2; i>=0; i--){
            if(num[i] < num[i+1]){
                index = i;//��¼�½�С����λ��
                break;
            }
        }
        if(index == -1){
            sort(num.begin(),num.end());
            return;
        }
        //��˳�����Ժ�����С���Ǹ����ڽ�С������������С������
        for(int i=len-1; i>index; i--){
            if(num[i]>num[index]){
                swap(num, index, i);
                break;              //�ǵ�Ҫbreak������WA��һ��
            }
        }
        sort(num.begin()+index+1, num.end());
    }
};