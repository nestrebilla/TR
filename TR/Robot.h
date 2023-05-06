#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Common.h"
#include "Parser.h"

namespace TR {
	class Robot {

	private:
		Position _pos;
		FaceDirection _faceDir;
		bool _isPlaced;

		void place(int x, int y, FaceDirection dir);
		void move();
		void left();
		void right();
		void report() const;

	public:
		Robot() : _isPlaced(false) {}
		Position getPosition() { return _pos; }
		FaceDirection getFaceDirection() { return _faceDir; }
		bool isPlaced() { return _isPlaced;  }

		void Execute(Command cmd);
	};

} // namespace TR
