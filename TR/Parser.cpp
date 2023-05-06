#include <stdexcept>
#include <string>
#include "Parser.h"
#include "Common.h"

using namespace std;


namespace TR {
	Command Parser::operator()(const string &in_str) {
		CommandType command;
		Position pos;
		FaceDirection facedirection = FaceDirection::NORTH;

		string cmd = in_str.substr(0, in_str.find(' '));
		if (cmd == "PLACE") {
			command = CommandType::PLACE;
			// Parse the PLACE command arguments
			pos.x = stoi(in_str.substr(in_str.find(' ') + 1,
				in_str.rfind(',') - in_str.find(',') - 1));
			pos.y = std::stoi(in_str.substr(in_str.find(',') + 1,
				in_str.rfind(',') - in_str.find(',') - 1));
			string dir_str = in_str.substr(in_str.rfind(',') + 1);
			if (dir_str == "NORTH") {
				facedirection = FaceDirection::NORTH;
			}
			else if (dir_str == "EAST") {
				facedirection = FaceDirection::EAST;
			}
			else if (dir_str == "SOUTH") {
				facedirection = FaceDirection::SOUTH;
			}
			else if (dir_str == "WEST") {
				facedirection = FaceDirection::WEST;
			}
			else {
				throw std::invalid_argument("Invalid direction");
			}
		}
		else if (cmd == "MOVE") {
			command = CommandType::MOVE;
		}
		else if (cmd == "LEFT") {
			command = CommandType::LEFT;
		}
		else if (cmd == "RIGHT") {
			command = CommandType::RIGHT;
		}
		else if (cmd == "REPORT") {
			command = CommandType::REPORT;
		}
		else {
			throw invalid_argument("Invalid command");
		}

		return { command, pos, facedirection };
	}
} // namespace TR
