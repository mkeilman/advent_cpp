//
//  adventDay01.cpp
//  advent_cpp
//
//  Created by Michael Keilman on 4/30/24.
//

#include "adventDay01.hpp"

AdventDay01::AdventDay01() : AdventDay(1) {
	testStrings = {
		"1abc2",
		"pqr3stu8vwx",
		"a1b2c3d4e5f",
		"treb7uchet",
	};
	
	for (auto x: {nums, digits}) {
		numWords.insert(std::end(numWords), std::begin(x), std::end(x));
	}
	regexNumWords = std::regex(std::format("(?=({})).", join(numWords, '|')));
}




