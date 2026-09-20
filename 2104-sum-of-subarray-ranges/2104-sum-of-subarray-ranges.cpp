class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> pse(n), nse(n);
        vector<int> pge(n), nge(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = 0; i < n; i++) {

            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            pge[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long minimumSum = 0;
        long long maximumSum = 0;

        for (int i = 0; i < n; i++) {

            long long leftMin = i - pse[i];
            long long rightMin = nse[i] - i;

            minimumSum += nums[i] * leftMin * rightMin;

            long long leftMax = i - pge[i];
            long long rightMax = nge[i] - i;

            maximumSum += nums[i] * leftMax * rightMax;
        }

        return maximumSum - minimumSum;
    }
};