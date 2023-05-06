#pragma once

#include "Common.h"

namespace TR {
	class Robot {

	private:
		Position _pos;
		FaceDirection _facedir;
		bool _placed;

	public:
		Robot() : _placed(false) {}

		void place(int x, int y, FaceDirection dir);
		void move();
		void left();
		void right();
		void report() const;
		void execute(Command cmd);
	};

} // namespace TR
