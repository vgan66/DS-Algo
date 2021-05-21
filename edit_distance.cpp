#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
	vector<vector<int>> v(str1.length() + 1, vector<int>(str2.length() + 1, 0));
	for (int i = 1; i <= (int)str1.length(); ++i)
		v[i][0] = i;
	for (int j = 1; j <= (int)str2.length(); ++j)
		v[0][j] = j;
	for (int i = 1; i <= (int)str1.length(); ++i)
	{
		
		for (int j = 1; j <= (int)str2.length(); ++j)
		{
			int in;
			int de;
			int re;
			in = v[i][j-1] + 1;
			de = v[i - 1][j] + 1;
			int m = min(in, de);
			if (str1[i - 1] == str2[j - 1])
				re = v[i - 1][j - 1];
			else
				re = v[i - 1][j - 1] + 1;

			v[i][j] = min(m, re);
		}
	}


  return v[(int)str1.length()][(int)str2.length()];
}

int main() {
	/*while (true)
	{*/
		string str1;
		string str2;
		std::cin >> str1 >> str2;
		std::cout << edit_distance(str1, str2) << std::endl;
	/*}*/
  return 0;
}
