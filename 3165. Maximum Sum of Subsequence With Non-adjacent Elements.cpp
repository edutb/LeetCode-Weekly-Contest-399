class Solution {
public:

    vector< vector< vector<long long> > > st;
    vector<int> nums;
    const int mod = 1e9 + 7;
    #define INF INT_MAX

    void build(int p, int L, int R){
        if(L == R){
            st[p][0][0] = 0;
            st[p][0][1] = -INF;
            st[p][1][0] = -INF;
            st[p][1][1] = nums[R];
        }
        else{
            build(2*p, L, (L+R)/2);
            build(2*p + 1, (L+R)/2 + 1, R);
            auto&x = st[2*p];
            auto&y = st[2*p + 1];
            st[p][0][0] = max(x[0][1] + y[0][0], max(x[0][0] + y[0][0], x[0][0] + y[1][0]));
            st[p][0][1] = max(x[0][1] + y[0][1], max(x[0][0] + y[0][1], x[0][0] + y[1][1])); 
            st[p][1][0] = max(x[1][0] + y[1][0], max(x[1][0] + y[0][0], x[1][1] + y[0][0])); 
            st[p][1][1] = max(x[1][1] + y[0][1], max(x[1][0] + y[1][1], x[1][0] + y[0][1]));  
        }
    }

    void update(int p, int L, int R, int i, int val){
        if(i > R || i < L) return;
        if(L == R){
            st[p][1][1] = val;
            return;
        }
        
        update(2*p, L, (L + R)/2, i, val);
        update(2*p + 1, (L + R)/2 + 1, R, i, val);
        auto&x = st[2*p];
        auto&y = st[2*p + 1];
        st[p][0][0] = max(x[0][1] + y[0][0], max(x[0][0] + y[0][0], x[0][0] + y[1][0]));
        st[p][0][1] = max(x[0][1] + y[0][1], max(x[0][0] + y[0][1], x[0][0] + y[1][1])); 
        st[p][1][0] = max(x[1][0] + y[1][0], max(x[1][0] + y[0][0], x[1][1] + y[0][0])); 
        st[p][1][1] = max(x[1][1] + y[0][1], max(x[1][0] + y[1][1], x[1][0] + y[0][1]));
    }


    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
          int n = nums.size();
          st.assign(4*n, vector< vector<long long> >(2, vector<long long>(2, 0)));
          this->nums = nums;
          build(1, 0, n-1);

          long long ans = 0;
          for(auto&q: queries){
            int pos = q[0];
            int val = q[1];
            update(1, 0, n -1, pos, (val >=0 ? val : 0));
            auto query_val = max(st[1][0][0], max(st[1][0][1], max(st[1][1][0], st[1][1][1])));
            ans = (ans%mod + query_val%mod)%mod;
          }

          return ans;
    }
};