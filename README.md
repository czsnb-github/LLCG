# Local Leetcode Code Generator (LLCG)

## Overview

Local Leetcode Code Generator (a.k.a., LLCG) is a code generator that generates LeetCode-style code to run locally.

Please contact me with any comments or suggestions.

## Quick Start

1. Place your LeetCode-style code into **code/input.cpp**
2. Place your test case into **code/input.txt** (copy and paste from LeetCode is recommended)
3. run `python main.py`
4. **code/output.cpp** can be run locally!

## Example

[Two_Sum](https://leetcode.cn/problems/two-sum/)

### Before

in **code/input.cpp**

```cpp
class Solution {
public:
    map<int, int> a;
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            int v = target - nums[i];
            if (a.count(v)) {
                ans = {i, a[v]};
                break;
            }
            a[nums[i]] = i;
        }
        return ans;
    }
};
```

in **code/input.txt** 

```
[2,7,11,15]
9
[3,2,4]
6
[3,3]
6
```

### After

in **code/output.cpp**

```cpp
#include "template/template.h"
class Solution {
 public:
  map<int, int> a;
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      int v = target - nums[i];
      if (a.count(v)) {
        ans = {i, a[v]};
        break;
      }
      a[nums[i]] = i;
    }
    return ans;
  }
};
Solution* solution;
int main() {
  solution = new Solution();
  vector<int> var1{2, 7, 11, 15};
  int var2{9};
  print(solution->twoSum(var1, var2));
  delete solution;
  solution = new Solution();
  vector<int> var3{3, 2, 4};
  int var4{6};
  print(solution->twoSum(var3, var4));
  delete solution;
  solution = new Solution();
  vector<int> var5{3, 3};
  int var6{6};
  print(solution->twoSum(var5, var6));
  delete solution;
}
```

build and run **code/output.cpp**, get following output

```
[1, 0]
[2, 1]
[1, 0]
```

Correct!

## TODO

+  More infrastructure for this project
+  User interface
+  Version management
