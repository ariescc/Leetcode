class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string res="";
		int minLength=0xfffffff;
		int len=strs.length();
		int count=0;
		if(len==0) return "";
		else if(len==1) return strs[0];
		else {
			for(int i=0;i<len;i++){
				if(strs[i].length()<minLength) minLength=strs[i].length();
			}
			for(int j=0;j<minLength;i++){
				for(int k=1;k<strs.length();k++){
					if(strs[k][j]!=strs[0][j]) return "";
				}
				res[count++]=strs[0][j];
			}
		}
		return res;
    }
};