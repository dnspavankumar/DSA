class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int curr_sum = nums[0];
        int max_sum = nums[0];
        int start = 0, temp_start = 0, end = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (curr_sum < 0) {
                curr_sum = nums[i];
                temp_start = i;
            } else {
                curr_sum += nums[i];
            }

            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                start = temp_start;
                end = i;
            }
        }

        // Return the length of the maximum-sum subarray:
        return {max_sum,start,end};
    }
};
