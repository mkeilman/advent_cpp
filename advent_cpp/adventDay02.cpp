//
//  adventDay02.cpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/9/24.
//

#include "adventDay02.hpp"

AdventDay02::AdventDay02() : AdventDay(2) {
	testStrings = {
		"Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
		"Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
		"Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
		"Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
		"Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green",
	};
	auto k = std::views::keys(bag);
	colors = {k.begin(), k.end()};
	regexPull = std::regex(std::format(R"***((\d+)\s*({}),*\s*)***", join(colors, '|')));
	
	auto v = std::views::values(bag);
	nCubes = std::reduce(v.begin(), v.end());
}
