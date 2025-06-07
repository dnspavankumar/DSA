# Set Matrix Zeroes - Brute Force Approach

## Algorithm Steps

1. **Record Zero Positions**  
   Traverse the matrix to collect positions `(i, j)` where `matrix[i][j] == 0`.

2. **Set Rows and Columns to Zero**  
   For each recorded position, set its entire row and column to `0`.

---

## Code

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> s;
        
        // Step 1: Record positions of all zeroes
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    s.push_back({i, j});
                }
            }
        }

        // Step 2a: Zero out the rows of all recorded positions
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[s[i][0]][j] = 0;
            }
        }

        // Step 2b: Zero out the columns of all recorded positions
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][s[i][1]] = 0;
            }
        }
    }
};
