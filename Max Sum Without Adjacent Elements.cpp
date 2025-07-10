int Solution::adjacent(vector<vector<int> > &A) {
    int N = A[0].size();
    vector<int> dp(N , 0);
    for (int i = 0 ; i < N ; i++){
        int c = A[0][i];
        int d = A[1][i];
        dp[i] = max(c , d);
    }
    vector<int> findp(N);
    findp[0] = dp[0];
    findp[1] = max(dp[0] , dp[1]);
    for (int i = 2 ; i < N ; i++){
        if (dp[i] + findp[i-2] > findp[i-1] ){
            findp[i] = dp[i] + findp[i-2];
        }
        else{
            findp[i] = findp[i-1];
        }
    }
    return findp[N-1];
   
}
