class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int nonZeroPos = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] != 0) {
            nums[nonZeroPos] = nums[i];
            nonZeroPos++;
        }
    }
    for(int i = nonZeroPos; i < n; i++) {
        nums[i] = 0;
    }
}
};