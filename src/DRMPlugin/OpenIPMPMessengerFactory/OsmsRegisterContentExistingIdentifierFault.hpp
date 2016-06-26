/*
 * Copyright 2003-2004 The Apache Software Foundation.

 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This file was auto-generated by the Axis C++ Web Service Generator (WSDL2Ws)
 * This file contains functions to manipulate complex type OsmsRegisterContentExistingIdentifierFault
 */

#if !defined(__OSMSREGISTERCONTENTEXISTINGIDENTIFIERFAULT_PARAM_H__INCLUDED_)
#define __OSMSREGISTERCONTENTEXISTINGIDENTIFIERFAULT_PARAM_H__INCLUDED_

#include <axis/AxisUserAPI.hpp>
#include <axis/SoapFaultException.hpp>
using namespace std;
AXIS_CPP_NAMESPACE_USE 

/*Local name and the URI for the type*/
static const char* Axis_URI_OsmsRegisterContentExistingIdentifierFault = "http://message.ws.server.osms.mutable.com";
static const char* Axis_TypeName_OsmsRegisterContentExistingIdentifierFault = "OsmsRegisterContentExistingIdentifierFault";

class OsmsRegisterContentExistingIdentifierFault : public SoapFaultException
{
public:
	xsd__int errorCode;
	xsd__string responseString;
	OsmsRegisterContentExistingIdentifierFault();
	virtual ~OsmsRegisterContentExistingIdentifierFault() throw();
};

#endif /* !defined(__OSMSREGISTERCONTENTEXISTINGIDENTIFIERFAULT_PARAM_H__INCLUDED_)*/
