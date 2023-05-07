#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TR/Parser.h"
#include "../TR/Parser.cpp"
#include "../TR/Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TR;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<>
			static std::wstring ToString<FaceDirection>(const FaceDirection& f) {
				return L"FaceDirection";
			}

			template<>
			static std::wstring ToString<CommandType>(const CommandType& f) {
				return L"CommandType";
			}
		}
	}
}

namespace TR_UnitTests
{
	TEST_CLASS(ParserTests)
	{
	public:

		TEST_METHOD(Should_Test_Placing_Robot_In_Valid_Position1)
		{
			// Setup
			string line = "PLACE 0,0,NORTH";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::PLACE);
			Assert::AreEqual(command.pos.x, 0);
			Assert::AreEqual(command.pos.y, 0);
			Assert::AreEqual(command.dir, FaceDirection::NORTH);

		}

		TEST_METHOD(Should_Test_Placing_Robot_In_Valid_Position2)
		{
			// Setup
			string line = "PLACE 2,4,EAST";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::PLACE);
			Assert::AreEqual(command.pos.x, 2);
			Assert::AreEqual(command.pos.y, 4);
			Assert::AreEqual(command.dir, FaceDirection::EAST);

		}

		TEST_METHOD(Should_Test_Placing_Robot_In_Invalid_Position1)
		{
			// Setup
			string line = "PLACE 5,5,WEST";	

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::PLACE);
			Assert::AreEqual(command.pos.x, 5);
			Assert::AreEqual(command.pos.y, 5);
			Assert::AreEqual(command.dir, FaceDirection::WEST);
		}

		TEST_METHOD(Should_Test_Placing_Robot_In_Invalid_Position2)
		{
			// Setup
			string line = "PLACE -5,-1,SOUTH";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::PLACE);
			Assert::AreEqual(command.pos.x, -5);
			Assert::AreEqual(command.pos.y, -1);
			Assert::AreEqual(command.dir, FaceDirection::SOUTH);
		}

	};
}