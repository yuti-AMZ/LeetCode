class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int target = tickets[k];
        int total = 0;
        for (int i = 0; i < (int)tickets.size(); ++i) {
            if (i <= k) total += min(tickets[i], target);
            else total += min(tickets[i], target - 1);
        }
        return total;
    }
};