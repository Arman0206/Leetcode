class Solution {
public:
vector<vector<int>> grid;
vector<int> v;
vector<int> dp;
int n,m;
    int maximalRectangle(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        //cout<<n<<" ";
        grid.resize(n,vector<int>(m));
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<m;j++){
            grid[i][j]=matrix[i][j]-'0';
            if(!grid[i][j]){
                cur=0;
                continue;
            }
            cur++;
            grid[i][j]=cur;
            }
        }
        int ans=0;
        for(int j=0;j<m;j++){

for(int k=1;k<=m;k++){
    int cur=0;
    for(int i=0;i<n;i++){
if(grid[i][j]>=k)
    cur++;
    else
    cur=0;
    ans=max(ans,cur*k);

    }
}

        }


return ans;

    }
};