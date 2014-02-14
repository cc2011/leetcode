//���ַ����ҵı���, ʱ�临�Ӷ�log n
//�ֱ����۸������
//����ͨ���ֲ��ҵ������ǣ���ͨ���ַ�ֻ��Ҫ��target��midλ�õ����ȽϾͿ����ų�һ��Ԫ��
//�����������жϳ��Ǳ��������ĶΣ�Ȼ���ж�target�Ƿ��������Ķ��У������ų�һ��Ԫ��
//��Ϊ������õ������ĶΣ���û�������ж�
class Solution {
public:
	int search(int A[], int n, int target) {
		int first = 0, last = n;
		while (first != last) {
			const int mid = (first + last) / 2;
			if (A[mid] == target)
				return mid;
			//������������
			if (A[first] <= A[mid]) {
				//�ж�target�Ƿ������
				if (A[first] <= target && target < A[mid])
					last = mid;
				else
					first = mid + 1;
			} 
			//�ұ���������
			else {
				//�ж�target�Ƿ����Ҷ�
				if (A[mid] < target && target <= A[last-1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};