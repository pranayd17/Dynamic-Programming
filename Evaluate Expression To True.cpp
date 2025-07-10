int mod=1e3+3;


int f(int i,int j, int isTrue,string &A,vector<vector<vector<int>>> &dp)

{

    if(i>j)

    return 0;

    if(i==j)

    {

        if(isTrue==1)

        return A[i]=='T';

        else

        return A[i]=='F';

    }

    if(dp[i][j][isTrue]!=-1)

    return dp[i][j][isTrue];

    

    int ways=0;

    for(int ind=i+1;ind<=j-1;ind+=2)

    {

        int LT=f(i,ind-1,1,A,dp);

        int LF=f(i,ind-1,0,A,dp);

        int RT=f(ind+1,j,1,A,dp);

        int RF=f(ind+1,j,0,A,dp);

        

        char op=A[ind];

        switch(op)

        {

            case '|':

            {

                if(isTrue)

                ways=(ways+ (LT*RT)%mod + (LT*RF)%mod +(LF*RT)%mod)%mod;

                else

                ways=(ways+(LF*RF)%mod)%mod;

            }

            break;

            case '&':

            {

                if(isTrue)

                ways=(ways+ (LT*RT)%mod)%mod;

                else

                ways=(ways+(LF*RF)%mod + (LT*RF)%mod +(LF*RT)%mod)%mod;

            }

            break;

            case '^':

            {

                if(isTrue)

                ways=(ways+ (LT*RF)%mod +(LF*RT)%mod)%mod;

                else

                ways=(ways+ (LT*RT)%mod +(LF*RF)%mod)%mod;

            }

            break;

        }

    }

    return dp[i][j][isTrue]=ways%mod;

}


int Solution::cnttrue(string A) {

    vector<vector<vector<int>>> dp(A.size(),vector<vector<int>>(A.size(),vector<int>(2,-1)));

    return f(0,A.size()-1,1,A,dp);

}
