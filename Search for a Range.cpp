/*
����һ��
����STL��lower_bound��upper_bound��distance����
*/
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		const int l = distance(A, lower_bound(A, A + n, target));
		const int u = distance(A, prev(upper_bound(A, A + n, target)));
		if (A[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
};

/*
��������
�Լ�ʵ��lower_bound��upper_bound�㷨
*/
class Solution {
public:
	vector<int> searchRange (int A[], int n, int target) {
		auto lower = lower_bound(A, A + n, target);
		auto uppper = upper_bound(lower, A + n, target);
		if (lower == A + n || *lower != target)
			return vector<int> { -1, -1 };
		else
			return vector<int> {distance(A, lower), distance(A, prev(uppper))};
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance(first, last) / 2);
			if (value > *mid) first = ++mid;
			else last = mid;
		}
		return first;
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance (first, last) / 2);
			if (value >= *mid) first = ++mid; // ��lower_bound ���˲�ͬ
			else last = mid;
		}
		return first;
	}
};

/*
���Լ��ķ�����

*/
class Solution {
public:
    void searchRange(vector<int> &v, int A[], int cur, int n, int target){
        for(int i=cur; i>=0; i--){
            if(A[i] == target){
                v[0] = i;
            }
            else{
                break;
            }
        }
        for(int i=cur; i<n; i++){
            if(A[i] == target){
                v[1] = i;
            }
            else{
                break;
            }
        }
        return;
    }
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        int head = 0, tail = n-1, cur=(head+tail)>>1;
        v.resize(2);
        v[0] = v[1] = -1;
        if(n==0) {
            return v;
        }
        if(n==1 && A[0] == target){
            v[0] = v[1] = 0;
            return v;
        }
        while(head < tail){
            if(cur == head || cur == tail){
                if(A[head] == target){
                    cur = head;
                }
                else if(A[tail] == target){
                    cur = tail;
                }
                searchRange(v,A,cur,n,target);
                return v;
            }
            if(A[cur] > target){
                tail = cur;
            }
            else if(A[cur] < target){
                head = cur;
            }
            else{
                searchRange(v,A,cur,n,target);
                return v;
            }
            cur = (head+tail)>>1;
        }
        return v;
    }
};