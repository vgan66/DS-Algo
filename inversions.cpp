#include <iostream>
#include <vector>

using std::vector;

//long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//  long long number_of_inversions = 0;
//  if (right <= left + 1) return number_of_inversions;
//  size_t ave = left + (right - left) / 2;
//  number_of_inversions += get_number_of_inversions(a, b, left, ave);
//  number_of_inversions += get_number_of_inversions(a, b, ave, right);
//  //write your code here
//  return number_of_inversions;
//}

vector<int> merge(const vector<int> &v1, const vector<int> &v2, long long &in)
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
			in = in + (v1.size() - i);
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
vector<int> merge_sort(const vector<int> &v, long long &in)
{
	if (v.size() == 1)
		return v;
	int mid = v.size() / 2;
	vector<int> vt1, vt2;
	vt1.assign(v.cbegin(), v.cbegin() + mid);
	vt2.assign(v.cbegin() + mid, v.cend());

	vector<int> v1 = merge_sort(vt1, in);
	vector<int> v2 = merge_sort(vt2, in);

	vector<int> v3 = merge(v1, v2, in);
	return v3;
}

int main() {
	/*while (true)
	{*/
		int n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < a.size(); i++) {
			std::cin >> a[i];
		}
		// vector<int> b(a.size());
		long long inv = 0;
		merge_sort(a, inv);
		std::cout << inv << '\n';
	//}
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
