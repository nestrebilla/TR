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

		TEST_METHOD(Should_Test_Parser_Parsing_Empty_Input)
		{
			// Setup
			string line = "";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::UNKNOWN);
			Assert::AreEqual(command.pos.x, UNKNOWN_POSITION);
			Assert::AreEqual(command.pos.y, UNKNOWN_POSITION);
			Assert::AreEqual(command.dir, FaceDirection::UNKNOWN);

		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Valid_Position_And_Face_Direction1)
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

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Valid_Position_And_Face_Direction2)
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

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Invalid_Position1)
		{
			// Setup
			string line = "PLACE 5,5,WEST";	

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid position"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Invalid_Position2)
		{
			// Setup
			string line = "PLACE -5,-1,SOUTH";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid position"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Invalid_Position_And_Face_Direction)
		{
			// Setup
			string line = "PLACE -5,-1,jhdapopdsa";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid position"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_No_Face_Direction)
		{
			// Setup
			string line = "PLACE -5,-1";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid PLACE command arguments"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Empty_Position1)
		{
			// Setup
			string line = "PLACE ,,NORTH";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Empty position information provided"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Empty_Position2)
		{
			// Setup
			string line = "PLACE ,0,NORTH";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Empty position information provided"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Empty_Position3)
		{
			// Setup
			string line = "PLACE 0,,NORTH";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Empty position information provided"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Empty_FaceDirection)
		{
			// Setup
			string line = "PLACE 0,0,";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid PLACE command arguments"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Non_Integer_Position1)
		{
			// Setup
			string line = "PLACE @,^,NORTH";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid non-integer position information provided"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Place_Command_With_Non_Integer_Position2)
		{
			// Setup
			string line = "PLACE a,z,NORTH";

			try
			{
				// Define and run SUT
				Parser sut;
				Command command = sut(line);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid non-integer position information provided"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Parser_Parsing_Move_Command)
		{
			// Setup
			string line = "MOVE";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::MOVE);
			Assert::AreEqual(command.pos.x, UNKNOWN_POSITION);
			Assert::AreEqual(command.pos.y, UNKNOWN_POSITION);
			Assert::AreEqual(command.dir, FaceDirection::UNKNOWN);

		}

		TEST_METHOD(Should_Test_Parser_Parsing_Left_Command)
		{
			// Setup
			string line = "LEFT";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::LEFT);
			Assert::AreEqual(command.pos.x, UNKNOWN_POSITION);
			Assert::AreEqual(command.pos.y, UNKNOWN_POSITION);
			Assert::AreEqual(command.dir, FaceDirection::UNKNOWN);

		}

		TEST_METHOD(Should_Test_Parser_Parsing_Right_Command)
		{
			// Setup
			string line = "RIGHT";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::RIGHT);
			Assert::AreEqual(command.pos.x, UNKNOWN_POSITION);
			Assert::AreEqual(command.pos.y, UNKNOWN_POSITION);
			Assert::AreEqual(command.dir, FaceDirection::UNKNOWN);

		}

		TEST_METHOD(Should_Test_Parser_Parsing_Report_Command)
		{
			// Setup
			string line = "REPORT";

			// Define and run SUT
			Parser sut;
			Command command = sut(line);

			// Assert
			Assert::AreEqual(command.type, CommandType::REPORT);
			Assert::AreEqual(command.pos.x, UNKNOWN_POSITION);
			Assert::AreEqual(command.pos.y, UNKNOWN_POSITION);
			Assert::AreEqual(command.dir, FaceDirection::UNKNOWN);

		}
	};
}