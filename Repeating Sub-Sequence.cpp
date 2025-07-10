int Solution::anytwo(string A)

{

    //This problem is an extension of the LCS .Note that in LCS , u had 2 strings but in this u have one so take the same string 2 times in LCS problem.

    //Also note that any ith character in the two subsequences shouldn’t have the same index in the original string so we use the first if condition in the problem as those would be same in both

    int n=A.size();

    int L[n + 1][n + 1];

    memset(L,0,sizeof(L));

    

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {

            //Just add this extra condition for meeting the requirements of this problem.

            if (i == j)

                L[i][j] = max(L[i - 1][j], L[i][j - 1]);

 

            else 

            if (A[i - 1] == A[j - 1])

                L[i][j] = L[i - 1][j - 1] + 1;

 

            else

                L[i][j] = max(L[i - 1][j], L[i][j - 1]);

        }

    }

    //L[n][n] gives us the Longest Common Subsequence Length

    if(L[n][n] >= 2)

    return 1;

    else

    return 0;

}
