#ifndef STAGE1_CPP
#define STAGE1_CPP

#include <algorithm>
#include <functional>

#include "typedefs.hpp"
#include "surveysystem.hpp"

#include <boost/filesystem.hpp>
#include <xercesc/dom/DOM.hpp>

#include <iostream>

namespace dss
{
	//first get these annoying functors out of the way.
	class is_hidden
	{
		public:
			bool operator ()(Path t, bool negate=false) const
			{
				return t.filename()[0] == '.' ^ negate;
			}
	};

	namespace surveysystem
	{
		const Path& Path_surveys() throw()
			{ return _path_surveys; }

		bool surveyExists(IDNumber survey_id) throw()
		{
			using namespace boost::filesystem;

			return exists(Path_surveys() / survey_id);
		}

		std::vector<Path> allSurveyDirectories() throw()
		{
			using namespace boost::filesystem;
			Path surveysPath(Path_surveys());
	
			std::vector<Path> dirs;
			for(directory_iterator dit(Path_surveys());
					dit != directory_iterator();
					++dit)
				dirs.push_back(dit->path());
			dirs.erase(std::remove_if(dirs.begin(), dirs.end(), is_hidden()), 
							dirs.end());
	
			return dirs;
		}
	
		//could be more effecient with pointers... but damn... too annoying.
		//ie. right now we will create a vector once in the function and then will end up returning the entire vector (ie. putting it on the stack).
		//I guess it's just bad on the stack... no biggie, unless we run out.
		std::vector<IDNumber> allSurveyIDs() throw()
		{
			std::vector<IDNumber> ret;
			std::vector<Path> sd = allSurveyDirectories();
			for(std::vector<Path>::iterator it = sd.begin(); 
					it != sd.end(); ++it)
				ret.push_back(it->filename());
			
			return ret;
		}
	
		std::map<IDNumber, unsigned> tallySurveysCompleted() throw()
		{
			std::vector<IDNumber> surveyIDs = allSurveyIDs();
			std::map<IDNumber, unsigned> surveysTallys;
	
			for(std::vector<IDNumber>::iterator it = surveyIDs.begin();
					it != surveyIDs.end(); ++it)
				surveysTallys[*it] = tallySurveysCompleted(*it);
	
			return surveysTallys;
		}
		unsigned tallySurveysCompleted(IDNumber survey_id) throw()
		{
			return getResponseFiles(survey_id).size();
		}
		//assumes their are only files in the responses directory.
		std::vector<Path> getResponseFiles
										(IDNumber survey_id) throw()
		{
			using namespace boost::filesystem;
	
			Path surveyPath = Path_surveys() / survey_id 
										/	SubPath_responses;
			std::vector<Path> filenames;
	
			for(directory_iterator dit(surveyPath);
					dit != directory_iterator();
					++dit)
				filenames.push_back(dit->path().filename());
	
			return filenames;
		}
	}
}
	
#endif
