My solution:
//�ܼ򵥣���carry���ϵĽ�λ���������Ҫ��λ�ͷ��ؼ��ɣ�
//���һֱ��Ҫ��λ��������ڿ�ͷ�����1
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        int carry = 1;
        for(int i=len-1; i>=0; i--){
            digits[i] += carry;
            if(digits[i] >= 10){
                digits[i] %= 10;
            }
            else{
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};