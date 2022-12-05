/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
 
class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test)
{
    ASSERT_TRUE(true);
}





TEST(tappityTest, Length_Difference_Test_Same_Word){ // Pass
	tappity obj("Hello");
	obj.entry("Hello");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Length_Difference_Test_Small_vs_Large_Word){ // Fail
	tappity obj("Hlo");
	obj.entry("Hello");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Length_Difference_Testing_Capitalization){ // pass
	tappity obj("Hello Bob!");
	obj.entry("Hello bob!");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Length_Difference_Test_Same_Text_Different_Spacing){ // Fail
	tappity obj("Hello Dale");
	obj.entry("HelloDale");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Length_Difference_Test_Spacing_Majorly_Different){ // Fail
	tappity obj("Hello               Dale");
	obj.entry("Hello Dale");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Length_Difference_Test_Spacing_Slightly_Different){ // Fail
	tappity obj(" ");
	obj.entry("");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Length_Difference_Test_No_Text_Same_Spacing){ // Pass
	tappity obj(" ");
	obj.entry(" ");
	int result = obj.length_difference();
	ASSERT_EQ(result, 0);
}






TEST(tappityTest, Accuracy_Both_Same_Testing_Correct_Percent) // Pass
{
	tappity obj("testing");
	obj.entry("testing");
	int result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

TEST(tappityTest, Accuracy_Both_Same_Testing_Wrong_Percent) // Fail
{
	tappity obj("testing");
	obj.entry("testing");
	int result = obj.accuracy();
	ASSERT_EQ(result, 80);
}

TEST(tappityTest, Accuracy_Different_Testing_Wrong_Percent) // Fail
{
	tappity obj("hello");
	obj.entry("there");
	int result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

TEST(tappityTest, Accuracy_Different_Testing_Correct_Percent) // Pass
{
	tappity obj("helloooooo");
	obj.entry("hellooooox");
	int result = obj.accuracy();
	ASSERT_EQ(result, 90);
}

TEST(tappityTest, Accuracy_Different_Testing_Nothing_Against_Something) // Pass
{
	tappity obj("howdy");
	obj.entry("");
	int result = obj.accuracy();
	ASSERT_EQ(result, 0);
}

TEST(tappityTest, Accuracy_Different_Testing_Slightly_Different_Wrong_Percent) // Fail
{
	tappity obj("wassaaaap");
	obj.entry("wassaap");
	int result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

TEST(tappityTest, Accuracy_Different_Testing_Slightly_Different_Correct_Percent) // Pass
{
	tappity obj("wassaaaap");
	obj.entry("wassaap");
	int result = obj.accuracy();
	ASSERT_EQ(result, 66);
}

TEST(tappityTest, Accuracy_Testing_Same_Numbers) // Pass
{
	tappity obj("132");
	obj.entry("132");
	int result = obj.accuracy();
	ASSERT_EQ(result, 100);
}

TEST(tappityTest, Accuracy_Testing_Different_Numbers) // Fail
{
	tappity obj("123");
	obj.entry("132");
	int result = obj.accuracy();
	ASSERT_EQ(result, 100);
}