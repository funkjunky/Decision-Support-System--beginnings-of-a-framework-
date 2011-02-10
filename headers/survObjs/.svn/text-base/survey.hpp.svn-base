#ifndef SURVEY_HPP_
#define SURVEY_HPP_

#include "typedefs.hpp"
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

using namespace boost;

namespace dss
{
	class SurveyImpl;
	class Question;

	class Survey
	{
		typedef shared_ptr<SurveyImpl> SurveyImplPtr;

		SurveyImplPtr _surveyImplPtr;

		public:
		Survey();
		Survey(const IDNumber& id);

		const IDNumber& Id() const;
		const std::map<IDNumber, Question>& Questions() const;
		const std::vector<Rule>& Rules() const;

		//gets all rules which a question ID depends on.
		std::vector<Rule> rulesQuestionDependsOn(const IDNumber& questionID) const;
		//gets all rules which are dependent on a question ID.
		std::vector<Rule> rulesDependentOnQuestion(const IDNumber& questionID) const;

		//load the survey object from a survey id. Calls external function.
		void loadFromId(const IDNumber& id);
		//reloads the survey according to the survey's id.
		void reload();
	};
}

#endif
