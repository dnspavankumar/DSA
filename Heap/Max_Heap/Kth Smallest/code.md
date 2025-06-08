# Kth Smallest Element - Explanation and Code

## Problem Statement
Given an array `arr` of integers and an integer `k`, find the k-th smallest element in the array.

---

## Approach Using Priority Queue (Max-Heap)

- We can use a **max-heap** (priority queue in C++ by default is a max-heap).
- Insert all elements of the array into the max-heap.
- Pop the largest element from the heap `k` times.
- After popping `k` times, the element at the top of the heap will be the k-th smallest element.

---

## Code Explanation

```cpp
class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // Create a max heap with all elements
        priority_queue<int, vector<int>> pq(arr.begin(), arr.end());
        
        // Pop k elements from the heap
        for (int i = 0; i < k; i++) {
            pq.pop();
        }
        
        // The top element now is the k-th smallest
        return pq.top();
    }
};
