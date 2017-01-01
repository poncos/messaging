/*
 * CheckImeiResp.h
 *
 * License: MIT
 *
 * (c) Copyright 2016 Esteban Collado Cespon.
 *
 *  Created on: 4 Jul 2016
 *      Author: cespoe
 */
#ifndef MODEL_CHECKIMEI_H_
#define MODEL_CHECKIMEI_H_

namespace messagingmodel
{
	enum CheckImeiStatus
	{
		BLACK=1,
		WHITE,
		GREY,
	};

	enum CheckImeiResultCode
	{
		SUCCESS=1,
		ERROR,
		UNKNOWN,
	};

	struct CheckImeiReq
	{
		char imei[16];
		char imsi[16];
		char msisdn[19];
	};

	struct CheckImeiResp
	{
		CheckImeiStatus status;
		CheckImeiResultCode resultcode;
	};
};

#endif /* MODEL_CHECKIMEI_H_ */
