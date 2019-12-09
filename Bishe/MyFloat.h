#pragma once
#include <string>

class MyFloat{
private:
	bool bSign; // ����λ 1λ

	char cExponent;	// ָ��Ϊ ��-126��127 8λ

	unsigned char* ulMantissa; // β��

	int mantissaSize;// β�� 23λ

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