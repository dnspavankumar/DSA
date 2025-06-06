

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int>ans;
        int n=arr.size();
        int right_max=arr[n-1];
        ans.push_back(right_max);
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]>=right_max){
                ans.push_back(arr[i]);
                right_max=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
