class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++)
       {
            if(mp.count(target-nums[i]))
            {
                return {mp[target-nums[i]],i};
            }
            else
            {
                mp[nums[i]]=i;
            }
       }
       return {-1};
    }
};
