/*
 * MessageConsumer.cpp
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

#include "ccommons/io/ShmFifo.hpp"
#include "model/CheckIMEI.hpp"

using namespace ccommons;
using namespace std;


int receiveTextMessage();
int receiveStructuredMessage();

int main()
{
	receiveTextMessage();
	receiveStructuredMessage();
}


int receiveStructuredMessage()
{
	ccommons::ShmFifo shmFifo("/messaging-textobj-fifo_shm",(1048000016), true);
	ccommons::shm_fifo_message fifo_message;
	messagingmodel::CheckImeiReq checkImei_req;
	long size_buffer = sizeof(messagingmodel::CheckImeiReq);

	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	for (int i=0;i<1000000;i++)
	{
		shmFifo.read(fifo_message);
		memcpy(&checkImei_req,fifo_message.content, size_buffer);
		//cout << "message number: " << fifo_message.message_number << ": " << checkImei_req.msisdn<< endl;
    }

	gettimeofday(&tp, NULL);
	long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	cout << "Text Object Delay: " << (ms2-ms1) << endl;
	cout << "Last message read: [" << fifo_message.message_number << "] imei: " << checkImei_req.imei <<
			" - imsi: " << checkImei_req.imsi << " - msisdn: " << checkImei_req.msisdn << endl;

	return 0;
}

int receiveTextMessage()
{
	ccommons::ShmFifo shmFifo("/messaging-text-fifo_shm",(1048000016), true);
	ccommons::shm_fifo_message fifo_message;


	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms1 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	for (int i=0;i<1000000;i++)
	{
		shmFifo.read(fifo_message);
		//cout << "message number: " << fifo_message.message_number << ": " << checkImei_req.msisdn<< endl;
    }

	gettimeofday(&tp, NULL);
	long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;

	cout << "Text Object Delay: " << (ms2-ms1) << endl;
	cout << "Last message read: [" << fifo_message.message_number << "] content: " << fifo_message.content << endl;

	return 0;
}



