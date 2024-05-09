//
//  adventDay.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 4/30/24.
//

#ifndef adventDay_hpp
#define adventDay_hpp

#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "utils.hpp"


class AdventDay {
	
	protected:
		std::string inputFile;
	
		void printStrings(std::vector<std::string> v) {
			std::cout << "[" << join(v) << "]\n";
		}
	
	public:
		AdventDay(int day);
	
		virtual void run(std::vector<std::string> v) {
			printStrings(v);
		}
	
		void runFromTestStrings() {
			run(testStrings);
		}
	
		void runFromFile() {
			std::vector<std::string> lines;
			std::ifstream f(inputFile);
			for (std::string line; std::getline(f, line);) {
				lines.push_back(line);
			}
			run(lines);
		};
	
		std::vector<std::string> testStrings;
};

#endif /* adventDay_hpp */
