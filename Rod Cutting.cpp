long long int solve(int i, int j, vector<int>& cuts, vector<vector<long long int>> &dp, vector<vector<int>> &pos){
    if(abs(i -j) <= 1)
        return 0;
   
    if(dp[i][j] != -1)
        return dp[i][j];

    long long int min_cost = -1;
    for(int k = i+1; k <=j-1; k++){
        long long int cost_for_cut = cuts[j] - cuts[i];
        long long int curr_cost = cost_for_cut + solve(i, k, cuts, dp, pos) + solve(k,j, cuts, dp, pos);
        if((curr_cost < min_cost) || (min_cost == -1LL)){
            min_cost = curr_cost;
            pos[i][j] = k;
        }
    }
    return dp[i][j] = min_cost;
}

void solve2(int i, int j, vector<int> &v, vector<vector<int>> &pos, vector<int>& cuts){
    if(abs(i - j) <= 1)
        return;
    v.push_back(cuts[pos[i][j]]);
    solve2(i, pos[i][j], v, pos, cuts);
    solve2(pos[i][j], j, v, pos, cuts);
}

vector<int> Solution::rodCut(int len, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(len);
    sort(cuts.begin(), cuts.end());
    int m = cuts.size();
    vector<vector<long long int>>dp(m+1,vector<long long int>(m+1, -1));
    vector<vector<int>> pos(m+1,vector<int>(m+1));
    int cost = solve(0, m-1, cuts, dp, pos);
    vector<int>v;
    solve2(0, m-1, v, pos, cuts);
    return v;
}
