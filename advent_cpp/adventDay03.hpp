//
//  adventDay03.hpp
//  advent_cpp
//
//  Created by Michael Keilman on 5/17/24.
//

#ifndef adventDay03_hpp
#define adventDay03_hpp

#include <cctype>
#include <map>
#include <stdio.h>
#include "adventDay.hpp"
#include "utils.hpp"

class Grid {
	
	protected:
		std::map<std::string, std::vector<int>> gears;
		std::vector<std::string> schematic;
		unsigned long size[2];
	
		std::vector<std::string> _parts(std::string str) {
			std::vector<std::string> pp;
			std::vector<std::vector<std::string>> v = findAll(str, std::regex(R"***(\D*(\d+)\D*)***"));
			//std::cout << "PARTS STR " << str << " N P" << v.size() << '\n';
			for (std::vector<std::string> vs: v) {
				//printStrings(vs);
				//std::cout << vs[0] << " ";
				pp.push_back(vs[0]);
			}
			//std::cout << '\n';
			return pp.size() ? pp : std::vector<std::string>();
		}
	
		std::vector<std::vector<unsigned long>> _neighborhood(std::string str, unsigned long posx, unsigned long posy) {
			std::vector<unsigned long> rx;
			std::vector<unsigned long> ry;
			long j = (long)posx;
			long jmax = j + str.size() + 1;
			long k = (long)posy;
			long kmax = k + 2;
			
			for (long i = j - 1; i < jmax; ++i) {
				if (i >= 0  && i < size[0]) {
					rx.push_back(i);
				}
			}
			for (long i = k - 1; i < kmax; ++i) {
				if (i >= 0 && i < size[1]) {
					ry.push_back(i);
				}
			}
			return {rx, ry};
		}
	
		long _is_part(std::string str, unsigned long posx, unsigned long posy) {
			auto n = _neighborhood(str, posx, posy);
			for (unsigned long r: n[1]) {
				for (unsigned long c: n[0]) {
					char s = schematic[r][c];
					if (! std::regex_match(std::string({s}), std::regex(R"***([.0-9])***"))) {
						return s == '*' ? (r * size[1] + c) : -1;
					}
				}
			}
			return -2;
		}
	
		std::map<std::string, std::vector<int>> _gears() {
			std::map<std::string, std::vector<int>> gears = {};
			for (unsigned long i = 0; i < schematic.size(); ++i) {
				std::string l = trim(schematic[i]);
				unsigned long l_idx = 0;
				for (std::string p: _parts(l)) {
					unsigned long c = std::string{l}.find(p, l_idx);
					long t = _is_part(p, c, i);
					if (t > -1) {
						std::string g = std::to_string(t);
						gears[g].push_back(std::stoi(p));
					}
					// in case of duplicate numbers on one line
					l_idx = c + p.size();
				}
			}
			return gears;
		}

		int _gears_sum() {
			int n = 0;
			for (int i = 0; i < schematic.size(); ++i) {
				std::string l = trim(schematic[i]);
				unsigned long l_idx = 0;
				std::vector<std::string> pp = _parts(l);
				for (std::string p: _parts(l)) {
					unsigned long c = std::string{l}.find(p, l_idx);
					long ip = _is_part(p, c, i);
					n += (ip > -2 ? std::stoi(p) : 0);
					l_idx = c + p.size();
				}
			}
			return n;
		}
		
		int _gear_ratio_sum() {
			int n = 0;
			std::map<std::string, std::vector<int>> gg = gears;
			for (auto &[k, v]: gg) {
				if (v.size() != 2) {
					continue;
				}
				n += (v[0] * v[1]);
			}
			return n;
		}
	
	public:
		int gears_sum;
		int gear_ratio_sum;
	
		Grid(std::vector<std::string> schematic) {
			this->schematic = schematic;
			this->size[0] = schematic.size();
			this->size[1] = trim(schematic[0]).size();
			this->gears = _gears();
			this->gears_sum = _gears_sum();
			this->gear_ratio_sum = _gear_ratio_sum();
		}
};

class AdventDay03 : public AdventDay {
	
	public:
		AdventDay03();
	
		void run(std::vector<std::string> v) {
			Grid g(v);
			std::cout << "SUM " << g.gears_sum << "\n";
			std::cout << "GEARS " << g.gear_ratio_sum << "\n";
		};
};

#endif /* adventDay03_hpp */
