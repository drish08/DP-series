#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void permutationHelper(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        permutationHelper(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    permutationHelper(s, 0, res);
    sort(res.begin(), res.end());
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

int main() {
  int n = 3, k = 3;
  Solution obj;
  string ans = obj.getPermutation(n, k);
  cout << "The Kth permutation sequence is " << ans << endl;

  return 0;
}