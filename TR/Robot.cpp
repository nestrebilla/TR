#include "Robot.h"

using namespace std;

namespace TR {
	void Robot::place(int x, int y, FaceDirection facedir) 
	{
		if (x < MIN_XLENGTH || x > MAX_XLENGTH || y < MIN_YLENGTH || y > MAX_YLENGTH) {
			throw invalid_argument("Invalid position");
		}

		_isPlaced = true;
		_pos.x = x;
		_pos.y = y;
		_faceDir = facedir;
	}

	void Robot::move() 
	{

		if (!_isPlaced) {
			return;
		}

		Position new_pos = _pos;

		switch (_faceDir) {
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

	void Robot::left() 
	{
		if (!_isPlaced) {
			return;
		}

		switch (_faceDir) {
		case FaceDirection::NORTH:
			_faceDir = FaceDirection::WEST;
			break;
		case FaceDirection::EAST:
			_faceDir = FaceDirection::NORTH;
			break;
		case FaceDirection::SOUTH:
			_faceDir = FaceDirection::EAST;
			break;
		case FaceDirection::WEST:
			_faceDir = FaceDirection::SOUTH;
			break;
		}
	}

	void Robot::right() 
	{
		if (!_isPlaced) {
			return;
		}
		switch (_faceDir) {
		case FaceDirection::NORTH:
			_faceDir = FaceDirection::EAST;
			break;
		case FaceDirection::EAST:
			_faceDir = FaceDirection::SOUTH;
			break;
		case FaceDirection::SOUTH:
			_faceDir = FaceDirection::WEST;
			break;
		case FaceDirection::WEST:
			_faceDir = FaceDirection::NORTH;
			break;
		}
	}

	void Robot::report() const {
		if (!_isPlaced) {
			return;
		}
		cout << "Output: " << _pos.x << "," << _pos.y << ",";
		switch (_faceDir) {
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

	void Robot::Execute(Command cmd) {
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

} // namespace TR