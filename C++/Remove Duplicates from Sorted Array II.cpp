//��һ��������¼���ֵĴ���
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int index = 1, count = 1, len = 1;
        if(!n) return 0;
        for(int i=1; i<n; i++) {
            if(A[i]!=A[i-1]) {
                count = 1;
                A[index++] = A[i];
                len++;
            }
            else if(count < 2) {
                A[index++] = A[i];
                count++;
                len++;
            }
            else {
                count++;
            }
        }
        return len;
    }
};