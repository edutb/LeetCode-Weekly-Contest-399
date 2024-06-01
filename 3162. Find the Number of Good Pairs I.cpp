class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
          
          int ans = 0;
          for(auto& x: nums1){
            for(auto&y: nums2){
                ans+= (x%(y*k) == 0);
            }
          }
          return ans;
    }
};