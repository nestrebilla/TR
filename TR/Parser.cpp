#include "Parser.h"

using namespace std;


namespace TR {

	vector<string> Parser::tokenizeString(const std::string &input, char delimiter)
	{
		vector<string> tokens;
		stringstream ss(input);
		std::string token;

		while (getline(ss, token, delimiter)) {
			tokens.push_back(token);
		}

		return tokens;
	}

	Command Parser::operator()(const string &input) 
	{
		CommandType command;
		Position pos;
		FaceDirection facedirection = FaceDirection::NORTH;

		vector<string> inputTokens = tokenizeString(input, ' ');
		string cmd = inputTokens[0];

		if (cmd == "PLACE") {
			command = CommandType::PLACE;

			// Parse the PLACE command arguments
			vector<string> placeAndDirectionInfo = tokenizeString(inputTokens[1], ',');
			pos.x = stoi(placeAndDirectionInfo[0]);
			pos.y = stoi(placeAndDirectionInfo[1]);
			string dir_str = placeAndDirectionInfo[2];

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
