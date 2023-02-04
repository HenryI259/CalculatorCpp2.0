#include <stdio.h>

class Complex
{

};

static class Math
{
public:
	int factorial(int x)
	{
		int ans = 1;
		for (int i = 1; i <= x; i++)
		{
			ans *= i;
		}
		return ans;
	}

	long double func(int x, int y)
	{
		return negExp(x, y);
	}

	
private:
	long double exp(long double x, int power) {
		long double result = x;
		bool sign = power > 0;
		int pow = power * (((int)!sign * -2) + 1);
		for (int i = 1; i < pow; i++) {
			result *= x;
		}
		return sign ? result : 1.0 / result;
	}

	long double posExp(long double x, int power) {
		long double result = x;
		for (int i = 1; i < power; i++) {
			result *= x;
		}
		return result;
	}

	long double negExp(long double x, int power) {
		long double result = 1/x;
		for (int i = 1; i < -power; i++) {
			result /= x;
		}
		return result;
	}
};

int main()
{
	Math math;
	long double x = math.func(2, -2);
	printf("%Lf", x);
	for (int i = 0; i < 200000000; i++)
	{
		math.func(2, -2);
	}
}