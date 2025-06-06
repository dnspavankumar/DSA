class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
          //skip duplicates of i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];

                if(sum==0){
                   ans.push_back({nums[i], nums[start], nums[end]});
                  //skip duplicates of start and end
                   while (start < end && nums[start] == nums[start + 1])start++;
                   while (start < end && nums[end] == nums[end - 1]) end--;
                   start++;
                   end--;

                }
                else if(sum<0){
                    start++;
                }
                else{
                    end--;
                }
            }
        }
        return ans;
    }
};
