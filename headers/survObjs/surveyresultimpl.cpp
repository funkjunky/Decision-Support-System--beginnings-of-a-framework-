#ifndef SURVEYRESULTIMPL_CPP_
#define SURVEYRESULTIMPL_CPP_

#include "typedefs.hpp"
#include "survObjs/surveyresultimpl.hpp"
#include "survObjs/survey.hpp"
#include "survObjs/response.hpp"

#include <map>

#include <boost/make_shared.hpp>

using namespace boost;

namespace dss
{
	SurveyResultImpl::SurveyResultImpl(const shared_ptr<Survey>& s)
		: _survey(s)
	{}

	SurveyResultImpl::SurveyResultImpl(const IDNumber& survey_id)
		: _survey(make_shared<Survey>(survey_id))
	{}

	const shared_ptr<Survey>& SurveyResultImpl::survey() const
	{
		return _survey;
	}

	const std::map<IDNumber, Response>& SurveyResultImpl::Responses() const
	{
		return _responses;
	}

	//get the response, cache it in the implementation object, and return the reference to that cahced object. const ref.
	const Response& SurveyResultImpl::getResponse(const IDNumber& response_id)
	{
		throw "not yet implemented.";
	}
}

#endif
