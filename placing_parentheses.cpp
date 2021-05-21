#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
	  return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void minmax(int i, int j, vector<vector<long long>> &M, vector<vector<long long>> &m, const string &exp, vector<char> op)
{
	long long Min = std::numeric_limits<long long>::max();
	long long Max = std::numeric_limits<long long>::min();
	for (int k = i; k < j; ++k)
	{
		long long a = eval(M[i][k], M[k + 1][j], op[k]);
		long long b = eval(M[i][k], m[k + 1][j], op[k]);
		long long c = eval(m[i][k], M[k + 1][j], op[k]);
		long long d = eval(m[i][k], m[k + 1][j], op[k]);

		Min = min(Min, min(a, min(b, min(c, d))));
		Max = max(Max, max(a, max(b, max(c, d))));
	}
	m[i][j] = Min;
	M[i][j] = Max;
}

long long get_maximum_value(const string &exp) {
  //write your code here
	int n = exp.length() / 2 + 1;
	vector <char> op(n);
	for (int i = 1,j = 1; j < exp.length() - 1; ++i, j = j+2)
	{
		op[i] = exp[j];
	}
	vector<vector<long long>>m(n + 1 , vector<long long>(n + 1, 0));
	vector<vector<long long>>M(n + 1 , vector<long long>(n + 1, 0));
	for (int i = 1, j = 0; j < exp.length(); ++i, j = j+2)
	{
		m[i][i] = exp[j] - '0';
		M[i][i] = exp[j] - '0';
	}

	for (int s = 1; s <= n ; ++s)
	{
		for (int i = 1; i <= n - s; ++i)
		{
			int j = s + i;
			minmax(i, j, M, m, exp, op);
		}
	}
  return M[1][n];
}

int main() {
	/*while (true)
	{*/
		string s;
		std::cin >> s;
		std::cout << get_maximum_value(s) << '\n';
	/*}*/
}
