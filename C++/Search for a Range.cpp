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
����ʵ��lower_bound��upper_bound�㷨
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
	ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, T target) {
		while (first != last) {
			auto mid = first + distance(first, last)/2;
			if (*mid < target) first = ++mid; 
			else last = mid; //���ڸ�����һ�������ƶ�last
		}
		return first;
	}

	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, T value) {
		while (first != last) {
			auto mid = next(first, distance (first, last) / 2);
			if (*mid <= target) first = ++mid; // ��lower_bound ���˲�ͬ�����ڸ�С��һ�������ƶ�last
			else last = mid;
		}
		return first;
	}
};

Second try:

class Solution {
public:
    int findLowBound(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        int mid;
        while(start <= end) {
            mid = (start + end)/2;
            if(A[mid] < target) {
                start = mid + 1;
            }
            else if(A[mid] > target) {
                end = mid - 1;
            }
            else {
                if(mid == start || A[mid] != A[mid-1]) {
                    return mid;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
    int findHighBound(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        int mid;
        while(start <= end) {
            mid = (start + end)/2;
            if(A[mid] < target) {
                start = mid + 1;
            }
            else if(A[mid] > target) {
                end = mid - 1;
            }
            else {
                if(mid == end || A[mid] != A[mid+1]) {
                    return mid;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(int A[], int n, int target) {
        int start, end;
        vector<int> res;
        start = findLowBound(A, n, target);
        end = findHighBound(A, n, target);
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};