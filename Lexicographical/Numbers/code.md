# Lexicographical Numbers in O(n) Time and O(1) Extra Space

## Logic

To print numbers from 1 to n in lexicographical order efficiently:

- We start with the number 1.
- At each step, try to go deeper by multiplying the current number by 10 (e.g., 1 → 10 → 100), as this moves us lexicographically to the next prefix.
- If multiplying by 10 exceeds n, we try to increment the current number by 1 (e.g., 10 → 11).
- If the incremented number exceeds n or ends with a zero digit, we remove trailing zeros by dividing by 10 until the last digit is not zero.
- Repeat the process until all numbers up to n are generated.

This approach mimics a depth-first traversal on the prefix tree of numbers and guarantees O(n) time complexity and O(1) extra space besides the output list.

---

## Code Snippet (C++)

```cpp
#include <vector>
using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> result;
    int curr = 1;
    for (int i = 0; i < n; i++) {
        result.push_back(curr);
        if (curr * 10 <= n) {
            curr *= 10;
        } else {
            if (curr >= n) curr /= 10;
            curr++;
            while (curr % 10 == 0) {
                curr /= 10;
            }
        }
    }
    return result;
}
