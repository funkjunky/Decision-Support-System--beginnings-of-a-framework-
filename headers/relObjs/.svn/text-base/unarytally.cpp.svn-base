#ifndef UNARYTALLY_CPP
#define UNARYTALLY_CPP

#include <vector>
#include <sstream>

#include <boost/make_shared.hpp>

#include "typedefs.hpp"

#include "relObjs/unarytally.hpp"

namespace dss
{
		UnaryTally::UnaryTally()
		{
			if(serializationExists())
				unserialize();
		}

		void UnaryTally::operator()(std::vector<Datum> parameters)
		{
				  //perhaps I may want to tally all parameter
				  //maybe not.. perhaps their should be one unary tally
				  //per item.
			++currentTally;
		}
		const boost::shared_ptr<std::vector<PResult> > 
			UnaryTally::getResults()
		{
			std::string optionID = "?";
			std::ostringstream out;
			out << currentTally;
			Datum datum = out.str();
			std::vector<PResult> result 
				= std::vector<PResult>(1, PResult(optionID, datum));

			//perhaps this should take a vector<PResult>?
			serializeAndSave();
			return boost::make_shared<std::vector<PResult> >(result);
		}

		//a tally isn't one to one.
		bool UnaryTally::isOneToOne()
		{
			return false;
		}

		//hasID
		IDNumber UnaryTally::getID()
		{
			return id;
		}
		AboutID UnaryTally::getAboutID()
		{
			//TODO: fill out actual AboutID...
			return AboutID("?");
		}

		bool serializationExists()
		{
			//check for JSONness...
		}

		void unserialize()
		{
			//requires: JSON
		}

		void serializeAndSave()
		{
			//JSON
		}

		Path getSerializePath()
		{
			//TODO: fill this in... this can be done.
		}

		xmlDoc serializeThis()
		{
			//I unno...
			return xmlDoc();
		}
}

#endif
