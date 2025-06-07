# Pascal's Triangle

## Binomial Coefficient Method

If row and column are given:

**Element at (row, col)** =  
(row-1)C(col-1)

Where:
- `r` is the row number (1-indexed),
- `c` is the column number (1-indexed),
- nCk is the binomial coefficient "n choose k".

---

## Iterative Formula (Using Previous Element)

If the **previous element** in the same row is known, the **next element** can be found using:

```cpp
next_element = previous_element * (row - col) / (col + 1);
```

Where:
- `row` is the current row number (0-indexed),
- `col` is the index of the current element in that row (0-indexed),
- `previous_element` is the element at index `col - 1`.
