#ifndef SURVEYUPDATERIMPL_CPP
#define SURVEYUPDATERIMPL_CPP

#include <boost/shared_ptr.hpp>

#include <vector>
#include <string>

#include "mapping.hpp"
#include "typedefs.hpp"
#include "alert.hpp"

#include "surveyupdaterimpl.hpp"

namespace dss
{
		SurveyUpdaterImpl::SurveyUpdaterImpl()		//updates the timestamp and used/ignored list.
		{
			 //i dunno... this is too dependent on xml.
		}

		ServerRetCode SurveyUpdaterImpl::updatePData()				//Functors keep track of serializaed objects.
		{
			//first load serialized object if it exists.
			//run the functor (I can write this now)
			//resave the serialized object.
			//update any info for this updater.
		}

		ServerRetCode SurveyUpdaterImpl::updateAlerts()
		{
			//I don't really know what to do here...
			//at least not in good enough detail.
			//having the xml would make things easier.
		}

		void SurveyUpdaterImpl::getFromJSON(const JSONObject& jsonObject)
		{
				//requires: JSON
				//ya... return a JSON object representing this...
		}
										//if updateAlerts xor updatePData wasn't
										//called. That would be bad.
}

#endif
