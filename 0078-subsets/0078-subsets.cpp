class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Initialize a 2D vector to store the subsets.
        vector<vector<int>> ans;
        // Initialize a temporary vector to store subsets during recursion.
        vector<int> v;
        // Start the recursion from index 0.
        recursion(ans, v, nums, 0);
        // Return the resulting subsets.
        return ans;
    }

    // Recursive function to generate subsets.
    void recursion(vector<vector<int>> &ans, vector<int>& v, vector<int>& nums, int i) {
        // If we have processed all elements in nums, add the current subset to ans.
        if (i == nums.size()) {
            ans.push_back(v);
            return;
        } 
        
        // Include the current element in the subset.
        v.push_back(nums[i]);
        // Recursively generate subsets with the current element included.
        recursion(ans, v, nums, i + 1);
        
        // Exclude the current element from the subset (backtrack).
        v.pop_back();
        // Recursively generate subsets with the current element excluded.
        recursion(ans, v, nums, i + 1);
        
    }
};