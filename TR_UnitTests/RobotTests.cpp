#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TR/Robot.h"
#include "../TR/Common.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TR;

namespace TR_UnitTests
{		
	TEST_CLASS(RobotTests)
	{
	public:
		
		TEST_METHOD(Should_Test_Valid_Initial_Position1)
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
			/*Assert::AreEqual(pos, sut.getPosition());
			Assert::AreEqual(FaceDirection::NORTH, sut.getFaceDirection());
			Assert::AreEqual(true, sut.isPlaced());*/
			Assert::AreEqual(sut.getPosition(), pos);
			Assert::AreEqual(sut.getFaceDirection(), FaceDirection::NORTH);
			Assert::AreEqual(sut.isPlaced(), true);

		}

	};
}