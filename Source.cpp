#include <stdio.h>

const float PI = 3.14159265358979323846264338327950288419716939937510;

float arctan(float x) {
	if (x > 1) {
		x = 1 / x;
		float sum = x;
		float num = x;
		float den = 1;
		for (int i = 1; i < 100; i++)
		{
			num *= -x * x;
			den += 2;
			sum += num / den;
		}
		return PI / 2 - sum;
	}
	else if (x < -1) {
		x = 1 / x;
		float sum = x;
		float num = x;
		float den = 1;
		for (int i = 1; i < 100; i++)
		{
			num *= -x * x;
			den += 2;
			sum += num / den;
		}
		return -PI / 2 - sum;
	}
	else {
		float sum = x;
		float num = x;
		float den = 1;
		for (int i = 1; i < 100; i++)
		{
			num *= -x * x;
			den += 2;
			sum += num / den;
		}
		return sum;
	}
}

float sqrt(float x) {
	long i = *(long*)&x;
	i = (i >> 1) + 0x1fbd3ee7;
	float y = *(float*)&i;
	y = 0.5 * (y + x / y);
	return 0.5 * (y + x / y);
}

int factorial(int x)
{
	int ans = 1;
	for (int i = 1; i <= x; i++)
	{
		ans *= i;
	}
	return ans;
}

float pow(float x, int power) {
	float result = 1;
	bool sign = power > 0;
	int pow = power * (((int)!sign * -2) + 1);
	for (int i = 0; i < pow; i++) {
		result *= x;
	}
	return sign ? result : 1.0 / result;
}

float exp(float x) {
	float sum = 1;
	float prod = 1;
	for (int i = 1; i < 100; i++) {
		prod *= x / i;
		sum += prod;
	}
	return sum;
}

float ln(float x) {
	long i = *(long*)&x;
	float y = (i / 8388608 - 127) * 0.693147181;
	y = y + x * exp(-y) - 1;
	return y + x * exp(-y) - 1;
}

float log(float b, float x) {
	return ln(x) / ln(b);
}

class Complex
{
public:
	float real, imag;
	Complex(float r = 0, float i = 0) { real = r; imag = i; }

	float radius() {
		return sqrt(real * real + imag * imag);
	}

	float angle() {
		if (real > 0) {
			return arctan(imag / real);
		}
		else if (real < 0) {
			return arctan(imag / real) + PI * (((int)(imag < 0) * -2) + 1);
		}
		else
		{
			return PI / 2 * (((int)(imag < 0) * -2) + 1);
		}
	}

	void print() {
		printf("%Lf + %Lfi\n", real, imag);
	}
};

Complex operator + (const Complex& c1, const Complex& c2) {
	return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator + (const Complex& c1, const float val) {
	return Complex(c1.real + val, c1.imag);
}

Complex operator + (const float val, const Complex& c1) {
	return c1 + val;
}

Complex operator - (const Complex& c1, const Complex& c2) {
	return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

Complex operator - (const Complex& c1, const float val) {
	return Complex(c1.real - val, c1.imag);
}

Complex operator - (const float val, const Complex& c1) {
	return Complex(val - c1.real, -c1.imag);
}

Complex operator * (const Complex& c1, const Complex& c2) {
	return Complex((c1.real * c2.real) - (c1.imag * c2.imag), (c1.real * c2.imag) + (c2.real * c1.imag));
}

Complex operator * (const Complex& c1, const float val) {
	return Complex(c1.real * val, c1.imag * val);
}

Complex operator * (const float val, const Complex& c1) {
	return c1 * val;
}

Complex operator / (const Complex& c1, const Complex& c2) {
	float r = ((c1.real * c2.real) + (c1.imag * c2.imag)) / (c2.real * c2.real + c2.imag * c2.imag);
	float i = ((c1.imag * c2.real) - (c1.real * c2.imag)) / (c2.real * c2.real + c2.imag * c2.imag);
	return Complex(r, i);
}

Complex operator / (const Complex& c1, float val) {
	return Complex(c1.real / val, c1.imag / val);
}

Complex operator / (const float val, const Complex& c1) {
	float r = (val * c1.real) / (c1.real*c1.real + c1.imag*c1.imag);
	float i = -(val * c1.imag) / (c1.real*c1.real + c1.imag * c1.imag);
	return Complex(r, i);
}

Complex exp(Complex z) {
	Complex sum = 1;
	Complex prod = 1;
	for (int i = 1; i < 100; i++) {
		prod = prod * z / i;
		sum = sum + prod;
	}
	return sum;
}

Complex ln(Complex z) {
	float r = ln(z.radius());
	z.imag = z.angle();
	z.real = r;
	return z;
}

Complex log(Complex b, Complex x) {
	return ln(x) / ln(b);
}

Complex pow(Complex b, Complex x) {
	return exp(ln(b) * x);
}


int main()
{
	Complex z = pow(2, Complex(2.3, 0));
	z.print();
}