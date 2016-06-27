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
 * This file contains functions to manipulate complex type OsmsRegisterContentAssignIdentifierResponse
 */

#include "OsmsRegisterContentAssignIdentifierResponse.hpp"
#include <axis/AxisWrapperAPI.hpp>

/*
 * This static method serialize a OsmsRegisterContentAssignIdentifierResponse type of object
 */
int Axis_Serialize_OsmsRegisterContentAssignIdentifierResponse(OsmsRegisterContentAssignIdentifierResponse* param, IWrapperSoapSerializer* pSZ, bool bArray = false)
{
	if (bArray)
	{
		pSZ->serialize("<", Axis_TypeName_OsmsRegisterContentAssignIdentifierResponse, ">", NULL);
	}
	else
	{
		bool blnIsNewPrefix = false;
		const AxisChar* sPrefix = pSZ->getNamespacePrefix(Axis_URI_OsmsRegisterContentAssignIdentifierResponse, blnIsNewPrefix);
		if (!blnIsNewPrefix)
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRegisterContentAssignIdentifierResponse, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRegisterContentAssignIdentifierResponse, "\">", NULL);
		}
		else
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRegisterContentAssignIdentifierResponse, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRegisterContentAssignIdentifierResponse, "\" xmlns:", sPrefix, "=\"",
				Axis_URI_OsmsRegisterContentAssignIdentifierResponse, "\">", NULL);
		}
	}

	pSZ->serializeAsElement("metadataType", (void*)(param->metadataType), XSD_STRING);
	pSZ->serializeAsElement("metadataXml", (void*)(param->metadataXml), XSD_STRING);

	pSZ->serialize("</", Axis_TypeName_OsmsRegisterContentAssignIdentifierResponse, ">", NULL);
	return AXIS_SUCCESS;
}

/*
 * This static method deserialize a OsmsRegisterContentAssignIdentifierResponse type of object
 */
int Axis_DeSerialize_OsmsRegisterContentAssignIdentifierResponse(OsmsRegisterContentAssignIdentifierResponse* param, IWrapperSoapDeSerializer* pIWSDZ)
{
	param->metadataType = pIWSDZ->getElementAsString("metadataType",0);
	param->metadataXml = pIWSDZ->getElementAsString("metadataXml",0);
	return pIWSDZ->getStatus();
}
void* Axis_Create_OsmsRegisterContentAssignIdentifierResponse(OsmsRegisterContentAssignIdentifierResponse* pObj, bool bArray = false, int nSize=0)
{
	if (bArray && (nSize > 0))
	{
		if (pObj)
		{
			OsmsRegisterContentAssignIdentifierResponse* pNew = new OsmsRegisterContentAssignIdentifierResponse[nSize];
			memcpy(pNew, pObj, sizeof(OsmsRegisterContentAssignIdentifierResponse)*nSize/2);
			memset(pObj, 0, sizeof(OsmsRegisterContentAssignIdentifierResponse)*nSize/2);
			delete [] pObj;
			return pNew;
		}
		else
		{
			return new OsmsRegisterContentAssignIdentifierResponse[nSize];
		}
	}
	else
		return new OsmsRegisterContentAssignIdentifierResponse;
}

/*
 * This static method delete a OsmsRegisterContentAssignIdentifierResponse type of object
 */
void Axis_Delete_OsmsRegisterContentAssignIdentifierResponse(OsmsRegisterContentAssignIdentifierResponse* param, bool bArray = false, int nSize=0)
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
 * This static method gives the size of OsmsRegisterContentAssignIdentifierResponse type of object
 */
int Axis_GetSize_OsmsRegisterContentAssignIdentifierResponse()
{
	return sizeof(OsmsRegisterContentAssignIdentifierResponse);
}

OsmsRegisterContentAssignIdentifierResponse::OsmsRegisterContentAssignIdentifierResponse()
{
	/*do not allocate memory to any pointer members here
	 because deserializer will allocate memory anyway. */
	memset( &metadataType, 0, sizeof( xsd__string));
	memset( &metadataXml, 0, sizeof( xsd__string));
}

OsmsRegisterContentAssignIdentifierResponse::~OsmsRegisterContentAssignIdentifierResponse()
{
	/*delete any pointer and array members here*/
}