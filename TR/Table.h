#pragma once

#include "Common.h"
#include "Robot.h"


namespace TR {

	class Table
	{
	private:
		int _xlength = UNKNOWN;
		int _ylength = UNKNOWN;
		Robot _robot;

	public:
		Table();
		~Table();

		void SetDimensions(int, int);

	};

} // namespace TR