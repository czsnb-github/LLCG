#ifndef OUTPUT_H
#define OUTPUT_H

#include <bits/stdc++.h>
using namespace std;

template <class T>
void __print(T&& x) {
  cout << x;
}
template <class T>
void __print(vector<T> x) {
  if (x.size() == 0) {
    cout << "[]";
    return;
  }
  bool first = true;
  for (auto& i : x) {
    cout << (first ? "[" : ", ");
    __print(i);
    first = false;
  }
  cout << ']';
}
template <class T, class... Ts>
void __print(T&& first, Ts&&... others) {
  __print(first);
  cout << ' ';
  __print(forward<Ts>(others)...);
}
template <class... T>
void print(T&&... x) {
  cout << setprecision(16);
  cout << boolalpha;
  __print(forward<T>(x)...);
  cout << endl;
}

#endif  // OUTPUT_H