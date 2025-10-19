class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        s.reserve(nums.size());
        for (int num : nums) {
            s.push_back(to_string(num));
        }
        
        auto cmp = [](const string &a, const string &b) {
            return a + b > b + a;
        };
        
        
        sort(s.begin(), s.end(), cmp);
        
        if (!s.empty() && s[0] == "0") {
            return "0";
        }
        
        string result;
        result.reserve(nums.size() * 10); 
        for (const string &str : s) {
            result += str;
        }
        
        return result;
    }
};
