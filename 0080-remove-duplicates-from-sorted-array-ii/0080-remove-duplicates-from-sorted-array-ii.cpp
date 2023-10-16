class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         bool inARow = false;
        int index = 1;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i+1] > nums[i]){
                inARow = false;
                nums[index++] = nums[i+1];
            }
            else if(nums[i+1] == nums[i] && inARow == false){
                inARow = true;
                nums[index++] = nums[i+1];
            }
        }

        return index;
        
    }
};