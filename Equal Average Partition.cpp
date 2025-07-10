vector<vector<int> > Solution::avgset(vector<int> &A) {
   int n=A.size();
   sort(A.begin(),A.end()); //to get rid of lexicographic things
   int sum=0;
   for(int i=0;i<n;++i)sum+=A[i];
   
   //3D DP
   //dp[i][j][k] represents starting from index i till end, can we make sum of k with subseq of size j
   int dp[n][n+1][sum+1]; //DP[index][length][sum]
   for(int i=0;i<n;++i){
       for(int j=0;j<=n;++j){
           for(int k=0;k<=sum;++k){
               dp[i][j][k]=-1;
           }
       }
   }
   //start filling from back of array
   //When we are at last index we can make sum=0 with length=0 as well as sum=A[ind] with length=1
   dp[n-1][1][A[n-1]]=1;
   dp[n-1][0][0]=1;
   
   //start filling rest of the dp
   for(int i=n-2;i>=0;--i){
       for(int j=0;j<=n;++j){
           for(int k=0;k<=sum;++k){
               /*
               if we have dp[i+1][j][k]=1 which means starting from index (i+1) till end we can make sum of k with length j,
               using this we can fill dp at ind i,
               either we will include ith index or not,
               if we include that which means dp[i][j+1][k+A[i]]=1 (length increases by 1, and sum increases by that element),
               if we don't include that whihc means dp[i][j][k]=1 (lenght and sum will not changes)
               */
               if(dp[i+1][j][k]==1){
                   dp[i][j][k]=1;
                   dp[i][j+1][k+A[i]]=1;
               }
           }
       }
   }
   vector<int>temp; //to store the 1st array
   for(int i=1;i<n;++i){
       //By doing some mathematics,
       /*
       sum)a = ((sum)*(lenght)a)/n;
       so iterate over sum and check if this sum is possible or not
       */
       if((sum*i)%n==0){
           int sum1=(sum*i)/n;
           //if dp[0][i][sum1]==1 which means we can make required sum using length i
           if(dp[0][i][sum1]==1){
               int len=i;
               // to get element do kind of backtacking things,
               for(int ii=0;ii<n-1;++ii){
                   //at every ind either it will be in our req ans or not
                   /*
                   to check it firstly it should be less than req sum,
                   then we will include it only when dp[next_ind][len-1][sum-A[ind]]==1,
                   if we included it then sum and length will get updated
                   */
                   if(A[ii]<=sum1 && len>0 && dp[ii+1][len-1][sum1-A[ii]]==1){
                       temp.push_back(A[ii]);
                       sum1-=A[ii];
                       len-=1;
                   }
               }
               // we haven't checked for the last index, so we have to check for that
               if(sum1==A[n-1])temp.push_back(A[n-1]);
               break;
           }
       }
   }
   
    sort(temp.begin(),temp.end()); //this will be my left array
    // to get rest array,just iterate and pick the remaining element
    vector<int>curr;
    vector<vector<int>>fin;
    if(temp.size()==0 || temp.size()==n)return fin;
    fin.push_back(temp);
    int j=0;
    for(int i=0;i<n;++i){
        if(j==temp.size()){
            curr.push_back(A[i]);
        }
        else if(A[i]!=temp[j]){
            curr.push_back(A[i]);
        }
        else{
            j+=1;
        }
    }
    fin.push_back(curr);
    return fin;
}
