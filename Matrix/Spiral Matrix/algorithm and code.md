# Spiral Order Traversal of a Matrix

This algorithm prints all elements of a 2D matrix in **spiral order**, starting from the top-left corner and moving rightward, downward, leftward, and upward repeatedly.

## Algorithm Steps

1. **Initialize boundaries**: `top`, `bottom`, `left`, `right`
2. **Traverse in spiral fashion** while boundaries are valid:
   - Move left → right across the top row.
   - Move top → bottom along the right column.
   - Move right → left across the bottom row (only if still within bounds).
   - Move bottom → top along the left column (only if still within bounds).

## Code

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        int top = 0, bottom = matrix.size() - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            // Traverse from Left to Right
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse from Top to Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Traverse from Right to Left (if still within bounds)
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse from Bottom to Top (if still within bounds)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
