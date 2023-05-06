#pragma once

#include "Common.h"
#include "Robot.h"

#define UNKNOWN_LENGTH -1

namespace TR {

	class Table
	{
	private:
		int _xlength = UNKNOWN_LENGTH;
		int _ylength = UNKNOWN_LENGTH;
		Robot _robot;

	public:
		Table();
		~Table();

		void SetDimensions(int, int);

	};

} // namespace TR