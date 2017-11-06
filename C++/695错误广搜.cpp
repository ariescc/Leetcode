class Solution {
public:
	
	struct Node {
		int x;
		int y;
		int area; // �Ӹ�node���������
	};
	
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
		// ���ѷ���
		int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

		queue<Node> que;
		
		Node now, next; //  ��ǰ�ڵ㣬 ��һ�ڵ�
		
		int res[50][50];
		memset(res, 0, sizeof(res)); // ������������
		
		int mark[50][50];
		memset(res, 0, sizeof(mark));
		
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[i].size(); i++)
			{
				if(grid[i][j] == 1) 
				{
					// �ӵ�ǰ��㿪ʼ������������
					while(!que.empty()) que.pop(); // ÿ�ι���ǰ��ն���
					
					now.x = i;
					now.y = j;
					now.area = 0;
					
					que.push(now); // ѹ�뵱ǰ���
					
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
		
		// �����ҵ����area
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