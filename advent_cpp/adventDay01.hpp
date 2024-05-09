//
//  adventDay01.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 4/30/24.
//

#ifndef adventDay01_hpp
#define adventDay01_hpp

#include <algorithm>
#include <regex>
#include <stdio.h>
#include "adventDay.hpp"
#include "utils.hpp"


static std::vector<std::string> nums {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
static std::vector<std::string> digits {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

class AdventDay01 : public AdventDay {
	protected:
		std::vector<std::string> numWords {};
		std::regex regexNumWords;
	
		static std::string toDigit(std::string s) {
			if (std::isdigit(s[0])) {
				return s;
			}
			return std::format("{:d}", indexOf(toLowerCase(s), nums) + 1);
		}
	
		int cumulativeCal(int current, std::string s) {
			return current + getCalibration(s);
		}
		
		int getCalibrations(std::vector<std::string> v) {
			int res = 0;
			for (std::string s : v) {
				res += getCalibration(s);
			}
			return res;
		}
	
		int getCalibration(std::string s) {
			std::vector<std::string> matches = findAll(s, regexNumWords);
			std::transform(matches.cbegin(), matches.cend(), matches.begin(), toDigit);
			return matches.empty() ? 0 : 10 * std::stoi(matches.front()) + std::stoi(matches.back());
		}

	
	public:
		AdventDay01();
	
		void run(std::vector<std::string> v) {
			std::cout << "CALS " << getCalibrations(v) << "\n";
		};
};

#endif /* adventDay01_hpp */
