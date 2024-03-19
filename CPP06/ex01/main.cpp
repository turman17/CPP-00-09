#include "Serialize.hpp"
#include <iostream>

int main()
{
	Data myData;
	myData.value = 123;
	// Serialize the Data* pointer
	uintptr_t serializedData = Serialize::serialize(&myData);
	// Deserialize back to Data* pointer
	Data *deserializedData = Serialize::deserialize(serializedData);
	if (&myData == deserializedData)
	{
		std::cout << "Success: The original and deserialized pointers match." << std::endl;
		std::cout << "Data value: " << deserializedData->value << std::endl;
	}
	else
		std::cout << "Error: The original and deserialized pointers do not match." << std::endl;
	return 0;
}