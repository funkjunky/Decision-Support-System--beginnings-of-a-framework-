#ifndef RELTEST_CPP
#define RELTEST_CPP

#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include "typedefs.hpp"
#include "relfunctor.hpp"

#include "relObjs/reltest.hpp"

namespace dss
{
		void RelTest::operator()(std::vector<Datum> parameters)
		{
			deadbeefiness.append("deadbeef");
		}

		const boost::shared_ptr<std::vector<PResult> > RelTest::getResults()
		{
			IDNumber resultID = "?";
			return boost::make_shared<std::vector<PResult> >
						(1, PResult(resultID, deadbeefiness));
		}

		//this test function is not one to one.
		bool RelTest::isOneToOne()
		{
				return false;
		}

		//hasID
		IDNumber RelTest::getID()
		{
			return id;
		}
		AboutID RelTest::getAboutID()
		{
			//TODO: fill this out.
			//code for returning an AboutID
			return AboutID("?");
		}
}

#endif
