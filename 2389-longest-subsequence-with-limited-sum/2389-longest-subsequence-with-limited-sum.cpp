class Solution {
public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    sort(nums.begin(), nums.end()); 

    
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }

    vector<int> ans;
    for (int q : queries) {
        
        int count = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
        ans.push_back(count);
    }

    return ans;
}


};