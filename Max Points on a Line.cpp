/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = points.size();
        unordered_map<float, int> mp;
        int max = 0;
        for(int i=0; i<size; i++){
            int duplicate = 1;
            mp.clear();       //��ֹ�ظ���������  
            mp[INT_MIN] = 0;  //��ֹ����ֻ��һ��������
            for(int j = i+1; j<size; j++){
                float k;
                //�����غϵ���
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    duplicate++;
                    continue;
                }
                //����б��
                if(points[i].x == points[j].x){
                    k = INT_MAX;   //����0��Ϊ����
                }
                else{
                    k = (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                }
                mp[k]++;
            }
            unordered_map<float, int>::iterator it = mp.begin();
            for(; it != mp.end(); it++){
                max = it->second + duplicate > max?it->second + duplicate : max;
            }
        }
        return max;
    }
};