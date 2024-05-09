//
//  utils.cpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/2/24.
//

#include "utils.hpp"

std::vector<std::string> findAll(std::string s, std::regex r) {
	std::string sc = s;
	std::vector<std::string> (matches);
	for (std::smatch sm; std::regex_search(sc, sm, r); ) {
		matches.push_back(sm[1].str());
		sc = sm.suffix();
	}
	return matches;
}

std::string join(std::vector<std::string> v, char delim) {
	std::string j = "";
	int i = 0;
	for (std::string s : v) {
		j = j + s;
		if (++i < v.size()) {
			j = j + delim;
		}
	}

	return j;
}

ptrdiff_t indexOf(std::string s, std::vector<std::string> v) {
	return std::distance(v.begin(), find(v.begin(), v.end(), s));
};

std::string toLowerCase(std::string s) {
	
	std::string l = "";
	for (char c: s) {
		l += tolower(c);
	}
	return l;
}
