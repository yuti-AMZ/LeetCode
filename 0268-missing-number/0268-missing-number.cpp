class Solution {
public:
   int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // O(n log n)
    
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i) {
            return i;  // missing number found
        }
    }
    
    return nums.size();  // if all numbers match, missing is n
}

};