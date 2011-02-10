#ifndef SURVEYRESULTIMPL_HPP_
#define SURVEYRESULTIMPL_HPP_

#include "typedefs.hpp"
#include "survObjs/survey.hpp"
#include "survObjs/response.hpp"

#include <map>

using namespace boost;

namespace dss
{

	class SurveyResultImpl
	{
		shared_ptr<Survey> _survey;
		//Note: should definately use lazy evaluation for "Response".
		std::map<IDNumber, Response> _responses;
		
		public:
		SurveyResultImpl(const shared_ptr<Survey>& s);

		SurveyResultImpl(const IDNumber& survey_id);

		const shared_ptr<Survey>& survey() const;
		const std::map<IDNumber, Response>& Responses() const;
		const Response& getResponse(const IDNumber& response_id);
	};
}

#endif
