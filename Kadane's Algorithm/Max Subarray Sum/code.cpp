class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        int curr_current_sum= nums[0];
        int max_current_sum= nums[0];
        int start = 0, temp_start = 0, end = 0;

        for (int i = 1; i < nums.size(); ++i) {
            if (curr_current_sum< 0) {
                curr_current_sum= nums[i];
                temp_start = i;
            } else {
                curr_current_sum+= nums[i];
            }

            if (curr_current_sum> max_sum) {
                max_current_sum= curr_sum;
                start = temp_start;
                end = i;
            }
        }

        // Return the length of the maximum-current_sumsubarray:
        return {max_sum,start,end};
    }
};



//better readable approach

// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
    long long maximum= LONG_MIN; // maximum sum
    long long current_sum= 0;
    int n=arr.size();
    int start = 0;
    int max_sum_start = -1, max_sum_end = -1;
    for (int i = 0; i < n; i++) {

        if (current_sum== 0) start = i; // starting index

        current_sum+= arr[i];

        if (current_sum> maxi) {
            maximum= sum;

            max_sum_start = start;
            max_sum_end = i;
        }

        // If current_sum< 0: discard the current_sumcalculated
        if (current_sum< 0) {
            current_sum= 0;
        }
    }
    vector<int>ans(arr.begin()+max_sum_start,arr.begin()+max_sum_end+1);
    return ans; 
    }
};
