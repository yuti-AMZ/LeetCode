class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int suffixStart = n - 1;
        while (suffixStart > 0 && nums[suffixStart - 1] < nums[suffixStart]) {
            suffixStart--;
        }
        if (suffixStart == 0) return (long long)n * (n + 1) / 2;

        long long result = (long long)(n - suffixStart + 1);

        int i = 0;
        for (; i < suffixStart; i++) {
            if (i > 0 && nums[i] <= nums[i - 1]) break;
        }
        int prefixEnd = i - 1;

        int j = suffixStart;
        for (; j < n; j++) {
            while (prefixEnd >= 0 && nums[prefixEnd] >= nums[j]) {
                prefixEnd--;
            }
            result += (long long)(prefixEnd + 2);
            if (j + 1 < n && nums[j] >= nums[j + 1]) break;
        }

        return result;
    }
};