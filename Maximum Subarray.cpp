//��¼�µ�ǰsum��С��0����Ժ����޹��ף�����
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, m;
        if(n == 0) return 0;
        m = A[0];
        for(int i=0; i<n; i++) {
            sum = max(sum, 0);
            sum += A[i];
            m = max(sum, m);
        }
        return m;
    }
};