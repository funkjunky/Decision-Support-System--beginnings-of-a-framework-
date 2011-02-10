#ifndef STAGE1_CPP
#define STAGE1_CPP

#include <map>

#include <boost/shared_ptr.hpp>

#include "typedefs.hpp"
#include "stage1.hpp"
#include "stage1impl.hpp"

#include "watch.hpp"


namespace dss
{
	const std::string globalUpdaterFilename = "dataFilesToUpdate.xml";

	ServerRetCode updateAll(const fnIterator& begin, const fnIterator& end)
	{
		GlobalPDataUpdater gpdu(globalUpdaterFilename);
		gpdu.updateWatches();
		gpdu.loadAllSurveyUpdaters();
		gpdu.runAllSurveyUpdaters();
	}

	GlobalPDataUpdater::GlobalPDataUpdater(const Path& filename)
		:impl(new GlobalPDataUpdaterImpl(filename))
	{}
		
	//these will never grab from cache.
	ServerRetCode GlobalPDataUpdater::loadAllSurveyUpdaters()
	{
		impl->loadAllSurveyUpdaters();
	}

	ServerRetCode GlobalPDataUpdater::loadSurveyUpdater
		(const Filename& filename)
	{
		impl->loadSurveyUpdater(filename);
	}

	ServerRetCode GlobalPDataUpdater::updateWatches()
	{
		impl->updateWatches();
	}

	ServerRetCode GlobalPDataUpdater::runAllSurveyUpdaters()
	{
		impl->runAllSurveyUpdaters();
	}
}
#endif
