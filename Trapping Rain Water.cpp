/*
���ֽⷨ��
����ÿ�����ӣ��ҵ�������������ߵ����ӣ������������ɵ�ˮ����
min(max_left,max_right) - height�����ԣ�
1. ��������ɨ��һ�飬����ÿ�����ӣ���ȡ������ֵ��
2. ��������ɨ��һ�飬����ÿ�����ӣ��������ֵ��
3. ��ɨ��һ�飬��ÿ�����������ɵ�ˮ�ۼ�����������
Ҳ���ԣ�
1. ɨ��һ�飬�ҵ���ߵ����ӣ�������ӽ������Ϊ���룻
2. �������һ�룻
3. �����ұ�һ�롣
*/
class Solution {
public:
    int trap(int A[], int n) {
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