//  This file is part of Empirical, https://github.com/devosoft/Empirical
//  Copyright (C) Michigan State University, 2016-2018.
//  Released under the MIT Software license; see doc/LICENSE

#include <algorithm>

#include "emp/base/vector.hpp"

int main()
{
  // Try out a regular vector
  emp::vector<int> v;
  for (int i = 0; i < 10; i++) v.push_back( 100 - 10*i );

  v.insert(v.begin() + 3, -1);

  for (auto x : v) std::cout << x << ' ';
  std::cout << '\n';

  // Examine vector<bool> specialization.
  emp::vector<bool> vb(1000,false);
  for (size_t i = 0; i < vb.size(); i++) {
    if (i%3==0 || i%5 == 0) vb[i] = true;
  }
  size_t count = 0;
  const auto vb2 = vb;
  for (size_t i = 0; i < vb.size(); i++) {
    if (vb2[i]) count++;
  }
  std::cout << "Count = " << count << '\n';


  // Try running vector through sort.
  std::sort(v.begin(), v.end());
  for (auto x : v) { std::cout << x << ' '; }
  std::cout << '\n';


  // Removeing 3rd value
  v.erase(v.begin() + 3);
  std::cout << "After removing value #3: " << '\n';
  for (auto x : v) { std::cout << x << ' '; }
  std::cout << '\n';

  // Try inserting value in place of old 30
  emp::vector<int> ins_vals = {25, 28, 32, 35};
  v.insert(v.begin() + 3, ins_vals.begin(), ins_vals.end());
  std::cout << "After inserting four values in place of 30: " << '\n';
  for (auto x : v) { std::cout << x << ' '; }
  std::cout << '\n';

  // Try looking through these BACKWARDS for ptinting.
  std::cout << "\nPrinting in reverse!\n";
  for (emp::vector<int>::reverse_iterator it = v.rbegin(); it < v.rend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << '\n';
}
