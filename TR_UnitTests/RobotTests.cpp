#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TR/Robot.h"
#include "../TR/Robot.cpp"
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
		}
	}
}

namespace TR_UnitTests
{		
	TEST_CLASS(RobotTests)
	{
	public:
		
		TEST_METHOD(Should_Test_Placing_Robot_In_Valid_Position1)
		{
			// Setup
			Position pos;
			pos.x = 0;
			pos.y = 0;
			Command command = { CommandType::PLACE, pos, FaceDirection::NORTH };

			// Define and run SUT
			Robot sut;
			sut.Execute(command);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x);
			Assert::AreEqual(sut.getPosition().y, pos.y);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::NORTH);
			Assert::AreEqual(sut.isPlaced(), true);

		}

		TEST_METHOD(Should_Test_Placing_Robot_In_Valid_Position2)
		{
			// Setup
			Position pos;
			pos.x = 3;
			pos.y = 4;
			Command command = { CommandType::PLACE, pos, FaceDirection::WEST };

			// Define and run SUT
			Robot sut;
			sut.Execute(command);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x);
			Assert::AreEqual(sut.getPosition().y, pos.y);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::WEST);
			Assert::AreEqual(sut.isPlaced(), true);

		}

		TEST_METHOD(Should_Test_Placing_Robot_In_Invalid_Position1)
		{
			// Setup
			Position pos;
			pos.x = -1;
			pos.y = -1;
			Command command = { CommandType::PLACE, pos, FaceDirection::SOUTH };

			try
			{	
				// Define and run SUT
				Robot sut;
				sut.Execute(command);
			}
			catch (const std::exception& e) 
			{
				// Assert
				Assert::AreEqual(string("Invalid position"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Placing_Robot_In_Invalid_Position2)
		{
			// Setup
			Position pos;
			pos.x = 5;
			pos.y = 3;
			Command command = { CommandType::PLACE, pos, FaceDirection::EAST };

			try
			{
				// Define and run SUT
				Robot sut;
				sut.Execute(command);
			}
			catch (const std::exception& e)
			{
				// Assert
				Assert::AreEqual(string("Invalid position"), string(e.what()));
				return;
			}

			Assert::Fail();
		}

		TEST_METHOD(Should_Test_Moving_Robot_To_Valid_Position1)
		{
			// Setup
			Position pos;
			pos.x = 0;
			pos.y = 0;
			Command command1 = { CommandType::PLACE, pos, FaceDirection::NORTH };
			Command command2 = { CommandType::MOVE, pos, FaceDirection::NORTH };

			// Define and run SUT
			Robot sut;
			sut.Execute(command1);
			sut.Execute(command2);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x);
			Assert::AreEqual(sut.getPosition().y, pos.y + 1);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::NORTH);
			Assert::AreEqual(sut.isPlaced(), true);
		}

		TEST_METHOD(Should_Test_Moving_Robot_To_Valid_Position2)
		{
			// Setup
			Position pos;
			pos.x = 0;
			pos.y = 0;
			Command command1 = { CommandType::PLACE, pos, FaceDirection::NORTH };
			Command command2 = { CommandType::MOVE, pos, FaceDirection::UNKNOWN };
			Command command3 = { CommandType::RIGHT, pos, FaceDirection::UNKNOWN };
			Command command4 = { CommandType::MOVE, pos, FaceDirection::UNKNOWN };

			// Define and run SUT
			Robot sut;
			sut.Execute(command1);
			sut.Execute(command2);
			sut.Execute(command3);
			sut.Execute(command4);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x + 1);
			Assert::AreEqual(sut.getPosition().y, pos.y + 1);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::EAST);
			Assert::AreEqual(sut.isPlaced(), true);
		}

		TEST_METHOD(Should_Test_Moving_Robot_To_Invalid_Position1)
		{
			// Setup
			Position pos;
			pos.x = 0;
			pos.y = 0;
			Command command1 = { CommandType::PLACE, pos, FaceDirection::SOUTH };
			Command command2 = { CommandType::MOVE, pos, FaceDirection::UNKNOWN };;

			// Define and run SUT
			Robot sut;
			sut.Execute(command1);
			sut.Execute(command2);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x);
			Assert::AreEqual(sut.getPosition().y, pos.y);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::SOUTH);
			Assert::AreEqual(sut.isPlaced(), true);
		}

		TEST_METHOD(Should_Test_Turning_Robot_Face_Direction_Left1)
		{
			// Setup
			Position pos;
			pos.x = 3;
			pos.y = 2;
			Command command1 = { CommandType::PLACE, pos, FaceDirection::SOUTH };
			Command command2 = { CommandType::LEFT, pos, FaceDirection::UNKNOWN };;

			// Define and run SUT
			Robot sut;
			sut.Execute(command1);
			sut.Execute(command2);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x);
			Assert::AreEqual(sut.getPosition().y, pos.y);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::EAST);
			Assert::AreEqual(sut.isPlaced(), true);
		}

		TEST_METHOD(Should_Test_Turning_Robot_Face_Direction_Left2)
		{
			// Setup
			Position pos;
			pos.x = 3;
			pos.y = 2;
			Command command1 = { CommandType::PLACE, pos, FaceDirection::EAST };
			Command command2 = { CommandType::LEFT, pos, FaceDirection::UNKNOWN };

			// Define and run SUT
			Robot sut;
			sut.Execute(command1);
			sut.Execute(command2);

			// Assert
			Assert::AreEqual(sut.getPosition().x, pos.x);
			Assert::AreEqual(sut.getPosition().y, pos.y);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::NORTH);
			Assert::AreEqual(sut.isPlaced(), true);
		}
	};
}