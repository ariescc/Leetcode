class Solution {
public:

	int vis[50][50];

    int maxAreaOfIsland(vector<vector<int>>& grid) {
       	
		if(grid.size() == 0)
		{
			return 0;
		}
		
		memset(vis, 0, sizeof(vis));
		
		int maxium = 0;
		
		// ±éÀú 1 
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); j++)
			{
				if(grid[i][j] == 0) continue;
				
				int area = dfs_area(grid, i, j);
				if(area > maxium)
				{
					maxium = area;
				}
			}
		}
		
		return maxium;
		
    }
	
	int dfs_area(vector<vector<int>>& grid, int x, int y)
	{
		if(grid[x][y] == 0 || vis[x][y] == 1)
		{
			return 0;
		}
		
		int area = 1;
		vis[x][y] = 1;
		
		if(x + 1 < grid.size())
		{
			area += dfs_area(grid, x + 1, y);
		}
		if(x - 1 < grid.size())
		{
			area += dfs_area(grid, x - 1, y);
		}
		if(y + 1 < grid[0].size())
		{
			area += dfs_area(grid, x, y + 1);
		}
		if(y - 1 < grid[0].size())
		{
			area += dfs_area(grid, x, y - 1);
		}
		return area;
	}
};