//
//  main.cpp
//  advent_cpp
//
//  Created by Michael Keilman on 4/30/24.
//


#include "adventDay01.hpp"
#include "adventDay02.hpp"
#include "adventDay03.hpp"
#include "adventDay04.hpp"
#include <iostream>

void usage() {
	std::cout << "usage: adventDay <day number>\n";
}


int main(int argc, const char * argv[]) {
	/*
	if (argc != 2) {
		usage();
		exit(1);
	}
	 */
	
	// factory?
	//AdventDay *d = new AdventDay(std::stoi(argv[1]));
	//AdventDay01 *d = new AdventDay01();
	//AdventDay02 *d = new AdventDay02();
	//AdventDay03 *d = new AdventDay03();
	AdventDay04 *d = new AdventDay04();
	d->runFromTestStrings();
	d->runFromFile();
	
	return 0;
}
