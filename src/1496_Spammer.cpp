#include <iostream>
#include <map>

int main() {
	int n;
	std::cin >> n;
	std::map<std::string, int> mTeamCounter;
	while (n--) {
		std::string strTeamName;
		std::cin >> strTeamName;
		mTeamCounter[strTeamName] += 1;
	}
	
	for (auto& team : mTeamCounter) {
		if (team.second > 1) {
			std::cout << team.first << std::endl;
		}
	}
	return 0;
}
