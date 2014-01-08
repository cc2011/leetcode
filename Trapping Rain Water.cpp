class Solution {
public:
    int trap(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int maxIdx=0, max=A[0], max_bar, rain = 0;
        //��ȡ����λ��
        for(int i=1; i<n; i++){
            if(A[i] > max){
                max = A[i];
                maxIdx = i;
            }
        }
        //���ƽ�
        max_bar = A[0];
        for(int i=1; i<maxIdx; i++){
            if(A[i] < max_bar){
                rain += (max_bar - A[i]);
            } 
            else{
                max_bar = A[i];
            }
        }
        //�Ҳ�ƽ�
        max_bar = A[n-1];
        for(int i=n-2; i>maxIdx; i--){
            if(A[i] < max_bar){
                rain += (max_bar - A[i]);
            } 
            else{
                max_bar = A[i];
            }
        }
        return rain;
    }
};