#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

vector<int> partition3(vector<int> &v, int l, int r)
{
	vector <int> p;
	int j = l;
	int k = v[l];
	for (int i = l + 1; i <= r; ++i)
	{
		if (v[i] <= k)
		{
			++j;
			swap(v[i], v[j]);
		}
	}

	swap(v[l], v[j]);
	p.push_back(j);
	k = v[j];
	int q = l;
	for (int i = l; i < j; ++i)
	{
		if (v[i] < k)
		{
			swap(v[i], v[q]);
			++q;
		}
	}
	if (v[q] != v[j])
		q = q + 1;
	p.push_back(q);
	swap(p[0], p[1]);
	return p;
}

void randomized_quick_sort3(vector<int> &v, int l, int r)
{
	if (l >= r)
		return;

	int k = l + rand() % (r - l + 1);
	swap(v[l], v[k]);
	vector<int> m = partition3(v, l, r);
	randomized_quick_sort3(v, l, m[0] - 1);
	randomized_quick_sort3(v, m[1] + 1, r);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main() {
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cin >> a[i];
		}
		randomized_quick_sort3(a, 0, a.size() - 1);
		for (size_t i = 0; i < a.size(); ++i) {
			std::cout << a[i] << ' ';
		}
}
