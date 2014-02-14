/*
˼·��O(nƽ��)�ķ�������ÿ������зָ�����������ߵ�����������
O(n)�ķ������������������㿪ʼ��ÿ�����������������������ÿ���㿪ʼ���յ���������
�����͵ó�����������Ե�i����зָi�㲻����ͬʱΪǰ�ε��յ�ͺ�ε���㣬���Բ��õ���
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) 
	{
		vector<int> profit(prices.size());
		int min_price = INT_MAX;
		//�ȵõ������ҵ��������(���̶�)
		for (int i = 0; i < prices.size(); i++) {
			if (prices[i] < min_price) min_price = prices[i]; //����������Сprice
			profit[i] = max(profit[i], prices[i]-min_price); //�����������
		}
		//�ٵõ����ҵ�����������(�յ�̶�)
		int max_price = INT_MIN , max_profit = 0, res = 0;
		for (int i = prices.size() - 1; i >= 0 ; i--) {
			if (prices[i] > max_price) max_price = prices[i]; //�����������price
			else max_profit = max(max_profit, max_price - prices[i]); //�����������
			res = max(profit[i]+ max_profit, res); 
		}
		return res;
	}
};