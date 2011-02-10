#ifndef ABOUTID_HPP
#define ABOUTID_HPP

#include <string>

#include <boost/shared_ptr.hpp>

#include "typedefs.hpp"

namespace dss
{
	//this should likely be an enum. Preferably produced via the preprocessor
	//automatically.
	typedef std::string Class;
	struct AboutID
	{
		AboutID(IDNumber _id);

		IDNumber id;
		Class producedBy;

		boost::shared_ptr<IDNumber> surveyID;
		boost::shared_ptr<IDNumber> responseID;
		boost::shared_ptr<IDNumber> questionID;
		boost::shared_ptr<IDNumber> choiceID;
		boost::shared_ptr<relIDNumber> relID;
		boost::shared_ptr<relIDNumber> updaterID;
		boost::shared_ptr<IDNumber> textSnippetID;
	};
}

#endif
