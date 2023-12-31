class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        
        vector<vector<int>>dp(arr.size()+1,vector<int>(arr[0].size()+1,-1));
        int row=0;
        int col=0;
        int result= fun(arr,row,col,dp);
        if(result==0)
        {
            return 1;
        }
        return result;
    }
    int fun(vector<vector<int>>&arr,int row,int col,vector<vector<int>>&dp)
    {
        if(row<0 or row>=arr.size() or col<0 or col>=arr[0].size())
        {
            return 1e6;
        }
        if(dp[row][col]!=-1)
        {
            return dp[row][col];
        }
        long long int right=fun(arr,row,col+1,dp);
        long long int down=fun(arr,row+1,col,dp);
        
        long long int h=min(right,down);
        if(h==1e6)
            h=1;
        long long int result=h-arr[row][col];
        
        if(result>0)
        {
            dp[row][col]= result;
            return result;
        }
        dp[row][col]= 1;
        return 1;
        
    }
};