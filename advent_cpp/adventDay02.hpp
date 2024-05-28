//
//  adventDay02.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/9/24.
//

#ifndef adventDay02_hpp
#define adventDay02_hpp

#include <algorithm>
#include <any>
#include <map>
#include <ranges>
#include <regex>
#include <stdio.h>
#include "adventDay.hpp"
#include "utils.hpp"

struct game_struct {
	int gid;
	std::map<std::string, std::vector<int>> colors;
};

static std::map<std::string, int> bag {
	{"blue", 14},
	{"green", 13},
	{"red", 12},
};
static std::regex re_id(R"***(Game\s*(\d+):)***");

class AdventDay02 : public AdventDay {
	protected:
		std::vector<std::string> colors;
		std::regex regexPull;
		int nCubes;

	game_struct toGame(std::string line) {
		std::smatch sm;
		std::regex_search(line, sm, re_id);
		//std::cout << line << sm[1].str();
		int gid = std::stoi(sm[1].str());
		game_struct g = {gid};
		std::vector<std::string> pulls = reSplit(
			std::regex(R"***(;\s*)***"),
			reSplit(std::regex(R"***(:\s*)***"), line)[1]
		);
		for (int i = 0; i < pulls.size(); ++i) {
			for (std::vector<std::string> v: findAll(pulls[i], regexPull)) {
				std::string c = v[1];
				int n = std::stoi(v[0]);
				if (! g.colors.count(c)) {
					g.colors[c] = std::vector<int>(pulls.size());
				}
				g.colors[c][i] = n;
			}
		}
		return g;
	}
	
	void printGame(game_struct g) {
		std::cout << "{\n\t";
		std::cout << std::format("gid: {:d}; colors: \n\t\t{{", g.gid);
		for (auto &[k, v]: g.colors) {
			std::cout << std::format("{}: ", k);
			std::cout << "[" << join(v) << "],";
		}
		std::cout << "\t}}";
		std::cout << "\n}\n";
	}

	int gameNum(game_struct game) {
		std::vector<std::vector<int>> counts;
		for (auto &[k, v]: game.colors) {
			counts.push_back(v);
			if (std::any_of(v.begin(), v.end(), [k](int x) { return x > bag[k]; })) {
				return 0;
			}
		}
		int nc = this->nCubes;
		std::vector<int> countSums(counts[0].size());
		for (int i = 0; i < counts.size(); ++i) {
			std::vector<int> c = counts[i];
			for (int j = 0; j < c.size(); ++j ) {
				countSums[j] +=  c[j];
			}
		}
		return std::any_of(
			countSums.begin(),
			countSums.end(),
			[nc](int s) {return s > nc; }
		) ? 0 : game.gid;
		
	}

	int gamePower(game_struct game) {
		int p = 1;
		for (auto &[k, v]: game.colors) {
			// max_element returns an iterator
			p *= *std::max_element(v.begin(), v.end());
		}
		return p;
	}

	int gamesPowerSum(std::vector<std::string> lines) {
		int n = 0;
		for (std::string line : lines) {
			n += gamePower(toGame(line));
		}
		return n;
	}

	
	int gamesSum(std::vector<std::string> lines) {
		int n = 0;
		for (std::string line : lines) {
			game_struct g = toGame(line);
			//printGame(g);
			//std::cout << std::format("GAME {:d}: {:d}", g.gid,  gameNum(g)) << "\n";
			n += gameNum(g);
		}
		return n;
	}
	
	public:
		AdventDay02();
	
		void run(std::vector<std::string> v) {
			std::cout << "SUM " << gamesSum(v) << "\n";
			std::cout << "POWERS " << gamesPowerSum(v) << "\n";
		};
};

#endif /* adventDay02_hpp */
