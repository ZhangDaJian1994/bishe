#include <iostream>
#include <string>

template<class T>
/**
**	V1.3 ʹ��ģ��������float �� double
**/
struct MiddleValue
{
	// ���ͣ����ڱ�ʾ�����Ȼ�˫���ȸ���ֵ
	T value;
	// Ϊtrue ��ʾΪd�ұߵ����ڽ����м�㣬
	// Ϊfalse ��ʾΪd��ߵ����ڽ����м��
	bool direct
};

/**
** �����洢Nά�ռ��У�ÿһ��С���估���Ӧ����
**/
template<class T>

struct ResultList
{
	int n = 0;
	ResultList(int n) {
		n = n;
	}
	// Nά�ռ乲��2*N���м��ֵ������ÿһά�ռ��������м�㣬������ʾ��һά     // �����䷶Χ
	// ÿһ��ά�ȵ�����ֵ����ʾ���ά�ȵ����䣬��ô��ά�ȹ�����һ�������
	// �Խǵ㣬�ϲ���ʱ�������һ����ķ����
	struct MiddleValue<T> mid[2*n];

	// ����ֵ = Nά�ռ��ĳС�����Ӧ�ĸ���ֵ
	// error ��ʾ���������ֵ����irramʵ������ ��ȥ �������ֵ���븡�����     // �Ĳ�ֵ
	// error = irram���򣨸���ֵ��- ������򣨸���ֵ����
	REAL error;
};
// ��������
REAL * arrNLoop;

int getInstrutionVariableNumber(std::string inputInstruction) {
	// TODO ����ָ���м�������
	int n = 1;
	return n;
}

void initDataStruct(int n) {
	// ���峤��Ϊn�����飬�洢ÿ��ά�ȵ�ǰ�����ĸ���ֵ
	arrNLoop = new REAL[n];
	// �������ֵ��ʼ��Ϊ��������Сֵ
	init(arrNLoop);
}

void calc(std::string inputInstruction) {
	int n = getInstrutionVariableNumber(inputInstruction);
	initDataStruct(n);

	for (int i = 0; i < n; i++) {

	}

}

bool isFloatMax(float f) {
	return 
}