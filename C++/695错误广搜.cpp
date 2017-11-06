class Solution {
public:
	
	struct Node {
		int x;
		int y;
		int area; // 从该node起最大的面积
	};
	
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
		// 广搜方向
		int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

		queue<Node> que;
		
		Node now, next; //  当前节点， 下一节点
		
		int res[50][50];
		memset(res, 0, sizeof(res)); // 所有数据清零
		
		int mark[50][50];
		memset(res, 0, sizeof(mark));
		
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); i++)
			{
				if(grid[i][j] == 1) 
				{
					// 从当前结点开始广搜求最大面积
					while(!que.empty()) que.pop(); // 每次广搜前清空队列
					
					now.x = i;
					now.y = j;
					now.area = 0;
					
					que.push(now); // 压入当前结点
					
					while(!que.empty())
					{
						now = que.front();
						que.pop();
						
						int fg = 0;
						
						for(int k = 0; k < 4; k++)
						{
							next.x = now.x + dir[k][0];
							next.y = now.y + dir[k][1];
							
							if(grid[next.x][next.y] == 0 || next.x < 0 || next.x >= grid.size() || next.y < 0 || next.y >= grid[i].size() || mark[next.x][next.y] == 1)
							{
								continue;
							}
							
							mark[next.x][next.y] = 1;
							next.area = now.area + 1;
							
							que.push(next);
							
							int flag = 0;
							
							for(int p = 0; p < 4; p++)
							{
								if(grid[next.x + dir[p][0]][next.y + dir[p][1]] == 1 &&
									mark[next.x + dir[p][0]][next.y + dir[p][1]] == 0)
									{
										flag = 1;
									}
							}
							
							if(flag == 0) 
							{
								res[i][j] = next.area;
								fg = 1;
								break;
							}
						}
						
						if(fg == 1)
						{
							break;
						}
						
					}
				}
			}
		}
		
		// 排序找到最大area
		int maxium = -1;
		for(int k1 = 0; k1 < 50; k1++)
		{
			for(int k2 = 0; k2 < 50; k2++)
			{
				if(res[k1][k2] > maxium)
				{
					maxium = res[k1][k2];
				}
			}
		}
		
		return maxium;
		
    }
};