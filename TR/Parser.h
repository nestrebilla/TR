#pragma once

#include "Common.h"
#include <string>

namespace TR {
	class Parser {
	public:
		Command operator()(const std::string &input);
	};

} // namespace TR
