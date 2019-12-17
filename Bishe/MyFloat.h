#pragma once
#include <string>
typedef MyFloat* MyFloatPtr;
/*�Զ��帡������*/
class MyFloat{
private:
	bool bSign; // ����λ 1λ

	char cExponent;	// ָ��Ϊ ��-126��127 8λ

	unsigned char *ulMantissa; // β��

	int mantissaSize;// β�� 23λ

public:
	MyFloat();
	MyFloat(bool sign, char ex, unsigned char *mantissa, int size);
	// ȡ��һ��������
	MyFloat* up();
	// β��+1
	void mantissaUp(bool sign);
	// �ж������������Ƿ����
	bool equals(MyFloat *other);
	// �ж��Ƿ�Ϊ���������ֵ
	bool isFloatMax();
	// set
	MyFloat setToOne(unsigned char *mantissa, int type);
	// ����β����1�ĸ���
	int countOne(unsigned char *mantissa);
	// ת��Ϊʮ����
	std::string to_decimal();
	// ת��Ϊ�ַ���
    std::string to_string();
};