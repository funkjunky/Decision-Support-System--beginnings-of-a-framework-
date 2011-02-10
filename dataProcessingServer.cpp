#include <iostream>
#include <string>
#include <vector>

#include "typedefs.hpp"
#include "stage1.hpp"

namespace dss
{
	ServerRetCode receivedResponse(const Filename&);
	ServerRetCode registerResponse(const Filename&);
	ServerRetCode processResponses
		(const fnIterator& begin, const fnIterator& end);

	int main()
	{
		//we run some kind of service or something here? I unno...
	}

	ServerRetCode receivedResponse(const Filename&)
	{
		//creates a new thread and calls registerResponse on that thread.
		//then return success if thread created successfully, 
		//otherwise return failure.
	}

	ServerRetCode registerResponse(const Filename&)
	{
		//adds the response to an array in preparation for when we want to 
		//process the new data. Ie. when it has hit a certain size.
	}

	ServerRetCode processResponses
		(const vIterator& begin, const vIterator& end)
	{
		//pass the responses to a *stage1 function* to process them.
	}
}
