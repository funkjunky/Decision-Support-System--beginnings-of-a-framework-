#ifndef RELFUNCTOR_HPP
#define RELFUNCTOR_HPP

#include <vector>

#include "typedefs.hpp"
#include "aboutid.hpp"
#include "hasID.hpp"

namespace dss
{
	class RelFunctor;
	class PResult;

	class RelFunctor : hasID
	{
		virtual void operator()(std::vector<Datum> parameters) = 0;
		virtual const boost::shared_ptr<std::vector<PResult> > getResults() = 0;

		virtual bool isOneToOne() = 0;
	};

	struct PResult : hasID
	{
		PResult(IDNumber _id, Datum _datum);

		IDNumber id;
		Datum datum;

		virtual IDNumber getID();
		virtual AboutID getAboutID();

		private:
		AboutID (*_getAboutID)(); //stores a function that gets the AboutID
		//This will be the only difference between results, so I decided it
		//wasn't necessary to abstract this class, if I had this fnc ptr.
	};
}

#endif
