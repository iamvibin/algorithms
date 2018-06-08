#include<iostream>
#include<cmath>
#include<vector>
#include <string>
#include <sstream>

using namespace std;

string multiply(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	vector<int> result(n1+n2,0);
	int index1 = 0;
	int index2 = 0;
	
		int carry =0;
	for(int i = n1-1; i>=0 ; i--)
	{
		int n1_c = num1[i] - '0';
		index2 = 0;
		for(int j = n2-1; j>=0; j--)
		{
			int n2_c = num2[j] - '0';
			
			int sum =  n1_c * n2_c + result[index1 + index2] + carry;
			carry = sum/10;
			result[index1 + index2] = sum%10;
			
			index2++;
		}
		
		
		index1++;
	}
	if(carry>0)
		{
			result[index1 + index2] += carry;
		}
	int iter =  result.size() - 1;
	int i = result.size() - 1;
	while(iter >= 0 && result[i] == 0)
		i--;
	if(i == -1)
	return "0";
	
	string s = "";
	
	while(i>=0)
	{
		std::stringstream ss; 
		ss << result[i--];
		std::string str = ss.str();
		s += str;
	}
	return s;
}

int main(){
	string str1 = "3141592653589793238462643383279502884197169399375105820974944592";
    string str2 = "2718281828459045235360287471352662497757247093699959574966967627";
    cout << multiply(str1, str2);
    
    return 0;
}
