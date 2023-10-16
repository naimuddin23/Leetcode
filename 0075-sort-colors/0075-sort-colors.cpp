class Solution {
public:
    void sortColors(vector<int>& nums) {
        int leftIndex =0;
        int rightIndex = nums.size() -1 ;
        int iterator =0;

        while(iterator <= rightIndex)
        {
            if(nums[iterator] == 0)
            {
                swap(nums[leftIndex], nums[iterator]);
                leftIndex++;
                iterator++;
            }
            else if(nums[iterator] == 2)
            {
                swap(nums[iterator] , nums[rightIndex]);
                rightIndex--;
            }
            else
            {
                iterator++;
            }
        }
        
    }
};