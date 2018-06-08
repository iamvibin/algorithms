#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long  MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
	int max1 = 0;
	int max2 = 0;
	if(numbers[0] > numbers[1]){
		 max1 = numbers[0];
		max2 = numbers[1];
	}
	else {
		 max1 = numbers[1];
		 max2 = numbers[0];
	}
    for (int first = 2; first < n; ++first) {
        if(max2 < numbers[first])
        {
        	if(max1 < numbers[first])
        	{
        		max2=max1;
        		max1=numbers[first];
        	}
        	else {
        		max2=numbers[first];
        	}
        }
    }
    
	max_product = (long long)max2 * max1;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}
