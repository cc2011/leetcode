//̰�ķ���ÿ�������ߵ���Զ��һ��
class Solution {
public:
    int jump(int A[], int n) {
        int longest, step = 1;
        int i = 0;
        if(n <= 1){
            return 0;
        }
        longest = A[0];
        while(longest < n-1 && i < n) {
            int l = longest;
            while(i <= l){
                if(i+A[i] > longest){
                    longest = i+A[i];
                }
                i++;
            }
            step++;
        }
        return step;
    }
};