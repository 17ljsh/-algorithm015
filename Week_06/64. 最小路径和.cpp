class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0){
            return 0;
        }
        int col = grid[0].size();
        vector<int> data(col,0);
        for (int i = col - 1; i >= 0; i--) {
            if (i != col - 1) {
                data[i] = grid[row-1][i] + data[i + 1];
            }
            else {
                data[i] = grid[row-1][i];
            }
            printf("%d ",data[i]);
        }
        
        for (int i = row -2; i >= 0; i--) {
            for (int j = col -1; j >= 0; j--) {
                if (j != col - 1) {
                    data[j] = grid[i][j] + min(data[j+1],data[j]);
                }
                else {
                    data[j] = grid[i][j] + data[j];
                }
            }
        }
        
        return data[0];
    }
};
//思路和官方题解差不多，但美观和处理逻辑还有待提高