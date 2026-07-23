class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return res;
        
    }

    void helper(vector<int>& nums,int i){
            if(i==nums.size()){
                res.push_back(nums);
            }

            for(int j=i;j<nums.size();j++){
               swap(nums[i], nums[j]);   // Make a choice
               helper(nums, i + 1);      // Explore
               swap(nums[i], nums[j]);   // Undo the choice 
            }
    }
};