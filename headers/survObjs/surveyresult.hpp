#ifndef SURVEYRESULT_HPP_
#define SURVEYRESULT_HPP_

#include "typedefs.hpp"

#include <boost/shared_ptr.hpp>

#include <map>

using namespace boost;

namespace dss
{
	class SurveyResultImpl;
	class Survey;
	class Response;

	typedef shared_ptr<SurveyResultImpl> SurveyResultImplPtr;
	class SurveyResult
	{
		SurveyResultImplPtr _surveyResultImplPtr;

		public:
		//prefered constructor, because this keeps the same reference.
		SurveyResult(const shared_ptr<Survey>& s);
		//this will create a new survey object using the id.
		SurveyResult(const IDNumber& survey_id);

		shared_ptr<Survey>& survey() const;
		const std::map<IDNumber, Response>& Responses() const;

		//Lazy evaluation... I'd prefer to do this when a Response object is accessed, however I can't search how to do that right now.
		//So when someone calls this, the function will load the response, then return it. Hence no const at the end of the prototype.
		const Response& getResponse(const IDNumber& response_id);
	};
}

#endif
