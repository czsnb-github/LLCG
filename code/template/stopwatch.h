#include <bits/stdc++.h>

using namespace std;

class Stopwatch {
  using clock_type = chrono::time_point<std::chrono::steady_clock>;
  clock_type startTimestamp;

  clock_type now() { return chrono::steady_clock::now(); }

 public:
  void start() { startTimestamp = now(); }
  int end() {
    // nanosecond
    auto diff = now() - startTimestamp;

    // ns to ms
    return diff.count() / 1e6;
  }
};