#ifndef STAGE1IMPL_HPP
#define STAGE1IMPL_HPP

#include "watch.hpp"
#include "surveyupdater.hpp"

#include <map>
#include <vector>

namespace dss
{
	class GlobalPDataUpdaterImpl
	{
		public:
		GlobalPDataUpdaterImpl(const Path& filename);

		ServerRetCode loadAllSurveyUpdaters();
		ServerRetCode loadSurveyUpdater(const Filename& filename);

		ServerRetCode updateWatches();

		ServerRetCode runAllSurveyUpdaters();

		private:
		std::vector<SurveyUpdater>& getAllSurveyUpdaters
			(bool ignoreCache=false);
		SurveyUpdater& getSurveyUpdater
			(const Filename& filename, bool ignoreCache=false);
		
		//private member variables
		Path globalFilename;
		std::vector<SurveyUpdater> surveyUpdaters;
		std::vector<Watch> watches;

		//cache
		bool AllSurveyUpdatersLoaded;
		std::map<Filename, bool> SurveyUpdaterLoaded;
	};
}

#endif
