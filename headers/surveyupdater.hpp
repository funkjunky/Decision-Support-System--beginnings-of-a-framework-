#ifndef SURVEYUPDATER_HPP
#define SURVEYUPDATER_HPP

#include <boost/shared_ptr.hpp>

#include "typedefs.hpp"
#include "json.hpp"
#include "processJSON.hpp"

namespace dss
{
	class SurveyUpdaterImpl;

	class SurveyUpdater : canDeJSONify
	{
		public:
		SurveyUpdater();
		SurveyUpdater(boost::shared_ptr<SurveyUpdaterImpl> _impl);

		//update the processed data.
		ServerRetCode updatePData();
		ServerRetCode updateAlerts();

		//virtual SurveyUpdater getFromJSON(JSONObject jsonObject);

		virtual void getFromJSON(const JSONObject& jsonObject);

		private:
		boost::shared_ptr<SurveyUpdaterImpl> impl;
	};
}

#endif
