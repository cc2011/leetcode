//
class Solution {
private:
    vector<vector<string> > ret;
public:
    bool valid(vector<vector<int> > &maxtrix, int row, int col, int n){
        int i, j;
		//�����û��ͬ�еģ�ֻҪ���֮ǰ�м��ɣ�
        for(i=0; i<row; i++)
            if(maxtrix[i][col])
                return false;
        //������϶Խ�
        i = row; j = col;
        while(i && j){
            if(maxtrix[--i][--j])
                return false;
		//������Ͻ�
        i = row; j = col;
        while(i && j<n-1){
            if(maxtrix[--i][++j]){
                return false;
        return true;
    }

	//������ȣ�����������̽�����ǵݹ����£�����ѭ����̽
	//���������̴�Сn����¼��ǰ������Ϣ��matrix����ǰ��������row
    void solveNQueens(int n, vector<vector<int> > &matrix, int row) {
        vector<string> v(n);
        string str;
		//DFS����ֹ����
        if(line == n){ //����Ѿ��ɹ����Ͱ�1��0�����Q��.
            for(int i=0; i<n; i++){
                str = "";
                for(int j=0; j<n; j++){
					str += (matrix[i][j] == 1? 'Q':'.');
                }
                v[i] = str;
            }
            ret.push_back(v);
			return;
        }
		//DFS���ģ��Ե�ǰ�е�ÿһ�н�����̽������Ϸ���������һ�еݹ�
        for(int j=0; j<n; j++){
            matrix[row].clear();
            if(valid(matrix, row, j, n)){ //�����ǰ�кϷ�
                matrix[line][j] = 1; //��ǰ�С�����Ϊ1
                solveNQueens(n, matrix, row+1); //�ݹ���һ��
                matrix[row][j] = 0;  //�����ǰ�С���
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        ret.clear();
        solveNQueens(n, matrix, 0);
        return ret;
    }
};