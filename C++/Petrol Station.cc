/*
有一个很长的车道，长度为 M. 
在车道的某些位置有一些加油站，长度为n的数组int T[] 代表这些加油站的位置。
我们现在要增加k的新的加油站以便尽量缩短加油站之间的最大间隔. 
你只可以在整数位置放置加油站

Example: 
N = 5, M = 20, K = 3, T = [3, 7, 15, 18, 1] 
Answer: 3 (放置新加油站的位置: 5, 10 and 13)
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int help(vector<int>& diff, int start, int end, int k) {
	int k_local = k;
	int guess = (start + end) / 2;
	int res = 0;
	for (int i = 0; i < diff.size(); ++i) {
		int count = 1;
		while ((double)diff[i] / count++ > guess) {
			--k_local;
		}
		res = max(res, diff[i] / (count - 1));
	}
	if (!k_local || start == end) return res;
	if (k_local > 0) {
		end = guess;
	}
	else if (k_local < 0)
		start = guess + 1;

	cout << "(" << start << "," << end << ")" << endl;
	return help(diff, start, end, k);
}

int petrol_station(vector<int>& v, int len, int k) {
	sort(v.begin(), v.end());
	v.push_back(len);
	vector<int> diff(v.size());
	adjacent_difference(v.begin(), v.end(), diff.begin());
	return help(diff, 0, len, k);
}

int main() {
	vector<int> v = { 1, 4, 5, 9, 20 };
	cout << petrol_station(v, 20, 5) << endl;
	return 0;
}
