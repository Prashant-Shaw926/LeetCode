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
        int i = 0, j = 0;
        long long sum = nums[i];

        while (j < n) {
            if (nums[i] >= target) {
                return 1;
            }
            if (sum >= target) {
                len = (j - i) + 1;
                if (len <= minLen) {
                    minLen = len;
                }
                sum -= nums[i];
                i++;
                continue;
            } else {
                j++;
                if (j == n) {
                    break;
                }
            }
            sum += nums[j];
        }

        return minLen == INT_MAX ? 0 : minLen;
    }
};