class Solution {
public:
   vector<int> targetIndices(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (nums[i] == target)
            result.push_back(i);
    }

    return result;
}
};