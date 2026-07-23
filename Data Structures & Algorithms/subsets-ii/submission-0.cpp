
//in backtracking whenever u want to remove duplicates first sort and then remove repeating elements side by side






class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // This will store all the subsets
        vector<vector<int>> res;

        // Stores the current subset being built
        vector<int> subset;

        // Start recursion from index 0
        sort(nums.begin(),nums.end());
        helper(nums, 0, subset, res);

        return res;
    }

    void helper(vector<int>& nums, int i,vector<int>& subset,vector<vector<int>>& res) {

        // Base Case:
        //if tracking has reached the end
        //add the answer to the result and proceed
        if (i == nums.size()) {                                   
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);      // Add current element
        helper(nums, i + 1, subset, res); // Recurse for next index

        // Backtracking:
        // Remove the element before exploring the next choice
        subset.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        helper(nums, i + 1, subset, res);
    }
};