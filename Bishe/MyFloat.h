#pragma once
#include <string>

class MyFloat{
private:
	bool bSign; // 符号位 1位

	char cExponent;	// 指数为 从-126到127 8位

	unsigned char* ulMantissa; // 尾数

	int mantissaSize;// 尾数 23位

public:
	MyFloat();
	MyFloat* up();
	void mantissaUp(bool sign);
	bool equals(MyFloat* other);
	bool isFloatMax();
	MyFloat setToOne(unsigned char* mantissa, int type);
	int countOne(unsigned char * mantissa);
	MyFloat(bool sign, char ex, unsigned char* mantissa, int size);
	std::string to_decimal();
    std::string to_string();
};