/*
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is OpenIPMP.
 * 
 * The Initial Developer of the Original Code is Mutable, Inc.
 * Portions created by Mutable, Inc. are
 * Copyright (C) Mutable, Inc. 2002-2006.  All Rights Reserved.
 * 
 */

#include "io/message/osmsMessageUserLogoutRequest.h"

osmsMessageUserLogoutRequest::osmsMessageUserLogoutRequest()
	: osmsMessage(osmsMessage::osmsMESSAGE_USER_LOGOUT_REQUEST, "com.mutable.osms.common.io.message.osmsMessageUserLogoutRequest")
{
}

osmsMessageUserLogoutRequest::~osmsMessageUserLogoutRequest()
{
}


char* osmsMessageUserLogoutRequest::xmlTemplate()
{
	return
	"<?xml version=\"1.0\"?> \
		<com.mutable.osms.common.io.message.osmsMessageUserLogoutRequest> \
			<MessageType type=\"int\"></MessageType> \
		</com.mutable.osms.common.io.message.osmsMessageUserLogoutRequest> \
    ";
}

char* osmsMessageUserLogoutRequest::encode()
{
	XMLDocument* pDoc = new XMLDocument();
	if (pDoc == NULL)
		return NULL;

	if (!pDoc->decode(xmlTemplate(), getName()))
	{
		delete pDoc;
		return NULL;
	}

	pDoc->setInteger("MessageType", getMessageType());

	char *result = pDoc->encode();

	delete pDoc;

	return result;
}

bool osmsMessageUserLogoutRequest::decode(char* xmlText)
{

	XMLDocument* pDoc = new XMLDocument();
	if (pDoc == NULL)
		return false;

	if (!pDoc->decode(xmlText, getName()))
	{
		delete pDoc;
		return false;
	}

	setMessageType(pDoc->getInteger("MessageType"));

	delete pDoc;

	return true;
}

