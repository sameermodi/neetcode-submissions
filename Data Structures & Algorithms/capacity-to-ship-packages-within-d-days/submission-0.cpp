class Solution {
public:
    int CountDays(vector<int>& weights, int maxWeight){
        int days = 1;
        int sum = 0;
        for(int i=0; i<weights.size(); i++){
            if(sum + weights[i] <= maxWeight) sum+= weights[i];
            else {
                days++;
                sum = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = INT_MIN , hi = 0;
        for(int i=0; i<n; i++){
            lo = max(lo, weights[i]);
            hi+= weights[i];
        }
        int ans = -1;
        while(lo <= hi){
            int mid = lo+(hi-lo)/2;

            if(CountDays(weights, mid) <= days){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }
        return ans;
    }
};