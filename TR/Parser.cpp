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

	Command Parser::createPlaceCommand(const vector<string> &input)
	{
		CommandType commandType = CommandType::PLACE;
		Position pos;
		FaceDirection faceDirection = FaceDirection::UNKNOWN;

		if (input.size() == 3)
		{
			// Detect empty position information input
			if (!input[0].empty() && !input[1].empty())
			{
				// Detect non-integer position 
				try
				{
					pos.x = stoi(input[0]);
					pos.y = stoi(input[1]);	
				}
				catch (const std::exception& e)
				{
					throw invalid_argument("Invalid non-integer position information provided");
				}

				// Detect invalid position
				if (pos.x < MIN_XLENGTH || pos.x > MAX_XLENGTH || pos.y < MIN_YLENGTH || pos.y > MAX_YLENGTH) {
					throw invalid_argument("Invalid position");
				}
				
			}
			else
			{
				throw invalid_argument("Empty position information provided");
			}

			// Map Face Direction argument to corresponding FaceDirection enum
			faceDirection = mapFaceDirection(input[2]);

			//Detect invalid Face Direction argument
			if (faceDirection == FaceDirection::UNKNOWN)
			{
				throw invalid_argument("Invalid robot face direction");
			}

			return { commandType, pos, faceDirection };
		}
		else
		{
			// Detect invalid PLACE command arguments
			throw invalid_argument("Invalid PLACE command arguments");
		}
	}

	Command Parser::operator()(const string &input) 
	{
		CommandType commandType = CommandType::UNKNOWN;
		Position pos;
		FaceDirection faceDirection = FaceDirection::UNKNOWN;

		vector<string> inputTokens = tokenizeString(input, ' ');

		if (inputTokens.size() != 0)
		{
			switch (mapCommandType(inputTokens[0])) {
			case CommandType::PLACE:
				// Parse the PLACE command arguments
				return createPlaceCommand(tokenizeString(inputTokens[1], ','));
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
		}

		return { commandType, pos, faceDirection };
	}

} // namespace TR
