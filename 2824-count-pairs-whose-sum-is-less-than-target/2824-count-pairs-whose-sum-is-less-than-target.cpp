class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); 
        
        int left = 0;
        int right = n - 1;
        long long count = 0; 
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
               
                count += (right - left);
                left++;
            } else {
                right--;
            }
        }
        
        return (int) count;
    }
};
