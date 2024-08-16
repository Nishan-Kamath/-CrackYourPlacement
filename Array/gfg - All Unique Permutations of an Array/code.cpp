class Solution {
  public:
  void permutation(int i, int n, vector<int> &p, vector<vector<int>> &ans, vector<int> &arr, vector<bool> &v) {
    if (i == n) {
        ans.push_back(p);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!v[j]) {
            if (j > 0 && arr[j] == arr[j - 1] && !v[j - 1]) {
                continue; 
            }
            p.push_back(arr[j]);
            v[j] = true;
            permutation(i + 1, n, p, ans, arr, v);
            v[j] = false;
            p.pop_back();
        }
    }
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
    vector<vector<int>> ans;
    vector<int> p;
    vector<bool> v(n, false);

    sort(arr.begin(), arr.end());
    permutation(0, n, p, ans, arr, v);

    return ans;
}
};