class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        seen = set()  # to store unique numbers

        for n in nums:
            if n in seen:
                return True  # duplicate found
            seen.add(n)

        return False  # all elements are distinct

        