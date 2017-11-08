class Solution {
public:

	bool judge(int x, int y, int n, int m)
	{
		if(x < 0 || y < 0 || x >= n || y >= m) 
			return 0;
		return 1;
	}

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		
		int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};
		int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};
		
		int n = M.size();
		int m = M[0].size();
		
		vector<vector<int>> ans;	
		
		for(int i = 0; i < n; i++)
		{
			vector<int> temp;
			for(int j = 0; j < m; j++)
			{
				int num = 0;
				int cnt = 0;
				for(int k = 0; k < 9; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					
					if(judge(nx, ny, n, m))
					{
						num += M[nx][ny];
						cnt++;
					}
				}
				temp.push_back(num/cnt);
			}
			ans.push_back(temp);
		}
		return ans;
    }
};