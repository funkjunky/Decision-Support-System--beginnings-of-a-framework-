#ifndef STAGE1_HPP
#define STAGE1_HPP

//includes
#include <map>
#include <vector>
#include <string>
#include "boost/filesystem.hpp"

#include "typedefs.hpp"

namespace dss
{
	class SurveySystem;
	class Survey;
	class Question;
	class Response;
	class SurveyResult;

	namespace surveysystem
	{
			//quick smaller functions//
			///////////////////////////
			//All of the paths involved with the survey system.
			const Path _path_surveys = "private/surveys.db";
			const Path SubPath_responses = "responses";
			const Path& Path_surveys() throw();
			bool surveyExists(IDNumber) throw();
			//Summary:
			//		returns a vector of all survey directories.
			std::vector<Path> allSurveyDirectories() throw();
			//Summary:
			//		returns a vector of all survey IDs.
			std::vector<IDNumber> allSurveyIDs() throw();
			//
			std::vector<Path> getResponseFiles
													(IDNumber survey_id) throw();

			//Larger functions//
			////////////////////
			//This may as well exist here. The global function can call this.
			std::map<IDNumber, unsigned> tallySurveysCompleted() throw();
			unsigned tallySurveysCompleted(IDNumber survey_id) throw();
	}

	//Summary: 
	//		returns a tally of the respones for a question
	//return type: 
	//		a map with choice id as key, and tally of responses
	//		for that specific key as the value.
	//Question types this works for:
	//		Current:	Multiple Choice (single selection)
	//					Multiple Choice (multiple selection)
	//		Future:	Text Response, Cloze questions, any really...
	//					would require further thought, however.
	std::map<IDNumber, unsigned> tallyQuestionResponses(
							IDNumber surveyID, IDNumber questionID);
}

#endif
