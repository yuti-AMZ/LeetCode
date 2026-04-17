class Solution:
    def combinationSum(self, candidates, target):
        result = []

        def backtrack(start, path, total):
            # Base cases
            if total == target:
                result.append(path[:])
                return
            if total > target:
                return

            # Try all options starting from 'start'
            for i in range(start, len(candidates)):
                path.append(candidates[i])
                backtrack(i, path, total + candidates[i])  # reuse same element
                path.pop()  # undo choice

        backtrack(0, [], 0)
        return result