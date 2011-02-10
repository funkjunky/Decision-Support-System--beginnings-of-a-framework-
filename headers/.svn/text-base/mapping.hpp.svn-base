#ifndef MAPPING_HPP
#define MAPPING_HPP

#include <string>
#include <vector>
#include <map>

#include <boost/shared_ptr.hpp>

#include "typedefs.hpp"
#include "relfunctor.hpp"

namespace dss
{
	class canEvaluate
	{
		//I'm not so sure about this yet... TODO: come back here, lol.
		virtual std::map<IDNumber, Datum> evaluate() = 0;
	};

	class Relation;
	class Mapping;
	class Variable;

	//typedef Data (*RelFunctor)
	//						(const std::vector<Data>& orderedExpressions);
	//this define will do fun preprocessor stuff to give a relational id 
	//to every functor, somehow.
	#define IDRELMAPPING std::map<relIDNumber, RelFunctor>()
	class Relation
	{
		public:
		Relation(boost::shared_ptr<RelFunctor> _relFunctor);
		Relation(relIDNumber _id);

		private:
		relIDNumber id;
		boost::shared_ptr<RelFunctor> relFunctor;
		//static const std::map<relIDNumber, RelFunctor> IDRelMapping
		//		= IDRELMAPPING;
	};

	//rel = f; orderedExpressions = {A, (h B C), D, (g A)}
	//This would look like thus in terms of functors:
	//f(A, h(B, C), D, (g(A)))
	class Mapping : canEvaluate
	{ 
		public:
		//TODO: REMOVE ME ASAP!
		Mapping();
		Mapping(const Relation& _rel
						, boost::shared_ptr<std::vector<canEvaluate> > 
								_orderedExpressions);

		virtual std::map<IDNumber, Datum> evaluate();

		private:
		Relation rel;
		boost::shared_ptr<std::vector<canEvaluate> > orderedExpressions;
	};
	
	class Variable : canEvaluate
	{
		public:
		Variable(const IDNumber& _id);

		virtual std::map<IDNumber, Datum> evaluate();

		private:
		IDNumber id;
	};
}

#endif
