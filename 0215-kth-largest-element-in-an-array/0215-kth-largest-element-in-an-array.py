class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k = len(nums) - k  # Convert to index for kth smallest in 0-based

        def quickselect(left, right):
            pivot = nums[random.randint(left, right)]
            i, j, p = left - 1, right + 1, left
            while p < j:
                if nums[p] < pivot:
                    i += 1
                    nums[i], nums[p] = nums[p], nums[i]
                    p += 1
                elif nums[p] > pivot:
                    j -= 1
                    nums[p], nums[j] = nums[j], nums[p]
                else:
                    p += 1
            if k <= i:
                return quickselect(left, i)
            elif k >= j:
                return quickselect(j, right)
            return nums[k]

        return quickselect(0, len(nums) - 1)