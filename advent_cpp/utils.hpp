//
//  utils.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/2/24.
//

#ifndef utils_hpp
#define utils_hpp

#include <algorithm>
#include <exception>
#include <format>
#include <iostream>
#include <map>
#include <regex>
#include <stdio.h>
#include <string>
#include <string_view>
#include <vector>

std::vector<std::vector<std::string>> findAll(std::string s, std::regex r);
ptrdiff_t indexOf(std::string s, std::vector<std::string> v, unsigned long start = 0);
std::string join(std::vector<std::string> v, char delim = ',');
std::string join(std::vector<int> v, char delim = ',');
void print(std::string);
void print(std::vector<std::string> v);
void print(std::map<std::string, int> m);
std::vector<int> range(int min, int max);
std::vector<std::string> reSplit(std::regex r, std::string s);
std::string toLowerCase(std::string s);
std::string toString(std::vector<std::string> v);
std::string toString(std::map<std::string, int> m);
std::string trim(std::string s);

#endif /* utils_hpp */
