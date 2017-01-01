/*
 * SerializeHelper.hpp
 *
 * License: MIT
 *
 * (c) Copyright 2016 Esteban Collado Cespon.
 *
 *  Created on: 4 Jul 2016
 *      Author: cespoe
 */
#ifndef MODEL_SERIALIZATIONUTILS_H_
#define MODEL_SERIALIZATIONUTILS_H_

#include "model/CheckIMEI.hpp"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

namespace messagingmodel
{
	std::string serialize(messagingmodel::CheckImeiReq& checkimei_req);
	void deserialize(std::string objdata,messagingmodel::CheckImeiReq& checkimei_req );
	std::string serialize(messagingmodel::CheckImeiResp& checkimei_req);
	void deserialize(std::string objdata, messagingmodel::CheckImeiResp& checkimei_resp);
};

namespace boost
{
	namespace serialization
	{
		template<class Archive>
		void serialize(Archive & ar, messagingmodel::CheckImeiReq &checkimeireq, const unsigned int version)
		{
			ar & checkimeireq.imei;
			ar & checkimeireq.imsi;
			ar & checkimeireq.msisdn;
		}

		template<class Archive>
		void serialize(Archive & ar, messagingmodel::CheckImeiResp &checkimeiresp, const unsigned int version)
		{
			ar & checkimeiresp.status;
			ar & checkimeiresp.resultcode;
		}
	} // namespace serialization
} // namespace boost


#endif
