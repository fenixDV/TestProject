#include "pch.h"
#include "Calculations.h"
#include "CalculationsTest.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CalculationsTests, Add) {
	Calculations calc;
	int result = calc.add(1, 3);
	EXPECT_EQ(result, 4);
}

TEST(CalculationsTests, AddNoThrow)
{
	EXPECT_NO_THROW({
	Calculations calc;
	int result = calc.add(1, 3);
	});
}

TEST(CalculationsTests, CompareThrowIfNegative)
{
	EXPECT_ANY_THROW({
	Calculations calc;
	int result = calc.compareGreater(-1, 3);
	});
}

TEST_F(CalculationsTest, SizeIsThree)
{
	auto vect1 = calc1.getVect();
	auto vect2 = calc2.getVect();
	auto vect3 = calc3.getVect();

	EXPECT_EQ(vect1.size(), 3);
	EXPECT_EQ(vect2.size(), 3);
	EXPECT_EQ(vect3.size(), 3);
}

TEST_F(CalculationsTest, Vector1ElementsEqual)
{
	auto vect1 = calc1.getVect();

	ASSERT_FALSE(vect1.empty());
	EXPECT_EQ(vect1.at(0), 1.890);
	EXPECT_EQ(vect1.at(1), 2);
	EXPECT_EQ(vect1.at(2), 0.39);
}

TEST_F(CalculationsTest, SortVectorAscending)
{
	auto vect1 = calc1.getVect();
	calc1.sortVectorAscending(vect1);

	EXPECT_LT(vect1[0], vect1[1]);
}

TEST_F(CalculationsTest, SortVectorDescending)
{
	auto vect2 = calc2.getVect();
	calc2.sortVectorDescending(vect2);

	EXPECT_GT(vect2[0], vect2[1]);
}

TEST_F(CalculationsTest, AllOfElementsAreNotEven)
{
	auto vectOfInts = std::vector<int> {4, 6, 7, 8, 16};
	bool result = calc3.allOfAreEven(vectOfInts);

	EXPECT_FALSE(result);
}

TEST_F(CalculationsTest, AnyOfElementsAreEven)
{
	auto vectOfInts = std::vector<int> {4, 6, 7, 8, 16};
	bool result = calc3.anyOfAreEven(vectOfInts);

	EXPECT_TRUE(result);
}

TEST(TestNewFeaturesFromCpp20, MapContainsKeyAndGetValue)
{
	std::map<int, std::string> m {
		{1, "apple"},
		{5, "banana"},
		{24, "orange"}};
	std::string value;
	Calculations calc;
	bool result = calc.checkIfContainsKeyAndGetValue(m, 24, value);

	ASSERT_TRUE(result);
	ASSERT_EQ(value, "orange");
}

TEST(TestNewFeaturesFromCpp20, MapDoesNotContainKeyAndGetValue)
{
	std::map<int, std::string> m {
		{1, "apple"},
		{5, "banana"},
		{24, "orange"}};
	std::string value;
	Calculations calc;
	bool result = calc.checkIfContainsKeyAndGetValue(m, 11, value);

	ASSERT_FALSE(result);
	ASSERT_EQ(value, "not found");
}

TEST(TestNewFeaturesFromCpp20, FindsElementsThatDiffer)
{
	std::string str1 = "anapacar";
	std::string str2 = "anapucar";
	Calculations calc;

	auto resultVect = calc.findPlaceWhereElementsDiffer(str1, str2);

	EXPECT_NE(resultVect.at(0), resultVect.at(1));
}

TEST(TestNewFeaturesFromCpp20, DoNotFindElementsThatDiffer)
{
	std::string str1 = "anapacar";
	std::string str2 = "anapacar";
	Calculations calc;

	auto resultVect = calc.findPlaceWhereElementsDiffer(str1, str2);

	EXPECT_TRUE(resultVect.empty());
}