class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>>ans;
      for(int r = 0 ;r<numRows;r++){
        vector<int>row;
        int res = 1;
        for(int c=0;c<=r;c++){
            row.push_back(res);
            res*=r-c;
            res/=c+1;
        }
        ans.push_back(row);
      }
      return ans;
    }
};
