#include <iostream>

int gcd_fast(int a, int b) {
  if(b==0)
  	return a;
  return gcd_fast(b,a%b);
}
long long lcm_naive(int a, int b) {
	int gcd = gcd_fast(a,b);
	long long temp = (long long)a * b;
	long long lcm = (long long) (temp/gcd);

  return (long long) lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
