//ʡ�ռ��ˣ�ֻ��һ������Ϊn�������¼ÿ��ѡ���кţ���Ȼ��vectorҲ����
//�о�N-QueensҲ������������ʡ�ռ䣬�����ٶȿ��ܸ���

class Solution {
public:
	//��������ǰ��row����¼ÿ�з����кŵ�����colArray
    bool check(int row, int* colArray) {  
		//����֮ǰ�еķ����������鵱ǰ
        for (int i = 0; i < row; ++i) {  
            int diff = abs(colArray[i] - colArray[row]); //diff��¼�кŲ�
            if (diff == 0 || diff == row - i) {          // int a row or line  
                return false;  
            }  
        }  
        return true;  
    }  
  
    void placeQueens(int row, int n, int &count, int* colArray) {  
        if (row == n) {  
            ++count;  
            return;  
        }  
          
        for (int col = 0; col < n; ++col) {  
            colArray[row] = col;  //����ÿ��
            if (check(row, colArray)){ //����Ϸ������µݹ�
                placeQueens(row+1, n, count, colArray);  
            }  
        }  
    }  
      
    int totalNQueens(int n) {  
        int *colArray = new int[n];  
        int count = 0;            
        placeQueens(0, n, count, colArray);            
        return count;  
    } 
};