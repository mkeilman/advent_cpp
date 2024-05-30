//
//  utils.cpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/2/24.
//

#include "utils.hpp"

std::vector<std::vector<std::string>> findAll(std::string s, std::regex r) {
	std::string sc = s;
	std::vector<std::vector<std::string>> (matches);
	for (std::smatch sm; std::regex_search(sc, sm, r); ) {
		std::vector<std::string> v = {};
		for (int i = 1; i < sm.size(); ++i) {
			v.push_back(sm[i].str());
		}
		matches.push_back(v);
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

std::string join(std::vector<int> v, char delim) {
	std::vector<std::string> t(v.size());
	std::transform(v.cbegin(), v.cend(), t.begin(), [](int n) { return std::to_string(n); });
	return join(t);
}

ptrdiff_t indexOf(std::string s, std::vector<std::string> v, unsigned long start) {
	return std::distance(v.begin() + start, find(v.begin() + start, v.end(), s));
}

void print(std::string s)  {
	std::cout << s << '\n';
}

void print(std::vector<std::string> v) {
	print(toString(v));
}

void print(std::map<std::string, int> m) {
	print(toString(m));
}

std::vector<int> range(int min, int max) {
	std::vector<int> r;
	
	if (max < min) {
		throw std::runtime_error(std::format("Max {} < min {}", max, min));
	}
	for (int i = min; i < max; ++i) {
		r.push_back(i);
	}
	return r;
}

std::vector<std::string> reSplit(std::regex r, std::string s) {
	return {
		std::sregex_token_iterator(s.begin(), s.end(), r, -1),
		std::sregex_token_iterator()
	};
}

std::string toLowerCase(std::string s) {
	
	std::string l = "";
	for (char c: s) {
		l += tolower(c);
	}
	return l;
}

std::string toString(std::vector<std::string> v) {
	return "[" + join(v) + "]";
}

std::string toString(std::map<std::string, int> m) {
	std::string s = "{";
	for (auto &[k, v]: m) {
		s += (k + ":" + std::format("{}", v) + ",");
	}
	s += "}";
	return s;
}

std::string trim(std::string s) {
	const std::string w = " \t\n\r\f\v";
	std::string_view v(s);
	v.remove_prefix(std::min(v.find_first_not_of(w), v.length()));
	v.remove_suffix(std::min(v.length() - v.find_last_not_of(w) - 1, v.length()));
	return std::string(v);
}
