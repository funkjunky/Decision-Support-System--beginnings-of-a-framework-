#ifndef SURVEYUPDATERIMPL_HPP
#define SURVEYUPDATERIMPL_HPP

#include <boost/shared_ptr.hpp>

#include <vector>
#include <string>

#include "mapping.hpp"
#include "typedefs.hpp"
#include "alert.hpp"
#include "json.hpp"

namespace dss
{
	enum UpdaterStatus
	{
		MANUAL, PUSH, FROZEN, WATCH, DEPRECATED, ARCHIVED
	};

	typedef std::string XMLNode;	//TODO: update this with a real XML Node
	class SurveyUpdaterImpl : canDeJSONify
	{
		public:
		SurveyUpdaterImpl();		//updates the timestamp and used/ignored list.

		ServerRetCode updatePData();				//Functors keep track of serializaed objects.
		ServerRetCode updateAlerts();

		//SurveyUpdaterImpl getFromJSON(const JSONObject& jsonObject);
		virtual void getFromJSON(const JSONObject& jsonObject);

										//this will need to send out a warning 
										//if updateAlerts xor updatePData wasn't
										//called. That would be bad.

		private:
		ServerRetCode parseRelationalMappingXML();	//stores them in relMap.
		ServerRetCode praseAlertsXML();			//stores them in alerts.

		Path relationFile;
		XMLNode homeNode;
		Mapping relMap; //this consists of an expression of relations and ids. ie. ((x rela y) relb z)
		std::vector<Alert> alerts;	//take an id that would represent the updater.

		UpdaterStatus status;
		TimeStamp lastUpdate;
		std::vector<respIDNumber> responsesUsed;
		std::vector<respIDNumber> responsesIgnored;
	};
}

#endif
