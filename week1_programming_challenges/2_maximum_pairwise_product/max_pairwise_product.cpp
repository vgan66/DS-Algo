#include <iostream>
#include <vector>
//#include <algorithm>
//#include <cstdlib>

/*long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                long long(numbers[first]) * long long(numbers[second]));
        }
    }

    return max_product;
}*/

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int maxIndex1 = -1;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
        if (maxIndex1 == -1 || numbers[i] > numbers[maxIndex1])
            maxIndex1 = i;
    
    int maxIndex2 = -1;
    for (int j = 0; j < n; j++)
        if (j != maxIndex1 && (maxIndex2 == -1 || numbers[j] > numbers[maxIndex2]))
            maxIndex2 = j;
     
    long long max_product = (long long)numbers[maxIndex1] * (long long)numbers[maxIndex2];
    
    return max_product;
}

int main() {
    /*while (true)
    {
        int n = rand() % 4 + 2;
        std::vector<int> numbers(n);
        for (int i : numbers)
            numbers[i] = rand() % 10;
        if (MaxPairwiseProductFast(numbers) != MaxPairwiseProduct(numbers))
            break;
    }*/
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    
    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
