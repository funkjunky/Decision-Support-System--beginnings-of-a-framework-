#ifndef MAPPING_CPP
#define MAPPING_CPP

#include <string>
#include <vector>
#include <map>

#include <boost/shared_ptr.hpp>

#include "typedefs.hpp"
#include "relfunctor.hpp"

#include "mapping.hpp"

namespace dss
{
		Relation::Relation(boost::shared_ptr<RelFunctor> _relFunctor)
			:relFunctor(_relFunctor), id("replace with IDRelMapping")
		{}

		Relation::Relation(relIDNumber _id)
			:id(_id), relFunctor()//TODO: relFunct"replace with IDRelMapping")
		{}

		Mapping::Mapping(const Relation& _rel
						, boost::shared_ptr<std::vector<canEvaluate> > 
								_orderedExpressions)
			:rel(_rel), orderedExpressions(_orderedExpressions)
		{}

		std::map<IDNumber, Datum> Mapping::evaluate()
		{
			//use some magic to go through the mapping and get back datum
			//as you can see below the basecases are variables.
			return std::map<IDNumber, Datum>();
		}

		Variable::Variable(const IDNumber& _id)
			: id(_id)
		{}

		std::map<IDNumber, Datum> Variable::evaluate()
		{
			//somehow extract the datum using the variable's id.
			return std::map<IDNumber, Datum>();
		}
}

#endif
