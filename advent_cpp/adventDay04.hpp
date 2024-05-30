//
//  adventDay04.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/29/24.
//

#ifndef adventDay04_hpp
#define adventDay04_hpp

#include <cmath>
#include <map>
#include <ranges>
#include <regex>
#include <span>
#include <stdio.h>
#include <tuple>
#include "adventDay.hpp"

class Deck {
	
	protected:
		std::vector<std::string> cards;
		std::map<std::string, int> copies;
	
		static std::tuple<std::string, int> _card_numbers(std::string card) {
			std::string cid = findAll(card, std::regex(R"***(Card\s*(\d+):)***"))[0][0];
			std::vector<std::string> nums = reSplit(std::regex(R"***(\|)***"), card);
			std::regex regexCardNums(R"***(\D*(\d+)\D*)***");
			std::vector<std::vector<std::string>> w = findAll(nums[0], regexCardNums);
			std::vector<std::string> winners;
			std::for_each(
				w.cbegin() + 1,
				w.cend(),
				[&winners](std::vector<std::string> v) { winners.push_back(v[0]); }
			);
			std::vector<std::string> draws;
			for (std::vector<std::string> v: findAll(nums[1], regexCardNums)) {
				draws.push_back(v[0]);
			}
			int n = 0;
			for (std::string c: draws) {
				if (std::find(winners.cbegin(), winners.cend(), c) != winners.cend()) {
					++n;
				}
			}
			return std::tuple(cid, n);
		}
	
	
		std::map<std::string, int> _card_copies() {
			int lc = cards.size();
			std::vector<int> r = range(0, lc);
			std::map<std::string, int> copies;
			for (int i: r) {
				copies[std::format("{}", i + 1)] = 1;
			}
			for (int i: r) {
				auto [cid, num_winners] = _card_numbers(this->cards[i]);
				for (int j: range(i + 1, std::min(i + 1 + num_winners, lc))) {
					copies[std::get<0>(_card_numbers(cards[j]))] += copies[cid];
				}
			}
			return copies;
		}
		
		int _cards_sum() {
			int n = 0;
			for (std::string c: this->cards) {
				auto [cid, num_winners] = _card_numbers(c);
				n += num_winners ? std::pow(2, num_winners - 1) : 0;
			}
			return n;
		}
		
		int _copies_sum() {
			auto vals = std::views::values(this->copies);
			return std::reduce(vals.begin(), vals.end());
		}
		
		
		public:
			int c_sum;
			int sum;
				
			Deck(std::vector<std::string> cards) {
				this->cards = cards;
				this->copies = _card_copies();
				this->c_sum = _copies_sum();
				this->sum = _cards_sum();
			};
};

class AdventDay04 : public AdventDay {
	
	public:
		AdventDay04();
	
		void run(std::vector<std::string> v) {
			Deck deck(v);
			std::cout << "SUM " <<  deck.sum << '\n';
			std::cout << "COPIES SUM " << deck.c_sum << '\n';
		};
};

#endif /* adventDay04_hpp */
