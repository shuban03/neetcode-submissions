class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        helper(nums, target, cur, 0);
        return res;
    }

    void helper(vector<int>& nums, int target, vector<int>& cur, int i) {

        // Base case: target achieved
        if (target == 0) {
            res.push_back(cur);   
            return;
        }

        // Base case:
        // 1. Target exceeded
        // 2. No more numbers left
        if (target < 0 || i >= nums.size()) {
            return;
        }

        // Choose current number
        cur.push_back(nums[i]);
        helper(nums, target - nums[i], cur, i); //stay at same index(can be used multiple times)
        cur.pop_back();
        helper(nums, target, cur, i + 1);    //go to next index
    }
};