#ifndef JSON_HPP
#define JSON_HPP

#include "processjson.hpp"

namespace dss
{
	//template<typename T>
	class canDeJSONify
	{
		//T getFromJSON(const JSONObject& jsonObject);
		virtual void getFromJSON(const JSONObject& jsonObject) = 0;
	};
}

#endif
