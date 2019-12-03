#include <iostream>
#include <string>
#include "program1.h"

/*
	��ԭָ��תΪ���ָ�ԭָ�����ʽ�л����롢��ࡢ�ַ���
	type �� ԭָ������ͣ� 1 �� ������, 2 �� ���, 3���ַ���
*/
std::string sourceInstructionToCompilation(std::string input, int type) {
	std::string result;
	switch (type)
	{
	case 1:
		// ������ת���
		result = machineInstructionToCompilation(input);
		break;
	case 2:
		// ���ת���
		result = input;
		break;
	case 3:
		// �ַ���ת���
		result = stringInstructionToCompilation(input);
		break;
	default:
		// �������
		result = "";
		break;
	}
	return result;
}

/*
	����ָ��תΪ���ָ��
*/
std::string machineInstructionToCompilation(std::string machineInstruction) {
	// TODO
	return machineInstruction;
}

/*
	�ַ�ָ��תΪ���ָ��
*/
std::string stringInstructionToCompilation(std::string stringInstruction) {
	// TODO
	return stringInstruction;
}