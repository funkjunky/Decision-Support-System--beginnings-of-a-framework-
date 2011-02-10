#ifndef UNARYTALLY_HPP
#define UNARYTALLY_HPP

#include <vector>

#include "typedefs.hpp"

#include "relfunctor.hpp"

namespace dss
{
	typedef std::string xmlDoc;
	class UnaryTally : RelFunctor
	{
		public:
		UnaryTally();

		virtual void operator()(std::vector<Datum> parameters);
		virtual const boost::shared_ptr<std::vector<PResult> > getResults();

		virtual bool isOneToOne();

		//hasID
		virtual IDNumber getID();
		virtual AboutID getAboutID();

		private:
		IDNumber id;

		unsigned currentTally;	//keep tabs on the current Tally.

		bool serializationExists(); 	//called during the constructor.
		void unserialize();				//called during the constructor.
		void serializeAndSave();		//called during getResult.
		Path getSerializePath();		//gets the filepath and name.
		//perhaps I should use serialization
		xmlDoc serializeThis();			//gets the xmlDOC from serializing.
	};
}

#endif
