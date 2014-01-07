//��̬�滮
//���һ�г������ϰ��Ҫ���ϰ��ﴦ��Ϊ0�������λ�ü��㷽������
//�Ե�һ�е�һ�е���������
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int height = obstacleGrid.size();
        if(!height){
            return 0;
        }
        int width = obstacleGrid[0].size(), valid = 1;
        vector<int> pathNum;
        if(obstacleGrid[0][0] || obstacleGrid[height-1][width-1]) return 0;
        for(int i=0; i<width; i++){ //�����һ��,ֻҪ�����ϰ������ȫΪ0
            if(obstacleGrid[0][i]){
                valid = 0;
            }
            pathNum.push_back(valid);
        }
        valid = 1;
        for(int i=1; i<height; i++){
            if(obstacleGrid[i][0]) valid = 0;
            pathNum[0] = valid;
            for(int j=1; j<width; j++){
                if(obstacleGrid[i][j]) pathNum[j] = 0;
                else pathNum[j] = pathNum[j] + pathNum[j-1];
            }
        }
        return pathNum[width-1];
    }
};