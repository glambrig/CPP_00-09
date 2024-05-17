#include "Serializer.hpp"
#include "Data.hpp"
#include <iomanip>

int	main(void)
{
	Data 					data(12345);
	unsigned long long		num;

	std::cout << "Original pointer = " << &data << std::endl;
	num = Serializer::serialize(&data);
	std::cout << "Result of serialization is: 0x" << std::hex << num << std::endl;
	std::cout << "Result of deserialization is: " << Serializer::deserialize(num) << std::endl;
}