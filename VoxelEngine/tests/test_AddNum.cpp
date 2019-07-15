#include "gtest/gtest.h"
#include "AddNum.h"

namespace {

	TEST(AddNumTest, Negative) {
		EXPECT_EQ(0, add(-5, 5));
		EXPECT_EQ(-5, add(-3, -2));
		EXPECT_EQ(-1, add(-1, 0));
	}
	TEST(AddNumTest, Zero) {
		EXPECT_EQ(0, add(0, 0));
	}
	TEST(AddNumTest, Positive) {
		EXPECT_EQ(1, add(0, 1));
		EXPECT_EQ(0, add(-1, 1));
		EXPECT_EQ(5, add(3, 2));
	}

	int main(int argc, char** argv) {
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
}