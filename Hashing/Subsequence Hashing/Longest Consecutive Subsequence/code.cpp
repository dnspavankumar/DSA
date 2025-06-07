class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int longest=0;
        for(int num:s){
            
            if(s.find(num-1)==s.end()){
                int curr=num;
                int streak = 1;
                while(s.find(curr+1)!=s.end()){
                    curr++;
                    streak++;    
                }
                longest = max(longest,streak);
            }
        }
        return longest;
    }
};
