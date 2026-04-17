class Solution {
public:
    int timeTaken(vector<int>& piles, int pile){
        int n = piles.size();
        int hr = 0;
        for(int i=0; i<n; i++){
            
           hr+= (piles[i]%pile==0)? piles[i]/pile : piles[i]/pile+1;
        }    
        return hr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1, hi = INT_MIN;

        for(int i=0; i<n; i++){
            hi = max(hi, piles[i]);
        }
        int ans = -1 ;
        while(lo <= hi){
            int mid = lo  + (hi - lo)/2;

            if(timeTaken(piles, mid) <= h){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }

        return ans;
       
    }
};
