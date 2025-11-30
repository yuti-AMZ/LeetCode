class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;  // number -> index
        
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            if(seen.count(complement)) {
                return { seen[complement], i };  // pair found
            }
            
            seen[nums[i]] = i;  // store current number with index
        }
        
        return {};  // return empty if no pair found
    }
};