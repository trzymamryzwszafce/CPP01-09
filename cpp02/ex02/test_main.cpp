#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

static int g_pass = 0;
static int g_fail = 0;

static std::string toStr(float value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

static std::string toStr(int value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

static void check(std::string const &label, bool condition, std::string const &detail = "")
{
	if (condition)
	{
		g_pass++;
		std::cout << "[OK]   " << label << std::endl;
	}
	else
	{
		g_fail++;
		std::cout << "[FAIL] " << label;
		if (!detail.empty())
			std::cout << "  -> " << detail;
		std::cout << std::endl;
	}
}

static bool floatClose(float a, float b, float eps = 0.01f)
{
	return (std::fabs(a - b) < eps);
}

int main(void)
{
	std::cout << "===== Constructors & conversions =====" << std::endl;
	{
		Fixed def;
		check("default constructor -> toFloat() == 0", floatClose(def.toFloat(), 0.0f),
			"got " + toStr(def.toFloat()));

		Fixed fromInt(10);
		check("Fixed(10).toInt() == 10", fromInt.toInt() == 10,
			"got " + toStr(fromInt.toInt()));
		check("Fixed(10).toFloat() == 10.0", floatClose(fromInt.toFloat(), 10.0f),
			"got " + toStr(fromInt.toFloat()));
		check("Fixed(10).getRawBits() == 2560", fromInt.getRawBits() == 2560,
			"got " + toStr(fromInt.getRawBits()));

		Fixed fromFloat(42.42f);
		check("Fixed(42.42f).toFloat() close to 42.42", floatClose(fromFloat.toFloat(), 42.42f, 0.01f),
			"got " + toStr(fromFloat.toFloat()));

		Fixed neg(-5);
		check("Fixed(-5).toInt() == -5", neg.toInt() == -5,
			"got " + toStr(neg.toInt()));

		Fixed copyCtor(fromInt);
		check("copy constructor preserves value", copyCtor.getRawBits() == fromInt.getRawBits());

		Fixed copyAssign;
		copyAssign = fromInt;
		check("copy assignment preserves value", copyAssign.getRawBits() == fromInt.getRawBits());

		Fixed rawTest;
		rawTest.setRawBits(256);
		check("setRawBits(256).toInt() == 1 (raw bypasses scaling)", rawTest.toInt() == 1,
			"got " + toStr(rawTest.toInt()));
	}

	std::cout << "\n===== Comparison operators =====" << std::endl;
	{
		Fixed a(5);
		Fixed b(10);
		Fixed c(5);

		check("5 > 10 == false", (a > b) == false);
		check("10 > 5 == true", (b > a) == true);
		check("5 < 10 == true", (a < b) == true);
		check("10 < 5 == false", (b < a) == false);
		check("5 >= 5 == true", (a >= c) == true);
		check("5 <= 5 == true", (a <= c) == true);
		check("5 == 5 == true", (a == c) == true);
		check("5 == 10 == false", (a == b) == false);
		check("5 != 10 == true", (a != b) == true);
		check("5 != 5 == false", (a != c) == false);
	}

	std::cout << "\n===== Arithmetic operators =====" << std::endl;
	{
		Fixed a(5);
		Fixed b(2);
		Fixed half(0.5f);

		Fixed sum = a + b;
		check("5 + 2 == 7", floatClose(sum.toFloat(), 7.0f), "got " + toStr(sum.toFloat()));

		Fixed diff = a - b;
		check("5 - 2 == 3", floatClose(diff.toFloat(), 3.0f), "got " + toStr(diff.toFloat()));

		Fixed prod = a * b;
		check("5 * 2 == 10", floatClose(prod.toFloat(), 10.0f), "got " + toStr(prod.toFloat()));

		Fixed prodFrac = a * half;
		check("5 * 0.5 == 2.5", floatClose(prodFrac.toFloat(), 2.5f), "got " + toStr(prodFrac.toFloat()));

		Fixed quot = a / b;
		check("5 / 2 == 2.5", floatClose(quot.toFloat(), 2.5f), "got " + toStr(quot.toFloat()));

		Fixed bigMul(1000.5f);
		Fixed bigMul2(3.25f);
		Fixed bigProd = bigMul * bigMul2;
		check("1000.5 * 3.25 == 3251.625", floatClose(bigProd.toFloat(), 3251.625f, 0.05f),
			"got " + toStr(bigProd.toFloat()));
	}

	std::cout << "\n===== Increment / decrement =====" << std::endl;
	{
		Fixed a(5);
		Fixed preResult = ++a;
		check("prefix ++ modifies original", floatClose(a.toFloat(), 5.0f + 1.0f / 256.0f, 0.001f),
			"got " + toStr(a.toFloat()));
		check("prefix ++ returns updated value", floatClose(preResult.toFloat(), a.toFloat()));

		Fixed b(5);
		Fixed postResult = b++;
		check("postfix ++ returns OLD value (5.0)", floatClose(postResult.toFloat(), 5.0f, 0.001f),
			"got " + toStr(postResult.toFloat()));
		check("postfix ++ still modifies original", floatClose(b.toFloat(), 5.0f + 1.0f / 256.0f, 0.001f),
			"got " + toStr(b.toFloat()));

		Fixed c(5);
		Fixed preDecResult = --c;
		check("prefix -- modifies original", floatClose(c.toFloat(), 5.0f - 1.0f / 256.0f, 0.001f),
			"got " + toStr(c.toFloat()));
		check("prefix -- returns updated value", floatClose(preDecResult.toFloat(), c.toFloat()));

		Fixed d(5);
		Fixed postDecResult = d--;
		check("postfix -- returns OLD value (5.0)", floatClose(postDecResult.toFloat(), 5.0f, 0.001f),
			"got " + toStr(postDecResult.toFloat()));
		check("postfix -- still modifies original", floatClose(d.toFloat(), 5.0f - 1.0f / 256.0f, 0.001f),
			"got " + toStr(d.toFloat()));
	}

	std::cout << "\n===== min / max (non-const) =====" << std::endl;
	{
		Fixed a(5);
		Fixed b(10);

		check("min(5, 10) == 5", floatClose(Fixed::min(a, b).toFloat(), 5.0f),
			"got " + toStr(Fixed::min(a, b).toFloat()));
		check("min(10, 5) == 5", floatClose(Fixed::min(b, a).toFloat(), 5.0f),
			"got " + toStr(Fixed::min(b, a).toFloat()));
		check("max(5, 10) == 10", floatClose(Fixed::max(a, b).toFloat(), 10.0f),
			"got " + toStr(Fixed::max(a, b).toFloat()));
		check("max(10, 5) == 10", floatClose(Fixed::max(b, a).toFloat(), 10.0f),
			"got " + toStr(Fixed::max(b, a).toFloat()));

		Fixed &minRef = Fixed::min(a, b);
		minRef = Fixed(99);
		check("min() returns a real reference (mutation reflected in original)",
			floatClose(a.toFloat(), 99.0f), "got a=" + toStr(a.toFloat()));
	}

	std::cout << "\n===== min / max (const) =====" << std::endl;
	{
		Fixed const a(5);
		Fixed const b(10);

		check("const min(5, 10) == 5", floatClose(Fixed::min(a, b).toFloat(), 5.0f),
			"got " + toStr(Fixed::min(a, b).toFloat()));
		check("const max(5, 10) == 10", floatClose(Fixed::max(a, b).toFloat(), 10.0f),
			"got " + toStr(Fixed::max(a, b).toFloat()));
		// NOTE: the following would (and should) fail to COMPILE if uncommented,
		// proving your const-correctness works:
		// Fixed::min(a, b) = Fixed(1);
	}

	std::cout << "\n===== operator<< =====" << std::endl;
	{
		Fixed a(5);
		std::cout << "  (visual check) a is " << a << std::endl;
	}

	std::cout << "\n=====================================" << std::endl;
	std::cout << "Passed: " << g_pass << " / " << (g_pass + g_fail) << std::endl;
	if (g_fail > 0)
		std::cout << g_fail << " test(s) FAILED — see [FAIL] lines above." << std::endl;
	else
		std::cout << "All tests passed." << std::endl;
	return (g_fail > 0 ? 1 : 0);
}
