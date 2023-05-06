#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Parser.h"
#include "Robot.h"

using namespace std;

namespace TR {
	void Robot::place(int x, int y, FaceDirection facedir) {
		if (x < MIN_XLENGTH || x > MAX_XLENGTH || y < MIN_YLENGTH || y > MAX_YLENGTH) {
			throw std::invalid_argument("Invalid position");
		}
		_placed = true;
		_pos.x = x;
		_pos.y = y;
		_facedir = facedir;
	}

	void Robot::move() {
		if (!_placed) {
			return;
		}
		Position new_pos = _pos;
		switch (_facedir) {
		case FaceDirection::NORTH:
			new_pos.y++;
			break;
		case FaceDirection::EAST:
			new_pos.x++;
			break;
		case FaceDirection::SOUTH:
			new_pos.y--;
			break;
		case FaceDirection::WEST:
			new_pos.x--;
			break;
		}
		if (new_pos.x < MIN_XLENGTH || new_pos.x > MAX_XLENGTH || new_pos.y < MIN_YLENGTH ||
			new_pos.y > MAX_YLENGTH) {
			return;
		}
		_pos = new_pos;
	}

	void Robot::left() {
		if (!_placed) {
			return;
		}
		switch (_facedir) {
		case FaceDirection::NORTH:
			_facedir = FaceDirection::WEST;
			break;
		case FaceDirection::EAST:
			_facedir = FaceDirection::NORTH;
			break;
		case FaceDirection::SOUTH:
			_facedir = FaceDirection::EAST;
			break;
		case FaceDirection::WEST:
			_facedir = FaceDirection::SOUTH;
			break;
		}
	}

	void Robot::right() {
		if (!_placed) {
			return;
		}
		switch (_facedir) {
		case FaceDirection::NORTH:
			_facedir = FaceDirection::EAST;
			break;
		case FaceDirection::EAST:
			_facedir = FaceDirection::SOUTH;
			break;
		case FaceDirection::SOUTH:
			_facedir = FaceDirection::WEST;
			break;
		case FaceDirection::WEST:
			_facedir = FaceDirection::NORTH;
			break;
		}
	}

	void Robot::report() const {
		if (!_placed) {
			return;
		}
		cout << "Output: " << _pos.x << "," << _pos.y << ",";
		switch (_facedir) {
		case FaceDirection::NORTH:
			cout << "NORTH";
			break;
		case FaceDirection::EAST:
			cout << "EAST";
			break;
		case FaceDirection::SOUTH:
			cout << "SOUTH";
			break;
		case FaceDirection::WEST:
			cout << "WEST";
			break;
		}
		cout << endl;
	}

	void Robot::execute(Command cmd) {
		if (cmd.type == CommandType::PLACE) {
			place(cmd.pos.x, cmd.pos.y, cmd.dir);
		}
		else if (cmd.type == CommandType::MOVE) {
			move();
		}
		else if (cmd.type == CommandType::LEFT) {
			left();
		}
		else if (cmd.type == CommandType::RIGHT) {
			right();
		}
		else if (cmd.type == CommandType::REPORT) {
			report();
		}
	}

} // namespace ToyRobot