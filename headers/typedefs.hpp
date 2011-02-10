#ifndef TYPEDEFS_HPP_
#define TYPEDEFS_HPP_

#include <boost/filesystem.hpp>

#include <string>

namespace dss
{
	//The type we use to identify anything in our survey database.
	//This will likely become a radix number, or a string representing 
	//a radix number.
	typedef std::string IDNumber;
	typedef std::string relIDNumber;

	typedef std::string Rule;
	typedef boost::filesystem::path Path;	//this is so we can change to wpath, if necessary.
	typedef std::string Filename;
	typedef void ServerRetCode;
	typedef std::vector<Filename>::iterator fnIterator;

	typedef std::string Datum;
	typedef std::string TimeStamp;
	typedef IDNumber respIDNumber;
}

#endif
