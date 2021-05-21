#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  while (left <= right)
  {
	  int mid = (left + right) / 2;

	  if (x == a[mid])
		  return mid;
	  else if (x < a[mid])
		  right = mid - 1;
	  else
		  left = mid + 1;
  }
  return -1;
}

int binary_search_recursive(const vector<int> &a, int x, int l, int r) {
	//int left = 0, right = (int)a.size();
	if (l <= r)
	{
		int mid = (l + r) / 2;

		if (x == a[mid])
			return mid;
		else if (x < a[mid])
			return binary_search_recursive(a, x, l, mid - 1);
		else
			return binary_search_recursive(a, x, mid + 1, r);
	}
	return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

vector<int> merge(const vector<int> &v1, const vector<int> &v2)
{
	int i = 0, j = 0;
	vector <int> v4;
	while (i < v1.size() && j < v2.size())
	{
		if (v1[i] <= v2[j])
		{
			v4.push_back(v1[i]);
			++i;
		}
		else
		{
			v4.push_back(v2[j]);
			++j;
		}
	}
	while (i < v1.size())
	{
		v4.push_back(v1[i]);
		++i;
	}
	while (j < v2.size())
	{
		v4.push_back(v2[j]);
		++j;
	}
	return v4;
}
vector<int> merge_sort(const vector<int> &v)
{
	if (v.size() == 1)
		return v;
	int mid = v.size() / 2;
	vector<int> vt1, vt2;
	vt1.assign(v.cbegin(), v.cbegin() + mid);
	vt2.assign(v.cbegin() + mid, v.cend());

	vector<int> v1 = merge_sort(vt1);
	vector<int> v2 = merge_sort(vt2);

	vector<int> v3 = merge(v1, v2);
	return v3;
}

int main() {
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); i++) {
			std::cin >> a[i];
		}
		int m;
		std::cin >> m;
		vector<int> b(m);
		for (int i = 0; i < m; ++i) {
			std::cin >> b[i];
		}
		vector<int> s = merge_sort(a);
		//for (int i = 0; i < m; ++i) 
		//	//replace with the call to binary_search when implemented
		//	std::cout << linear_search(s, b[i]) << ' ';

		//std::cout << "\n";
		for (int i = 0; i < m; ++i)
			std::cout << binary_search(s, b[i]) << ' ';
		/*std::cout << "\n";
		for (int i = 0; i < m; ++i)
			std::cout << binary_search_recursive(s, b[i], 0, s.size()) << ' ';
		std::cout << "\n";*/
}
