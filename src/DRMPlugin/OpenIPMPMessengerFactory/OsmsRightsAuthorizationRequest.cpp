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
 * This file contains functions to manipulate complex type OsmsRightsAuthorizationRequest
 */

#include "OsmsRightsAuthorizationRequest.hpp"
#include <axis/AxisWrapperAPI.hpp>

/*
 * This static method serialize a OsmsRightsAuthorizationRequest type of object
 */
int Axis_Serialize_OsmsRightsAuthorizationRequest(OsmsRightsAuthorizationRequest* param, IWrapperSoapSerializer* pSZ, bool bArray = false)
{
	if (bArray)
	{
		pSZ->serialize("<", Axis_TypeName_OsmsRightsAuthorizationRequest, ">", NULL);
	}
	else
	{
		bool blnIsNewPrefix = false;
		const AxisChar* sPrefix = pSZ->getNamespacePrefix(Axis_URI_OsmsRightsAuthorizationRequest, blnIsNewPrefix);
		if (!blnIsNewPrefix)
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRightsAuthorizationRequest, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRightsAuthorizationRequest, "\">", NULL);
		}
		else
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRightsAuthorizationRequest, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRightsAuthorizationRequest, "\" xmlns:", sPrefix, "=\"",
				Axis_URI_OsmsRightsAuthorizationRequest, "\">", NULL);
		}
	}

	pSZ->serializeAsElement("contentId", (void*)(param->contentId), XSD_STRING);
	pSZ->serializeAsElement("endDate", (void*)&(param->endDate), XSD_DATETIME);
	pSZ->serializeAsElement("licenseType", (void*)(param->licenseType), XSD_STRING);
	pSZ->serializeAsElement("startDate", (void*)&(param->startDate), XSD_DATETIME);
	pSZ->serializeAsElement("userName", (void*)(param->userName), XSD_STRING);

	pSZ->serialize("</", Axis_TypeName_OsmsRightsAuthorizationRequest, ">", NULL);
	return AXIS_SUCCESS;
}

/*
 * This static method deserialize a OsmsRightsAuthorizationRequest type of object
 */
int Axis_DeSerialize_OsmsRightsAuthorizationRequest(OsmsRightsAuthorizationRequest* param, IWrapperSoapDeSerializer* pIWSDZ)
{
	param->contentId = pIWSDZ->getElementAsString("contentId",0);
	xsd__dateTime* p_endDate = (pIWSDZ->getElementAsDateTime("endDate",0));
	param->endDate = *p_endDate;
	delete p_endDate;
	param->licenseType = pIWSDZ->getElementAsString("licenseType",0);
	xsd__dateTime* p_startDate = (pIWSDZ->getElementAsDateTime("startDate",0));
	param->startDate = *p_startDate;
	delete p_startDate;
	param->userName = pIWSDZ->getElementAsString("userName",0);
	return pIWSDZ->getStatus();
}
void* Axis_Create_OsmsRightsAuthorizationRequest(OsmsRightsAuthorizationRequest* pObj, bool bArray = false, int nSize=0)
{
	if (bArray && (nSize > 0))
	{
		if (pObj)
		{
			OsmsRightsAuthorizationRequest* pNew = new OsmsRightsAuthorizationRequest[nSize];
			memcpy(pNew, pObj, sizeof(OsmsRightsAuthorizationRequest)*nSize/2);
			memset(pObj, 0, sizeof(OsmsRightsAuthorizationRequest)*nSize/2);
			delete [] pObj;
			return pNew;
		}
		else
		{
			return new OsmsRightsAuthorizationRequest[nSize];
		}
	}
	else
		return new OsmsRightsAuthorizationRequest;
}

/*
 * This static method delete a OsmsRightsAuthorizationRequest type of object
 */
void Axis_Delete_OsmsRightsAuthorizationRequest(OsmsRightsAuthorizationRequest* param, bool bArray = false, int nSize=0)
{
	if (bArray)
	{
		delete [] param;
	}
	else
	{
		delete param;
	}
}
/*
 * This static method gives the size of OsmsRightsAuthorizationRequest type of object
 */
int Axis_GetSize_OsmsRightsAuthorizationRequest()
{
	return sizeof(OsmsRightsAuthorizationRequest);
}

OsmsRightsAuthorizationRequest::OsmsRightsAuthorizationRequest()
{
	/*do not allocate memory to any pointer members here
	 because deserializer will allocate memory anyway. */
	memset( &contentId, 0, sizeof( xsd__string));
	memset( &endDate, 0, sizeof( xsd__dateTime));
	memset( &licenseType, 0, sizeof( xsd__string));
	memset( &startDate, 0, sizeof( xsd__dateTime));
	memset( &userName, 0, sizeof( xsd__string));
}

OsmsRightsAuthorizationRequest::~OsmsRightsAuthorizationRequest()
{
	/*delete any pointer and array members here*/
}
