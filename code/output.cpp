#include "template/template.h"
class Solution {
 public:
  vector<vector<int>> e;
  int n;
  vector<int> a;
  vector<int> val;
  int ck(int u, int x, int fa) {
    int ans = 0;
    int sum = 0;
    for (auto& v : e[u]) {
      if (v == fa) {
        continue;
      }
      int sr = ck(v, x, u);
      if (sr == -1) {
        return -1;
      }
      ans += sr;
      if (val[v]) {
        sum += val[v];
      }
      if (sum > x) {
        return -1;
      }
    }
    if (sum == x) {
      sum = 0;
      ++ans;
    }
    val[u] = sum;
    return ans;
  }
  void ckmax(int& x, int y) {
    if (x < y) {
      x = y;
    }
  }
  int run(int x) {
    fill(val.begin(), val.end(), 0);
    int r = ck(0, x, -1);
    if (r && val[0] == 0) {
      return r;
    }
    return 0;
  }
  int componentValue(vector<int>& _a, vector<vector<int>>& edges) {
    n = _a.size();
    int s = 0;
    for (auto& i : _a) {
      a.emplace_back(i);
      s += i;
    }
    e.resize(n);
    for (auto& i : edges) {
      int u = i[0];
      int v = i[1];
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
    int ans = 0;
    val.resize(n);
    for (int i = 1; i * i <= n; ++i) {
      if (n % i == 0) {
        run(i);
        if (i != n / i) {
          run(n / i);
        }
      }
    }
    return ans;
  }
};
Solution* solution;
Stopwatch stopwatch;
int main() {
	stopwatch.start();
	solution = new Solution();
	vector<int> var1{6,2,2,2,6};
	vector<vector<int>> var2{{0,1},{1,2},{1,3},{3,4}};
	print(solution->componentValue(var1, var2));
	delete solution;
	print("Runtime: " + to_string(stopwatch.end()) + " ms");

	stopwatch.start();
	solution = new Solution();
	vector<int> var3{2};
	vector<vector<int>> var4{};
	print(solution->componentValue(var3, var4));
	delete solution;
	print("Runtime: " + to_string(stopwatch.end()) + " ms");
}