#include "dss.hpp"
#include "gtest/gtest.h"
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;
using namespace dss;

class SurveyTest : testing::test
{
	protected:
		IDNumber surveyID = "7";
		unsigned expQuestionCount = 11;
		unsigned expRuleCount = 3;

	//virtual void setup() {}

	//virtual void teardown() {}
	
	void nullTest(Survey& _s)
	{
		using ::testing::Ne;
		ASSERT_THAT(_s.Id, Ne(NULL)); 
		ASSERT_THAT(_s.Questions, Ne(NULL)); 
		ASSERT_THAT(_s.Rules, Ne(NULL)); 
	}

	void expectedValuesTest(Survey& _s)
	{
		using ::testing::Eq;
		EXPECT_THAT(_s.Id, Eq(surveyID));
		EXPECT_THAT(_s.Questions().size(), Eq(expQuestionCount));
		EXPECT_THAT(_s.Rules.size(), Eq(expRuleCount));
	}
}

TEST_F(SurveyTest, constructorTest) {
	Survey _s(surveyID);
	nullTest(_s);
	expectedValuesTest(_s);
}

TEST_F(SurveyTest, loadFromIdTest) {
	Survey _s;
	_s.loadFromId(surveyID);
	nullTest(_s);
	expectedValuesTest(_s);
}

TEST_F(SurveyTest, reloadTest) {
	Survey _s(surveyID);
	_s.reload();
	nullTest(_s);
	expectedValuesTest(_s);
}
