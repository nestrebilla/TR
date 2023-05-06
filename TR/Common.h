#pragma once

namespace TR {
	const int MAX_XLENGTH = 4;
	const int MIN_XLENGTH = 0;
	const int MAX_YLENGTH = 4;
	const int MIN_YLENGTH = 0;
	const int UNKNOWN = -1;

	enum class FaceDirection { UNKNOWN, NORTH, EAST, SOUTH, WEST };

	struct Position {
		int x = UNKNOWN;
		int y = UNKNOWN;
	};

	enum class CommandType { PLACE, MOVE, LEFT, RIGHT, REPORT };

	struct Command {
		CommandType type;
		Position pos;
		FaceDirection dir;
	};

} // namespace TR