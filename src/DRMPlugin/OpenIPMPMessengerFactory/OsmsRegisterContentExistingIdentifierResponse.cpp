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
 * This file contains functions to manipulate complex type OsmsRegisterContentExistingIdentifierResponse
 */

#include "OsmsRegisterContentExistingIdentifierResponse.hpp"
#include <axis/AxisWrapperAPI.hpp>

/*
 * This static method serialize a OsmsRegisterContentExistingIdentifierResponse type of object
 */
int Axis_Serialize_OsmsRegisterContentExistingIdentifierResponse(OsmsRegisterContentExistingIdentifierResponse* param, IWrapperSoapSerializer* pSZ, bool bArray = false)
{
	if (bArray)
	{
		pSZ->serialize("<", Axis_TypeName_OsmsRegisterContentExistingIdentifierResponse, ">", NULL);
	}
	else
	{
		bool blnIsNewPrefix = false;
		const AxisChar* sPrefix = pSZ->getNamespacePrefix(Axis_URI_OsmsRegisterContentExistingIdentifierResponse, blnIsNewPrefix);
		if (!blnIsNewPrefix)
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRegisterContentExistingIdentifierResponse, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRegisterContentExistingIdentifierResponse, "\">", NULL);
		}
		else
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRegisterContentExistingIdentifierResponse, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRegisterContentExistingIdentifierResponse, "\" xmlns:", sPrefix, "=\"",
				Axis_URI_OsmsRegisterContentExistingIdentifierResponse, "\">", NULL);
		}
	}

	pSZ->serializeAsElement("responseString", (void*)(param->responseString), XSD_STRING);

	pSZ->serialize("</", Axis_TypeName_OsmsRegisterContentExistingIdentifierResponse, ">", NULL);
	return AXIS_SUCCESS;
}

/*
 * This static method deserialize a OsmsRegisterContentExistingIdentifierResponse type of object
 */
int Axis_DeSerialize_OsmsRegisterContentExistingIdentifierResponse(OsmsRegisterContentExistingIdentifierResponse* param, IWrapperSoapDeSerializer* pIWSDZ)
{
	param->responseString = pIWSDZ->getElementAsString("responseString",0);
	return pIWSDZ->getStatus();
}
void* Axis_Create_OsmsRegisterContentExistingIdentifierResponse(OsmsRegisterContentExistingIdentifierResponse* pObj, bool bArray = false, int nSize=0)
{
	if (bArray && (nSize > 0))
	{
		if (pObj)
		{
			OsmsRegisterContentExistingIdentifierResponse* pNew = new OsmsRegisterContentExistingIdentifierResponse[nSize];
			memcpy(pNew, pObj, sizeof(OsmsRegisterContentExistingIdentifierResponse)*nSize/2);
			memset(pObj, 0, sizeof(OsmsRegisterContentExistingIdentifierResponse)*nSize/2);
			delete [] pObj;
			return pNew;
		}
		else
		{
			return new OsmsRegisterContentExistingIdentifierResponse[nSize];
		}
	}
	else
		return new OsmsRegisterContentExistingIdentifierResponse;
}

/*
 * This static method delete a OsmsRegisterContentExistingIdentifierResponse type of object
 */
void Axis_Delete_OsmsRegisterContentExistingIdentifierResponse(OsmsRegisterContentExistingIdentifierResponse* param, bool bArray = false, int nSize=0)
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
 * This static method gives the size of OsmsRegisterContentExistingIdentifierResponse type of object
 */
int Axis_GetSize_OsmsRegisterContentExistingIdentifierResponse()
{
	return sizeof(OsmsRegisterContentExistingIdentifierResponse);
}

OsmsRegisterContentExistingIdentifierResponse::OsmsRegisterContentExistingIdentifierResponse()
{
	/*do not allocate memory to any pointer members here
	 because deserializer will allocate memory anyway. */
	memset( &responseString, 0, sizeof( xsd__string));
}

OsmsRegisterContentExistingIdentifierResponse::~OsmsRegisterContentExistingIdentifierResponse()
{
	/*delete any pointer and array members here*/
}
