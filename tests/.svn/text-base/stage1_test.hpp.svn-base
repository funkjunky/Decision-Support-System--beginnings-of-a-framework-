#include "dss.hpp"
#include "gtest/gtest.h"

#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;
using namespace dss;
//most of the functions tested here are in the namespace dss::system
using namespace dss::surveysystem;

TEST(stage1, remarks) {
	cout << "** The following tests require the the private folder remains unchanged. **" << endl;
}

TEST(stage1, surveyExists) {
	EXPECT_FALSE(surveyExists("99")) << "survey id=99 should not exist.";
	EXPECT_TRUE(surveyExists("1")) << "survey id=1 should exist.";
}

TEST(stage1, allSurveyIDs) {
	EXPECT_EQ(3, allSurveyIDs().size()) << "their should be 3 surveys.";
}

TEST(stage1, getResponseFiles) {
	string expected = "1.xml 2.xml 3.xml 4.xml 5.xml 6.xml 7.xml 8.xml 9.xml ";
	string produced;
	vector<Path> responseFiles = getResponseFiles("7");
	for(vector<Path>::iterator i = responseFiles.begin();
			i != responseFiles.end();
			++i)
	{
		produced += i->string();
		produced += " ";
	}

	EXPECT_EQ(expected, produced) <<"response files for survey number 7.";
}

TEST(stage1, tallySurveysCompleted) {
	const unsigned expectedTally = 9;

	EXPECT_EQ(expectedTally, tallySurveysCompleted("7")) 
		<< "Tally of responses collected for id=1.";
}
