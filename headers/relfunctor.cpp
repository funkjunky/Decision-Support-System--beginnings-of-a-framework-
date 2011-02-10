#ifndef RELFUNCTOR_CPP
#define RELFUNCTOR_CPP

#include <vector>

#include "typedefs.hpp"
#include "aboutid.hpp"
#include "hasID.hpp"

#include "relfunctor.hpp"

namespace dss
{
		PResult::PResult(IDNumber _id, Datum _datum)
			:id(_id), datum(_datum)
		{}

		IDNumber PResult::getID()
		{
			return id;
		}

		AboutID PResult::getAboutID()
		{
			//TODO: fill this out properly.
			return _getAboutID();
		}
}

#endif
