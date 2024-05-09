//
//  adventDay.cpp
//  advent_cpp
//
//  Created by Michael Keilman on 4/30/24.
//

#include "adventDay.hpp"

AdventDay::AdventDay(int day) {
	inputFile = std::format("input_day_{:02d}.txt", day);
	
	
	if (! std::filesystem::exists(inputFile)) {
		throw std::runtime_error(std::format("File not found: {}", inputFile));
	}
}
