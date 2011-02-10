#ifndef SURVEYUPDATER_CPP
#define SURVEYUPDATER_CPP

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "typedefs.hpp"
#include "json.hpp"
#include "processJSON.hpp"

#include "surveyupdater.hpp"
#include "surveyupdaterimpl.hpp"

namespace dss
{
		SurveyUpdater::SurveyUpdater()
			:impl(boost::make_shared<SurveyUpdaterImpl>())
		{}

		SurveyUpdater::SurveyUpdater
				(boost::shared_ptr<SurveyUpdaterImpl> _impl)
			:impl(_impl)
		{}

		ServerRetCode SurveyUpdater::updatePData()
		{
			impl->updatePData();
		}
		ServerRetCode SurveyUpdater::updateAlerts()
		{
			impl->updateAlerts();
			//I can't write any of this without researching things like email.
			//the email is the least important part anyways.
		}

		//SurveyUpdater SurveyUpdater::getFromJSON(JSONObject jsonObject);
		void SurveyUpdater::getFromJSON(const JSONObject& jsonObject)
		{
			//return
			//	SurveyUpdater(
			//		boost::make_shared<SurveyUpdaterImpl>(
			//`			impl->getFromJSON(jsonObject)));
		}
}

#endif
