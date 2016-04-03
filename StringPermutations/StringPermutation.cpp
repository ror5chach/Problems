#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


// using backtracking algorithm
// the second swap is the backtracking which regains the original string after every iteration
//	http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

void swap(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp; 
}

void permutations(char* ch, int left, int right)
{
	if (left == right)
	{
		string str(ch);
		cout << str << endl;
	}
	else
	{
		for (int i = left; i <= right; ++i)
		{
			swap((ch+left), (ch+i));
			permutations(ch, left+1, right);
			swap((ch+left), (ch+i));			// backtracking to get back original string
		}
	}
}

int main()
{
	string input = "ABC";
	int len = input.length();

	char* ch = new char[len + 1];
	ch[input.length()] = '\0';
	memcpy(ch, input.c_str(), len);

	permutations(ch, 0, len-1);

	delete[] ch;
	return 0;
}