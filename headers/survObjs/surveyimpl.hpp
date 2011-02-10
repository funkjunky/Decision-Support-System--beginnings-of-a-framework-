#ifndef SURVEYIMPL_HPP_
#define SURVEYIMPL_HPP_

#include "typedefs.hpp"

#include <map>
#include <vector>

#include "survObjs/question.hpp"

namespace dss
{

	class SurveyImpl
	{
		IDNumber _id;
		//IDNumber: radix number for the question 
		std::map<IDNumber, Question> _questions;
		std::vector<Rule> _rules;

		std::map<IDNumber, Rule> __RulesQuestionDependsOn;
		std::map<IDNumber, Rule> __RulesDependentOnQuestion;

		public:
		SurveyImpl(IDNumber id);

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
