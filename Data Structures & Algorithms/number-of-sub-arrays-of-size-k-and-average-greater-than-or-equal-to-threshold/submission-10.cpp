class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int N = arr.size();

        if (k > N) return 0;

        int L = 0, R = 0;
        int sum = 0;
        int target = k*threshold;

        while (R < k) {
            sum+=arr[R];
            R++;
        }
        int res = 0;
        if (sum >= target) res++;
        while (R < N) {
            sum-=arr[L];
            sum+=arr[R];
            
            if (sum >= target) {

                res++;
            }
            L++;
            R++;   
        }

        return res;
    }
};