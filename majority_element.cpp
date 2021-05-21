#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  //write your code here
  int count = 1;
  int x = a[0];
  for (int i = 1; i < (int)a.size(); ++i)
  {
	  if (a[i] == x)
	  {
		  ++count;
		  if (count > (int)a.size() / 2)
			  return 0;
	  }
	  else
	  {
		  x = a[i];
		  count = 1;
	  }
  }
  return -1;
}

void merge(vector<int>& v, int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int i = 0, j = 0;
	vector<int> v1;
	vector<int> v2;

	while (i < n1)
	{
		v1.push_back(v[l + i]);
		++i;
	}
	while (j < n2)
	{
		v2.push_back(v[m + 1 + j]);
		++j;
	}

	int k = 0, o = 0, p = l;
	while (k < n1 && o < n2)
	{
		if (v1[k] <= v2[o])
		{
			v[p] = v1[k];
			++k;
		}
		else
		{
			v[p] = v2[o];
			++o;
		}
		++p;
	}
	while (k < n1)
	{
		v[p] = v1[k];
		++k;
		++p;
	}
	while (o < n2)
	{
		v[p] = v2[o];
		++o;
		++p;
	}
}

void merge_sort(vector<int>& v, int l, int r)
{
	if (l >= r)
		return;
	int mid = l + (r - l) / 2;
	merge_sort(v, l, mid);
	merge_sort(v, mid + 1, r);
	merge(v, l, mid, r);
}

int main() {
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cin >> a[i];
		}

		merge_sort(a, 0, a.size()- 1);
		std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
