class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> cur;
        sort(nums.begin(),nums.end());
        helper(nums, target, cur, 0);
        return res;
    }

    void helper(vector<int>& nums, int target, vector<int>& cur, int i) {

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

        cur.push_back(nums[i]);
        helper(nums, target-nums[i], cur, i+1);
        cur.pop_back();
        int j=i;
        while(j+1<nums.size() && nums[j]==nums[j+1]){
            j++;
        }
        helper(nums, target, cur, j+1);
    }
};