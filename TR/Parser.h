#pragma once

#include "Common.h"
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace TR {
	class Parser {

	private:
		vector<string> tokenizeString(const string &input, char delimiter);

	public:
		Command operator()(const string &input);
	};

} // namespace TR
