//
//  utils.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/2/24.
//

#ifndef utils_hpp
#define utils_hpp

#include <algorithm>
#include <iostream>
#include <regex>
#include <stdio.h>
#include <string>
#include <vector>

std::vector<std::string> findAll(std::string s, std::regex r);
ptrdiff_t indexOf(std::string s, std::vector<std::string> v);
std::string join(std::vector<std::string> v, char delim = ',');
std::string toLowerCase(std::string s);

#endif /* utils_hpp */
