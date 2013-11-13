//using binary search
class Solution {
public:
    int searchInsert( int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int head = 0, tail = n-1, mid;
        if(! n || target < A[0]) return 0; 
        if( target > A[ n-1]) return n;
        while(1) {
            if( A[head] == target){
                return head;
            }
            if( A[tail] == target){
                return tail;
            }
			//mid = ((head+tail+1)>>1);
            //if(mid == tail) return tail;
            mid = ((head+tail)>>1);
            if(mid == head) return tail;
            if( A[mid] <= target){
                head = mid;
            }
            else {
                tail = mid;
            }
        }
    }
};