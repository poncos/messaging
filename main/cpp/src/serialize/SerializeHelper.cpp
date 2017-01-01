/*
 * SerializeHelper.cpp
 *
 * License: MIT
 *
 * (c) Copyright 2016 Esteban Collado Cespon.
 *
 *  Created on: 4 Jul 2016
 *      Author: cespoe
 */
#include "serialize/SerializeHelper.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace messagingmodel
{
	std::string serialize(messagingmodel::CheckImeiReq& checkimei_req)
	{
		std::ostringstream checkimei_ostream;
		boost::archive::text_oarchive oa(checkimei_ostream);

		oa << checkimei_req;
		return checkimei_ostream.str();
	}

	std::string serialize(messagingmodel::CheckImeiResp& checkimei_resp)
	{
		std::ostringstream checkimei_ostream;
		boost::archive::text_oarchive oa(checkimei_ostream);

		oa << checkimei_resp;
		return checkimei_ostream.str();
	}

	void deserialize(std::string objdata,messagingmodel::CheckImeiReq& checkimei_req )
	{
		std::istringstream checkimei_istream( objdata );
		boost::archive::text_iarchive ia(checkimei_istream);

		ia >> checkimei_req;
	}

	void deserialize(std::string objdata, messagingmodel::CheckImeiResp& checkimei_resp)
	{
		std::istringstream checkimei_istream( objdata );
		boost::archive::text_iarchive ia(checkimei_istream);

		ia >> checkimei_resp;
	}
};
