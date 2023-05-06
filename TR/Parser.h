#pragma once

#include "Common.h"
#include <string>

namespace TR {
	class Parser {
	public:
		Command operator()(const std::string &in_str);
	};

} // namespace TR
