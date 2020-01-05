#include <iostream>
#include <cstdint>
#include <vector>
#include <string>

// My personal (poor) C++ code showing how to reverse the XOR encryption in the xordemo crackme
std::vector<std::uint8_t> do_xor()
{
	// const char* base_key = "1feebdab";
	// the string gets reversed based on the endianness of x86,
	// so it actually is:
	const char* base_key = "badbeef1";
	std::uint8_t byte_code[] =
	{ 0x10, 0x14, 0x0A, 0x05, 0x0C, 0x17, 0x0A, 0x02 };	
	const std::int32_t size = std::strlen(base_key);
	std::vector<std::uint8_t> data = {};
	
	for (std::int32_t i = 0; i < size; i++)
	{
		std::uint8_t xor_value = base_key[i] ^ byte_code[i];
		data.push_back(xor_value);
	}

	return data;
}

std::int32_t main(std::int32_t argc, const char* argv[])
{
	std::vector<std::uint8_t> data = do_xor();
	std::string input;
	
	std::cout << data.data() << std::endl;

	std::cin >> input;

	return 0;
}
