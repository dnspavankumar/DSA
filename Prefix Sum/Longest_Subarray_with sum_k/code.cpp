int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> prefix_sum(n+1,0);
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            prefix_sum[i+1] = prefix_sum[i]+arr[i];
        }
        
        int maximum_size=0;
        for(int i=0;i<n+1;i++){
            if(mp.count(prefix_sum[i]-k)){
                maximum_size=max(maximum_size,i-mp[prefix_sum[i]-k]);
            }
            //store only first occurences
            if(mp.find(prefix_sum[i]) == mp.end()) {
                mp[prefix_sum[i]] = i; 
            }
        }
        return maximum_size;
    }
