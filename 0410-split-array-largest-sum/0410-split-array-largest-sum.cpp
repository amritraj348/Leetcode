class Solution {
public:
    bool allocationPossible(vector<int>& arr, int mid, int n, int k) {
        int allocatedStud = 1;
        int pages = 0;

        for(int i = 0; i < n; i++) {

            if(arr[i] > mid)
                return false;

            if(pages + arr[i] > mid) {
                allocatedStud++;
                pages = arr[i];
            }
            else {
                pages += arr[i];
            }
        }

        return allocatedStud <= k;
    }

    int findPages(vector<int>& arr, int k) {
        int n = arr.size();

        if(k > n)
            return -1;

        int low = 0;
        int high = 0;

        for(int i = 0; i < n; i++) {
            low = max(low, arr[i]);
            high += arr[i];
        }

        int result = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(allocationPossible(arr, mid, n, k)) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return result;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};