class Solution {
private:
    vector<int> pre;
    vector<int> post;
public:
    int pivotIndex(vector<int>& nums) {
        int N = nums.size();
        pre.assign(N+1, 0);
        post.assign(N+1,0);

        for (size_t l = 0; l < N; l++) {
            int r = N - l;
            pre[l+1] = pre[l] + nums[l];
            post[r-1] = post[r] + nums[r-1];
        }

        for (size_t i = 0; i < N; i++) {
            cout << pre[i] << " " << post[i+1] << endl;
            if (pre[i] == post[i+1]) return i;
        }


        // for (auto e: pre) {
        //     cout << e << " ";
        // }
        // cout << endl;

        // for (auto e: post) {
        //     cout << e << " ";
        // }
        // cout << endl;
        return -1;
    };

    
};