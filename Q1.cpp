2D Dp
//Q1) Code Studio link- https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003;
//Method 1- Recursive +memoization
//#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
int f(int idx,vector<vector<int>> &points,int select,vector<vector<int>>&dp)
{
    if(idx<0)
        return 0;
    if(dp[idx][select]!=-1)
        return dp[idx][select];
    vector<int>v=points[idx];
    int ans1=INT_MIN;
    int ans2=INT_MIN;
    int ans3=INT_MIN;
    if(select==0)
         ans1=v[0]+max(f(idx-1,points,1,dp),f(idx-1,points,2,dp));
     if(select==1)
         ans2=v[1]+max(f(idx-1,points,0,dp),f(idx-1,points,2,dp));
    if(select==2)
         ans3=v[2]+max(f(idx-1,points,0,dp),f(idx-1,points,1,dp));
    return dp[idx][select]=max(ans1,max(ans2,ans3));
    
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
  
   vector<vector<int>>dp(n,vector<int>(3,-1));
    for(int i=0;i<3;i++)
        dp[0][i]=points[0][i];
    for(int idx=1;idx<n;idx++)
    {
        int ans1=0;
        int ans2=0;
        int ans3=0;
        for(int select=0;select<3;select++)
        {
            if(select==0)
                ans1=points[idx][0]+max(dp[idx-1][1],dp[idx-1][2]);
            if(select==1)
                ans1=points[idx][1]+max(dp[idx-1][0],dp[idx-1][2]);
             if(select==2)
                ans1=points[idx][2]+max(dp[idx-1][0],dp[idx-1][1]);
            dp[idx][select]=max(ans1,max(ans2,ans3));
        }
    }
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
// Method 2-Tabulation 
//#include <bits/stdc++.h>
#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
  
   vector<vector<int>>dp(n,vector<int>(3,-1));
    for(int i=0;i<3;i++)
        dp[0][i]=points[0][i];
    for(int idx=1;idx<n;idx++)
    {
        int ans1=0;
        int ans2=0;
        int ans3=0;
        for(int select=0;select<3;select++)
        {
            if(select==0)
                ans1=points[idx][0]+max(dp[idx-1][1],dp[idx-1][2]);
            if(select==1)
                ans1=points[idx][1]+max(dp[idx-1][0],dp[idx-1][2]);
             if(select==2)
                ans1=points[idx][2]+max(dp[idx-1][0],dp[idx-1][1]);
            dp[idx][select]=max(ans1,max(ans2,ans3));
        }
    }
    return max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
//Method 3) Space optimization Final ans
#include <bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
  
   vector<int>dp(n);
    for(int i=0;i<3;i++)
        dp[i]=points[0][i];
    for(int idx=1;idx<n;idx++)
    {
        int ans1=0;
        int ans2=0;
        int ans3=0;
        for(int select=0;select<3;select++)
        {    //cout<<dp[0]<<dp[1]<<dp[2]<<endl;
            if(select==0)
                ans1=points[idx][0]+max(dp[1],dp[2]);
            if(select==1)
                ans2=points[idx][1]+max(dp[0],dp[2]);
             if(select==2) 
                ans3=points[idx][2]+max(dp[0],dp[1]);
            
        }
            dp[0]=ans1;
            dp[1]=ans2;
            dp[2]=ans3;
    }
    return max(dp[0],max(dp[1],dp[2]));
}
