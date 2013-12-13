class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if(total & 0x1) { //������Ԫ��,ȡ�м�Ԫ��
            return find_kth(A, m, B, n, total/2 + 1);
        }
        else { //ż����Ԫ��,ȡ�м�����Ԫ�ص�ƽ��
            return (find_kth(A, m, B, n, total/2) + find_kth(A, m, B, n, total/2 + 1))/2;
        }
    }
private:
    double find_kth(int A[], int m, int B[], int n, int k) {
        if(m > n) return find_kth(B, n, A, m, k); //�ٶ�mС�ڵ���n
        if(m == 0) return B[k-1];
        if(k == 1) return min(A[0], B[0]);
        
        int pa = min(k/2, m), pb = k - pa; //���ַ��ı���
        if(A[pa-1] < B[pb-1]) { //ȥ��A��k/2��Ԫ�ػ���ȫ��
            return find_kth(A+pa, m-pa, B, n, k-pa);
        }
        else if(A[pa-1] > B[pb-1]) { //ȥ��B��k/2��Ԫ�ػ��߸����Ԫ��
            return find_kth(A, m, B+pb, n-pb, k-pb);
        }
        else {
            return A[pa-1];
        }
    }
}; 