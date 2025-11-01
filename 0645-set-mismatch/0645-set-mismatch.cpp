class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> seen;
        int duplicate = -1;
        int sum = 0;
        int n = nums.size();

        for (int num : nums) {
            if (seen.count(num)) {
                duplicate = num;
            } else {
                seen.insert(num);
            }
            sum += num;
        }

        int expectedSum = n * (n + 1) / 2;
        int missing = expectedSum - (sum - duplicate);

        return {duplicate, missing};
    }
};