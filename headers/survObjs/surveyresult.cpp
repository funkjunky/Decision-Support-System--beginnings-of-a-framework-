#ifndef SURVEYRESULT_CPP_
#define SURVEYRESULT_CPP_

#include <boost/make_shared.hpp>

#include "typedefs.hpp"
#include "survObjs/surveyresult.hpp"
#include "survObjs/surveyresultimpl.hpp"
#include "survObjs/survey.hpp"
#include "survObjs/response.hpp"

using namespace boost;

namespace dss
{
	//this assumes a reference is already created somewhere, or you could make it from scratch.
	SurveyResult::SurveyResult(const shared_ptr<Survey>& s)
		: _surveyResultImplPtr(make_shared<SurveyResultImpl>(s))
	{}

	//this one takes a number and CREATES the survey. if this is used you must pass all other references from this.
	SurveyResult::SurveyResult(const IDNumber& survey_id)
		: _surveyResultImplPtr(make_shared<SurveyResultImpl>(survey_id))
	{}

	shared_ptr<Survey>& SurveyResult::survey() const
	{
		_surveyResultImplPtr->survey();
	}

	const std::map<IDNumber, Response>& SurveyResult::Responses() const
	{
		_surveyResultImplPtr->Responses();
	}

	const Response& SurveyResult::getResponse(const IDNumber& response_id)
	{
		_surveyResultImplPtr->getResponse(response_id);
	}
}

#endif
