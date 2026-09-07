class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minLen = INT_MAX, len = 0, sum = 0;
        int i = 0, j = 0;

        for (i = 0; i < n; i++) {
            if (nums[i] >= target) {
                return 1;
            }
            sum = nums[i];
            for (j = i + 1; j < n; j++) {
                sum += nums[j];
                if (sum >= target) {
                    len = (j - i) + 1;
                    if (len < minLen) {
                        minLen = len;
                    }
                }
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};