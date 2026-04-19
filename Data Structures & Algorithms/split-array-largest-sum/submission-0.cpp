class Solution {
public:
    int countPartitions(vector<int>& a, int maxSum) {
        int partitions = 1; // at least one partition
        long long subarraySum = 0; // sum of current subarray

        for (int num : a) {
            if (subarraySum + num <= maxSum) {
                subarraySum += num;
            } else {
                partitions++;
                subarraySum = num;
            }
        }
        return partitions;
    }

    // Finds the minimum largest subarray sum possible for at most k partitions
    int splitArray(vector<int>& a, int k) {
        int low = *max_element(a.begin(), a.end()); // largest element
        int high = accumulate(a.begin(), a.end(), 0); // sum of all elements

        // Binary search for the smallest maxSum
        while (low <= high) {
            int mid = (low + high) / 2;
            int partitions = countPartitions(a, mid);

            if (partitions > k) {
                low = mid + 1; // too many partitions → increase maxSum
            } else {
                high = mid - 1; // valid but try smaller maxSum
            }
        }
        return low;
    
    }
};