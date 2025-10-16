class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;  // use long to handle edge cases
        for (int n : nums) {
            if (n == first || n == second || n == third) continue; // skip duplicates
            
            if (n > first) {
                third = second;
                second = first;
                first = n;
            } 
            else if (n > second) {
                third = second;
                second = n;
            } 
            else if (n > third) {
                third = n;
            }
        }

        return (third == LONG_MIN) ? first : third;
    }
};