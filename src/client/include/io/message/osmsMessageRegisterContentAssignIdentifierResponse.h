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
#ifndef osmsMessageRegisterContentAssignIdentifierResponse_H
#define osmsMessageRegisterContentAssignIdentifierResponse_H

#include "osmsMessage.h"

class osmsMessageRegisterContentAssignIdentifierResponse : public osmsMessage
{

public:
	osmsMessageRegisterContentAssignIdentifierResponse();
	virtual ~osmsMessageRegisterContentAssignIdentifierResponse();

	virtual char* encode();
	virtual bool decode(char* xmlText);
	virtual char* xmlTemplate();

	//bean properties
	char* getMetadataType();
	void setMetadataType(char* MetadataType);

	char* getMetadataXml();
	void setMetadataXml(char* MetadataXml);

private:
	char* m_MetadataType;
	char* m_MetadataXml;
};

#endif // osmsMessageRegisterContentAssignIdentifierResponse_H