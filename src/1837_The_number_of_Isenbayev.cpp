#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

struct Man
{
	Man(const std::string& s, int l = -1)
		: name(s)
		, level(l)
	{	}
	
	void add(Man* m) 
	{ 
		if (m != nullptr) {
			for ( auto man : teams ) {
				if (man->name == m->name) 
					return;
			}
			teams.emplace_back(m);
		}
	}
	
	std::string name;
	int level = -1;
	std::vector<Man*> teams;
};

int main() {	
	std::vector<Man*> mans;
	
	int n;
	std::cin >> n;
	mans.reserve(n * 3);
	for (int i = 0; i < n; ++i) {
		std::string name[3];
		std::cin >> name[0] >> name[1] >> name[2];

		int el[3] = {0};

		for (int l = 0, j = 0; l < 3; ++l) {
			for (j = 0; j < mans.size(); ++j) {
				if(mans[j]->name == name[l]) {
					el[l] = j;
					break;
				}
			}

			if (j == mans.size()) {
				mans.push_back(new Man(name[l]));
				el[l] = j;
			}
		}

		mans[el[0]]->add(mans[el[1]]);	mans[el[0]]->add(mans[el[2]]);
		mans[el[1]]->add(mans[el[0]]);	mans[el[1]]->add(mans[el[2]]);
		mans[el[2]]->add(mans[el[0]]);	mans[el[2]]->add(mans[el[1]]);
		
	}
	
	int idx = -1;
	for (int i = 0; i < mans.size(); ++i) {
		if (mans[i]->name == "Isenbaev") {
			mans[i]->level = 0;
			idx = i;
			break;
		}
	}
	
	if (idx != -1) {
		std::map<Man*, bool> used;
		std::queue<Man*> q;
		for (int i = 0; i < mans.size(); ++i) {
		  used[mans[i]] = false;
    }
	
		q.push(mans[idx]);
		used[mans[idx]] = true;

		while ( !q.empty() ) {
			Man* node = q.front();
			q.pop();

			used[node] = true;

			for (int i = 0; i < node->teams.size(); ++i) {
				Man* child = node->teams[i];
				if (!used[child]) {
					child->level = node->level + 1;
					used[child] = true;
					q.push(child);
				}
			}
		}
	}
	
	std::sort(mans.begin(), mans.end(), [](Man* el1, Man* el2){ return el1->name < el2->name;});
	
	for (auto& man : mans) {
		std::string l = man->level == -1 ? "undefined" : std::to_string(man->level);
		std::cout << man->name << ' ' << l << std::endl;
	}
	
	return 0;
}
