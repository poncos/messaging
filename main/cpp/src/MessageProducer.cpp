/*
 * MessageProducer.cpp
 *
 * License: MIT
 *
 * (c) Copyright 2016 Esteban Collado Cespon.
 *
 *  Created on: 28 Nov 2016
 *      Author: poncos
 */
#include <iostream>
#include <sys/time.h>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <sys/time.h>
#include <thread>
#include <new>

#include "ccommons/io/ShmFifo.hpp"
#include "serialize/SerializeHelper.hpp"
#include "model/CheckIMEI.hpp"

using namespace ccommons;
using namespace std;


int sendTextMessage();
int sendTextObjectMessage();
int sendSerializedObjectMessage();

int main()
{
	sendTextMessage();

	sendTextObjectMessage();

	//sendSerializedObjectMessage();
}

int sendTextMessage()
{
	ccommons::ShmFifo shmFifo("/messaging-text-fifo_shm",(1048000016), true);
	string message_content 		= "holaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaholaadios";
	const char* message_content_char
								= message_content.c_str();
	long message_content_size 	= strlen(message_content_char);

	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	for (int i=0;i<1000000;i++)
	{
		shmFifo.write(message_content_char,message_content_size);
	}

	gettimeofday(&tp, NULL);
	long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	cout << "Text Message Delay: " << (ms2-ms1) << endl;

	return 0;
}

int sendSerializedObjectMessage()
{
	ccommons::ShmFifo shmFifo("/messaging-binobj-fifo_shm",(1048000016), true);
	messagingmodel::CheckImeiReq checkImei_req;
	char imei[16] = "254784512658411";
	char imsi[16] = "214021245145781";
	char msisdn[19] = "123456987412547896";

	strcpy(checkImei_req.imei, imei);
	strcpy(checkImei_req.imsi, imsi);
	strcpy(checkImei_req.msisdn, msisdn);

	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	for (int i=0;i<1000000;i++)
	{
		string checkimei_req_str = messagingmodel::serialize(checkImei_req);
		shmFifo.write(checkimei_req_str.c_str(),checkimei_req_str.length());
	}

	gettimeofday(&tp, NULL);
	long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	cout << "Serialized Object Delay: " << (ms2-ms1) << endl;

	return 0;
}

int sendTextObjectMessage()
{
	ccommons::ShmFifo shmFifo("/messaging-textobj-fifo_shm",(1048000016), true);
	messagingmodel::CheckImeiReq checkImei_req;
	char imei[16] = "254784512658411";
	char imsi[16] = "214021245145781";
	char msisdn[19] = "123456987412547896";
	long checkimei_req_size = sizeof(messagingmodel::CheckImeiReq);

	strcpy(checkImei_req.imei, imei);
	strcpy(checkImei_req.imsi, imsi);
	strcpy(checkImei_req.msisdn, msisdn);

	struct timeval tp;
	gettimeofday(&tp, NULL);
	stringstream ss;
	long int ms1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	for (int i=0;i<1000000;i++)
	{
		shmFifo.write(reinterpret_cast<const char*>(&checkImei_req),checkimei_req_size);
    }

	gettimeofday(&tp, NULL);
	long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	cout << "Text Object Delay: " << (ms2-ms1) << endl;

	return 0;
}


