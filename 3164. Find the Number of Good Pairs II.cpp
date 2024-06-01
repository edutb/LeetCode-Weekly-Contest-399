class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        long long ans = 0;

        unordered_map<int, int> good;
        for(auto&v: nums2) good[v]++;

        for(auto&n: nums1){
            if(n%k) continue;
            for(int i = 1; i <= sqrt(n); i++){
                if(n%(i*k) == 0) ans+= good[i];
                if(i!=(n/i) && n%((n/i)*k) == 0) ans+= good[n/i];
            }
        }

        return ans;
    }
};