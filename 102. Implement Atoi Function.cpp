#include <bits/stdc++.h> 
int atoi(string str) {
  int res = 0;
  for (auto i : str) {
    if (isdigit(i))
        res = (res * 10) + (i - '0');
  }

  return str[0] == '-' ? -res : res;
}