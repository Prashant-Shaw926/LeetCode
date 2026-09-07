class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] >= target) {
                return 1;
            } else {
                return 0;
            }
        }
        int minLen = INT_MAX, len = 0;
        int i = 0, j = i + 1;
        long long sum = nums[i];

        i = 0;
        while (j < n) {
            if (nums[i] >= target) {
                return 1;
            }
            sum += nums[j];
            if (sum >= target) {
                len = (j - i) + 1;
                if (len <= minLen) {
                    minLen = len;
                    i++;
                    j = i + 1;
                    sum = nums[i];
                }
            } else {
                j++;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};