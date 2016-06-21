#include <iostream>
#include <string>


bool IsLeftMostBitSet(unsigned int value)
{
	int modValue = value & 128;
	return (modValue == 128);
};
bool IsRightMostBitSet(unsigned int value)
{
	int modValue = value & 1;
	return (modValue == 1);
};
bool IsBitSet(unsigned int value, unsigned char bit_to_check)
{
	return ((value >> bit_to_check) & 1);
};
int GetRightMostSetBit(unsigned int value)
{
	if (value == 0)
	{
		return -1;
	}
	return log2(value&(-value)) + 1;
};
void PrintBinary(unsigned char value)
{
	std::string binaryString;
	for (int i = 8; i > 0; i--)
	{
		if (IsBitSet(value, i))
		{
			binaryString += "1";
		}
		else 
		{
			binaryString += "0";
		}
	}
	std::cout << binaryString << '\n';
};
bool IsPowerOfTwo(unsigned int value)
{
	if (((value != 0) && (value & (~value + 1)) == value))
	{
		return true;
	}
	else
	{
		return false;
	}
};
int main()
{
	unsigned int a;
	a = 200;
	IsLeftMostBitSet(a);
	a = 20;
	IsLeftMostBitSet(a);
	a = 200;
	IsRightMostBitSet(a);
	a = 1;
	IsRightMostBitSet(a);
	IsBitSet(a, 2);
	a = 4;
	IsBitSet(a, 2);
	a = 32;
	GetRightMostSetBit(a);
	a = 0;
	GetRightMostSetBit(a);
	a = 83;
	PrintBinary(a);
	a = 64;
	IsPowerOfTwo(a);
	a = 81;
	IsPowerOfTwo(a);

	system("PAUSE");
	return 0;
}

//
//
////Binary Questions!
//
////1. Convert the following from decimal to binary
////1 = 000000001
////42 = 00101010
////256 = 101100101
////4,294,967,296 = 10000000000000000000000000000000
//
////2. Convert the following from binary to decimal
////10000000 = 128	
////10101010 = 170
////11110000 = 240
////11001100 = 204
//
////3. Solve these binary arithmatic problems
////111 + 111 = 110
////1010 + 1010 = 0100
////11101 + 1010 = 00111
////1011 - 11 = 1000
////10001 - 100 = 00101
////101 * 10 = 1010
////1011 * 11 = 33 100001
////1101 / 11 = 100.100001
//
////4. In many places, numbers stored in computers are displayed as hexadecimal (base 16). What
////advantages do hex numbers have over decimal and binary numbers respectively when
////displaying numbers stored in a computer?
////Hexadecimal takes up less space and it is a lot easier to read in comparison to decimal.
//
////5. Using Two's complement convert the following between decimal and binary (for binary use 1
////signed byte)
////10000000 = 10000000 = -128
////10101010 = 01010110 = 86
////11110000 = 00010000 = 16
////11001100 = 00110100 = 52
////-16 = 11110000
////128 = 10000000
////-128 = 10000000
////-123 = 01100001
//
////6. What do each of these evaluate to?
////11111 | 11111 = 11111
////11111 ^ 11111 = 00000
////10101 & 11111 = 10101
////10101 | 11111 = 11111
////10101 ^ 11111 = 01010
////1 << 3 = 1000
////100 >> 2 = 1
////~10101 = 01010
////100 << 1 = 1000
////1010 >> 1 = 101.0
////~11111 = 00000
//
////7. A true/false value can be stored in a single bit – zero for false, one for true. However, the
////Boolean type in C is a full byte big – 8 bits. This means it is possible to store 8 bits in a single
////byte. Using bitwise operators, how might you:
////- Set a single bit to 0: OR
////- Set a single bit to 1: AND
////- Check the value of a single bit: AND
