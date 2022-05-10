#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> decTobin(int x)
{
	bool sign = 0;
	vector<bool> a;

	if (x >= 0)
	{
		while (x != 0)
		{
			if (x & 1)
			{
				a.push_back(1);
			}
			else
			{
				a.push_back(0);
			}
			x = x >> 1;
		}
		while (a.size() < 8)
		{
			a.push_back(0);
		}
	}
	else
	{
		x = -x;
		while (x != 0)
		{
			if (x & 1)
			{
				a.push_back(1);
			}
			else
			{
				a.push_back(0);
			}
			x = x >> 1;
		}
		while (a.size() < 7)
		{
			a.push_back(0);
		}
		a.push_back(1);
	}
	reverse(a.begin(), a.end());

	while (a.size() > 8)
	{
		a.pop_back();
	}
	return a;
}
int binTodec(vector<bool> a)
{
	int a_int = 0;
	if (a.at(0) & 1)
	{
		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size() - 1; i++)
		{
			a_int = a_int + a.at(i) * pow(2, i);
		}
		a_int = -a_int;
	}
	else
	{
		reverse(a.begin(), a.end());
		for (int i = 0; i < a.size() - 1; i++)
		{
			a_int = a_int + a.at(i) * pow(2, i);
		}
	}
	return a_int;
}
int input(string name)
{
	int x;
	cout << "Input (dec) " << name << "=";
	cin >> x;
	return x;
}
void output(vector<bool> a, string name)
{
	cout << "Output (bin) " << name << "=";
	for (int i = 0; i < a.size(); i++)
		cout << a.at(i);
	cout << endl;
	cout << "Output (dec) " << name << "=" << binTodec(a) << endl;
}

vector<bool> add(vector<bool> a, vector<bool> b)
{
	vector<bool> sum;
	bool sig = 0;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) + b.at(i) + sig == 2)
		{
			sum.push_back(0);
			sig = 1;
		}
		else if (a.at(i) + b.at(i) + sig == 3)
		{
			sum.push_back(1);
			sig = 1;
		}
		else
		{
			sum.push_back(a.at(i) + b.at(i) + sig);
			sig = 0;
		}
	}
	reverse(sum.begin(), sum.end());
	return sum;
}

vector<bool> oneComplement(vector<bool> a)
{
	vector<bool> one;
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) & 1)
			one.push_back(0);
		else
			one.push_back(1);
	}
	return one;
}
vector<bool> twoComplement(vector<bool> a)
{
	vector<bool> two;
	vector<bool> number1;
	for (int i = 0; i < 7; i++)
	{
		number1.push_back(0);
	}
	number1.push_back(1);
	two = add(oneComplement(a), number1);
	return two;
}
vector<bool> subtract(vector<bool> a, vector<bool> b)
{
	vector<bool> diff;
	diff = add(a, twoComplement(b));
	return diff;
}
vector<bool> multiply(vector<bool> a, vector<bool> b)
{
	vector<bool> product;
	vector<bool> med;
	for (int i = 0; i < 8; i++)
	{
		product.push_back(0);
	}
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) & 1)
		{
			med = b;
			for (int j = 0; j < i; j++)
			{
				med.push_back(0);
			}
			product = add(product, med);
		}
	}
	return product;
}
vector<bool> divide_a(vector<bool> a, vector<bool> b)
{
	vector<bool> A;
	if (a.at(0) & 1)
	{
		for (int i = 0; i < 8; i++)
		{
			A.push_back(1);
		}
		int k = 8;
		while (k > 0)
		{
			A.push_back(a.at(0));
			A.erase(A.begin());
			a.push_back(0);
			a.erase(a.begin());
			A = subtract(A, b);
			if (A.at(0) & 1)
			{
				a.at(a.size() - 1) = 0;
				A = add(A, b);
			}
			else
			{
				a.at(a.size()-1) = 1;
			}
			k = k - 1;
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			A.push_back(0);
		}
		int k = 8;
		while (k > 0)
		{
			A.push_back(a.at(0));
			A.erase(A.begin());
			a.push_back(0);
			a.erase(a.begin());
			A = subtract(A, b);
			if (A.at(0) & 1)
			{
				a.at(a.size()-1) = 0;
				A = add(A, b);
			}
			else
			{
				a.at(a.size()-1) = 1;
			}
			k = k - 1;
		}
	}
	return a;
}
vector<bool> divide_A(vector<bool> a, vector<bool> b)
{
	vector<bool> A;
	if (a.at(0) & 1)
	{
		for (int i = 0; i < 8; i++)
		{
			A.push_back(1);
		}
		int k = 8;
		while (k > 0)
		{
			A.push_back(a.at(0));
			A.erase(A.begin());
			a.push_back(0);
			a.erase(a.begin());
			A = subtract(A, b);
			if (A.at(0) & 1)
			{
				a.at(a.size() - 1) = 0;
				A = add(A, b);
			}
			else
			{
				a.at(a.size() - 1) = 1;
			}
			k = k - 1;
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			A.push_back(0);
		}
		int k = 8;
		while (k > 0)
		{
			A.push_back(a.at(0));
			A.erase(A.begin());
			a.push_back(0);
			a.erase(a.begin());
			A = subtract(A, b);
			if (A.at(0) & 1)
			{
				a.at(a.size() - 1) = 0;
				A = add(A, b);
			}
			else
			{
				a.at(a.size() - 1) = 1;
			}
			k = k - 1;
		}
	}
	return A;
}
int main()
{
	vector<bool> a;
	vector<bool> b;
	a = decTobin(input("a"));
	b = decTobin(input("b"));
	output(a, "a");
	output(b, "b");
	output(add(a, b), "sum");
	output(subtract(a, b), "diff");
	output(multiply(a, b), "product");
	output(divide_a(a, b), "quotient"); 
	output(divide_A(a, b), "surplus");
	return 0;
}


