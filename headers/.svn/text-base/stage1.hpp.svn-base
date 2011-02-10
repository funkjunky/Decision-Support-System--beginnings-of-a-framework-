#ifndef STAGE1_HPP
#define STAGE1_HPP

#include <map>

#include <boost/shared_ptr.hpp>

#include "typedefs.hpp"
#include "stage1impl.hpp"

namespace dss
{
	ServerRetCode updateAll(const fnIterator& begin, const fnIterator& end);

	class SurveyUpdater;
	class Watch;

	class GlobalPDataUpdater
	{
		public:
		GlobalPDataUpdater(const Path& filename);
		
		//these will never grab from cache.
		ServerRetCode loadAllSurveyUpdaters();
		ServerRetCode loadSurveyUpdater(const Filename& filename);

		ServerRetCode updateWatches();

		ServerRetCode runAllSurveyUpdaters();

		private:
		//member variables
		boost::shared_ptr<GlobalPDataUpdaterImpl> impl;
	};
}

#endif
