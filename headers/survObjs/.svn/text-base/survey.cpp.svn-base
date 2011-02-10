#ifndef SURVEY_CPP_
#define SURVEY_CPP_

#include "survObjs/survey.hpp"
#include "survObjs/question.hpp"
#include "survObjs/surveyimpl.hpp"
#include "typedefs.hpp"

#include <map>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace boost;

namespace dss
{

	Survey::Survey()
	{}

	Survey::Survey(const IDNumber& id)
		: _surveyImplPtr(make_shared<SurveyImpl>(id))
	{}

	const IDNumber& Survey::Id() const
	{
		return _surveyImplPtr->Id();
	}

	const std::map<IDNumber, Question>& Survey::Questions() const
	{
		return _surveyImplPtr->Questions();
	}

	const std::vector<Rule>& Survey::Rules() const
	{
		return _surveyImplPtr->Rules();
	}

	std::vector<Rule> Survey::rulesQuestionDependsOn(const IDNumber& questionID) const
	{
		return _surveyImplPtr->rulesQuestionDependsOn(questionID);
	}

	std::vector<Rule> Survey::rulesDependentOnQuestion(const IDNumber& questionID) const
	{
		return _surveyImplPtr->rulesDependentOnQuestion(questionID);
	}

	void Survey::loadFromId(const IDNumber& id)
	{
		return _surveyImplPtr->loadFromId(id);
	}

	void Survey::reload()
	{
		_surveyImplPtr->reload();
	}

}

#endif
