                                                 

//Fast IO
static auto magic = []() {ios_base::sync_with_stdio(false); cin.tie(nullptr); return false;}();

class Solution {
public:
	int p = 1000000007;
	
	int kConcatenationMaxSum(vector<int>& arr, int k) {
		long long ans = 0;
		long long maxsofar = 0;
		long long sum = 0;
		
		//for k == 1 kadane's algo
		for (int i = 0; i<arr.size(); i++) {
			sum += arr[i];
			if(sum >= p)
				sum %= p;
			maxsofar += arr[i];
			if(maxsofar >= p)
				maxsofar %= p;
			if(maxsofar < 0)
				maxsofar = 0;
			else
				ans = max(ans, maxsofar);
		}
		
		if(k == 1)
			return ans;
		
		long long ans1 = ans;
		
		//try for two arrays concatenated
		for (int i = 0; i<arr.size(); i++) {
			maxsofar += arr[i];
			if(maxsofar >= p)
				maxsofar %= p;
			if(maxsofar < 0)
				maxsofar = 0;
			else
				ans = max(ans, maxsofar);
		}
		
		//compute three values that can possibly be the answers
		long long res = max(ans1, ans);
		if(sum > 0)
			res = max(res, ((ans + ((sum * (k-2))%p))%p));
			
		//return the answer
		return res;
	}
};
