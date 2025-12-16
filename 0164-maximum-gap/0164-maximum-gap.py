class Solution:
    def maximumGap(self, nums: list[int]) -> int:
        if len(nums) < 2:
            return 0

        min_val, max_val = min(nums), max(nums)
        n = len(nums)
        gap = math.ceil((max_val - min_val) / (n - 1))

        if gap == 0:  # all numbers are the same
            return 0

        # initialize buckets
        buckets_min = [math.inf] * (n - 1)
        buckets_max = [-math.inf] * (n - 1)

        for num in nums:
            if num == min_val or num == max_val:
                continue
            idx = (num - min_val) // gap
            buckets_min[idx] = min(buckets_min[idx], num)
            buckets_max[idx] = max(buckets_max[idx], num)

        max_gap = 0
        prev = min_val

        for i in range(n - 1):
            if buckets_min[i] == math.inf:
                continue
            max_gap = max(max_gap, buckets_min[i] - prev)
            prev = buckets_max[i]

        max_gap = max(max_gap, max_val - prev)
        return max_gap