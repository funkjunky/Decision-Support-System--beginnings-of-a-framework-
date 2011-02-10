#include <iostream>
#include <vector>
#include <map>
#include "dss.hpp"
#include "boost/filesystem.hpp"


#include "stage1_test.hpp"

#include <gtest/gtest.h>

#define _RTEST 0 
#if _RTEST
	#include "RInside.h"
#endif

using namespace std;
using namespace dss;
using namespace dss::surveysystem;

ostream& operator<<(ostream& out, const vector<IDNumber>& v);
ostream& operator<<(ostream& out, const vector<Path>& v);
ostream& operator<<(ostream& out, const map<IDNumber, unsigned>& v);

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//Will catch any vector, but may only work on some.
ostream& operator<<(ostream& out, const vector<IDNumber>& v)
{
	for (vector<IDNumber>::const_iterator it = v.begin();it != v.end();++it)
		out << *it << ((it+1 == v.end())?" ":", ");

	return out;
}

//Will catch any vector, but may only work on some.
ostream& operator<<(ostream& out, const vector<Path>& v)
{
	for (vector<Path>::const_iterator it = v.begin();it != v.end();++it)
		out << *it << ((it+1 == v.end())?" ":", ");

	return out;
}

ostream& operator<<(ostream& out, const map<IDNumber, unsigned>& v)
{
	for (map<IDNumber, unsigned>::const_iterator it = v.begin();it != v.end();++it)
		out << it->first << ": " << it->second << endl;

	return out;
}

#if _RTEST
void rTest(int argc, char* argv[])
{
	RInside R(argc, argv);
	R["txt"] = "Hello, world!\n";

	R.parseEvalQ("cat(txt)");

	exit(0);
}
#endif
