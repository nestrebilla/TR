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

	FaceDirection Parser::mapFaceDirection(const std::string &input)
	{
		if (input == "NORTH") {
			return FaceDirection::NORTH;
		}
		else if (input == "EAST") {
			return FaceDirection::EAST;
		}
		else if (input == "SOUTH") {
			return FaceDirection::SOUTH;
		}
		else if (input == "WEST") {
			return FaceDirection::WEST;
		}
		else {
			return FaceDirection::UNKNOWN;
		}
	}

	CommandType Parser::mapCommandType(const std::string &input)
	{
		if (input == "PLACE") {
			return CommandType::PLACE;
		}
		else if (input == "MOVE") {
			return CommandType::MOVE;
		}
		else if (input == "LEFT") {
			return CommandType::LEFT;
		}
		else if (input == "RIGHT") {
			return CommandType::RIGHT;
		}
		else if (input == "REPORT") {
			return CommandType::REPORT;
		}
		else {
			return CommandType::UNKNOWN;
		}
	}

	Command Parser::operator()(const string &input) 
	{
		CommandType commandType = CommandType::UNKNOWN;
		Position pos;
		FaceDirection faceDirection = FaceDirection::UNKNOWN;

		vector<string> inputTokens = tokenizeString(input, ' ');

		switch (mapCommandType(inputTokens[0])) {
			case CommandType::PLACE:
			{
				commandType = CommandType::PLACE;

				// Parse the PLACE command arguments
				vector<string> placeAndDirectionInfo = tokenizeString(inputTokens[1], ',');
				pos.x = stoi(placeAndDirectionInfo[0]);
				pos.y = stoi(placeAndDirectionInfo[1]);
				FaceDirection faceDir = mapFaceDirection(placeAndDirectionInfo[2]);

				// Detect invalid PLACE command arguments
				switch (faceDir) {
				case FaceDirection::UNKNOWN:
					throw std::invalid_argument("Invalid robot face direction");
					break;
				default:
					faceDirection = faceDir;
					break;
				}
			}
				break;
			case CommandType::MOVE:
				commandType = CommandType::MOVE;
				break;
			case CommandType::LEFT:
				commandType = CommandType::LEFT;
				break;
			case CommandType::RIGHT:
				commandType = CommandType::RIGHT;
				break;
			case CommandType::REPORT:
				commandType = CommandType::REPORT;
				break;
			default:
				throw invalid_argument("Invalid command");
				break;
		}

		return { commandType, pos, faceDirection };
	}

} // namespace TR
