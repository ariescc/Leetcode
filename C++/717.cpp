class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		int i = 0;
		
        while(i < bits.size())
		{
			if(i<bits.size()-1 && bits[i] == 1)
			{
				if(bits[i+1] == 1 || bits[i+1] == 0) 
				{
					i = i+2;
					if(i>=bits.size())
					{
						return false;
					}
					else if(i == bits.size()-1)
					{
						if(bits[i] == 0)
						{
							return true;
						}
						else 
						{
							return false;
						}
					}
				}
			}
			else if(i == bits.size()-1)
			{
				if(bits[i] == 0)
				{
					return true;
				}
				else 
				{
					return false;
				}
			}
			else 
			{
				i++;
			}
		}
    }
};