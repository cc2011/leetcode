//��ʼ���Ӵ������ˣ�Ȼ���ö̵����м��ƶ�
//��������������ݻ���ֱ������������ͷ
class Solution {
public:
    int maxArea(vector<int> &height) {
        int len = height.size(), res = 0;
        int i = 0, j=len-1;
        while(i<j){
            res = max(res, min(height[i],height[j])*(j-i));
            height[i]>height[j]? j--:i++;
        }
        return res;
    }
};