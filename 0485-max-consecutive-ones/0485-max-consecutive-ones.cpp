class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;
        
        for (int x : nums) {
            if (x == 1) {
                currentCount++;
                if (currentCount > maxCount) {
                    maxCount = currentCount;
                }
            } else {
                // reset when we hit a 0
                currentCount = 0;
            }
        }
        
        return maxCount;
    }
};