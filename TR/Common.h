#pragma once

namespace TR {
	const int MAX_XLENGTH = 4;
	const int MIN_XLENGTH = 0;
	const int MAX_YLENGTH = 4;
	const int MIN_YLENGTH = 0;

	enum class FaceDirection { UNKNOWN, NORTH, EAST, SOUTH, WEST };

	struct Position {
		int x;
		int y;
	};

	enum class Commands { PLACE, MOVE, LEFT, RIGHT, REPORT };

	struct Command {
		Commands command;
		Position pos;
		FaceDirection facedir;
	};

} // namespace TR