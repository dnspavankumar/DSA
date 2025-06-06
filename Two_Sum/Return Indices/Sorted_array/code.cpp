class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n=arr.size();
        int left= 0 ;
        int right=n-1;
        while(left<right){
            int sum=arr[left]+arr[right];
            if(sum==target)return{left+1,right+1};
            else if(sum<target)left++;
            else right--;
        }
        return {-1};
    }
};
