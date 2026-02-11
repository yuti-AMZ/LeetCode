class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]  # Initialize stack with -1 to handle base for first valid substring
        max_length = 0

        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)  # Push the index of '('
            else:
                stack.pop()  # Pop the last '(' index
                if not stack:
                    stack.append(i)  # If stack is empty, push current index as base
                else:
                    max_length = max(max_length, i - stack[-1])  # Update max length

        return max_length

# Example usage:
solution = Solution()
s = ")()())"
print(solution.longestValidParentheses(s))  # Output: 4
