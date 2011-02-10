#ifndef STAGE1IMPL_CPP
#define STAGE1IMPL_CPP

#include <vector>

#include "typedefs.hpp"
#include "surveyupdater.hpp"
#include "stage1impl.hpp"

namespace dss
{
	GlobalPDataUpdaterImpl::GlobalPDataUpdaterImpl(const Path& filename)
		:globalFilename(filename)
	{}

	ServerRetCode GlobalPDataUpdaterImpl::loadAllSurveyUpdaters()
	{
		getAllSurveyUpdaters();
	}
	ServerRetCode GlobalPDataUpdaterImpl::loadSurveyUpdater
		(const Filename& filename)
	{
		getSurveyUpdater(filename);
	}

	ServerRetCode GlobalPDataUpdaterImpl::updateWatches()
	{
		//read xml...
		//for every watch... update the watch if necessary.
		//I'm not 100% on watches yet.
	}

	ServerRetCode GlobalPDataUpdaterImpl::runAllSurveyUpdaters()
	{
		std::vector<SurveyUpdater>& sus = getAllSurveyUpdaters();
		typedef std::vector<SurveyUpdater>::iterator suIter;
		for(suIter it = sus.begin(); it != sus.end()
				  ; ++it)
		{
			it->updatePData();
			it->updateAlerts();
		}
	}
	std::vector<SurveyUpdater>& GlobalPDataUpdaterImpl::getAllSurveyUpdaters
		(bool ignoreCache)
	{
		//read XML, and for every SurveyUpdater
		//call getSurveyUpdater(filename)
		//return doesn't matter.
		//mark All SurveyUpdatersLoaded as true
		//finally return the vector of surveyUpdaters
		surveyUpdaters = std::vector<SurveyUpdater>();
		return surveyUpdaters;
	}

	SurveyUpdater& GlobalPDataUpdaterImpl::getSurveyUpdater
		(const Filename& filename, bool ignoreCache)
	{
		//check the loadSurveyUpdaterCalled map to see if we have already
		//loaded this SurveyUpdater.
		//if not...
		//get the xml file associated to the filename
		//get a SurveyUpdater object from it and add it to the vector.
		//then add the bool true to the loadSurveyUpdaterCalled.
		//then return a reference to the SurveyUpdater.
		surveyUpdaters.push_back(SurveyUpdater());
		return surveyUpdaters[0];
	}
}

#endif
