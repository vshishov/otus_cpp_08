#include <iostream>
#include <map>
#include <string>

int main() 
{
	int n;
	std::cin >> n;
	std::map<char, std::string> vChars;

	while (n--) {
		char ch1, ch2;
		std::cin >> ch1 >> ch2;
		vChars[ch1] += ch2;
	}
	
	char c;
	std::cin >> c;
	
	for (auto ch : vChars[c]) {
		std::cout << c << ch << std::endl;
	}
	return 0;
}
