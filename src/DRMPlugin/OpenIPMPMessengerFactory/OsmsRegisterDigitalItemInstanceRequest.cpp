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
 * This file contains functions to manipulate complex type OsmsRegisterDigitalItemInstanceRequest
 */

#include "OsmsRegisterDigitalItemInstanceRequest.hpp"
#include <axis/AxisWrapperAPI.hpp>

/*
 * This static method serialize a OsmsRegisterDigitalItemInstanceRequest type of object
 */
int Axis_Serialize_OsmsRegisterDigitalItemInstanceRequest(OsmsRegisterDigitalItemInstanceRequest* param, IWrapperSoapSerializer* pSZ, bool bArray = false)
{
	if (bArray)
	{
		pSZ->serialize("<", Axis_TypeName_OsmsRegisterDigitalItemInstanceRequest, ">", NULL);
	}
	else
	{
		bool blnIsNewPrefix = false;
		const AxisChar* sPrefix = pSZ->getNamespacePrefix(Axis_URI_OsmsRegisterDigitalItemInstanceRequest, blnIsNewPrefix);
		if (!blnIsNewPrefix)
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRegisterDigitalItemInstanceRequest, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRegisterDigitalItemInstanceRequest, "\">", NULL);
		}
		else
		{
			pSZ->serialize("<", Axis_TypeName_OsmsRegisterDigitalItemInstanceRequest, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_OsmsRegisterDigitalItemInstanceRequest, "\" xmlns:", sPrefix, "=\"",
				Axis_URI_OsmsRegisterDigitalItemInstanceRequest, "\">", NULL);
		}
	}

	pSZ->serializeAsElement("auxDataXml", (void*)(param->auxDataXml), XSD_STRING);
	pSZ->serializeAsElement("keyXml", (void*)(param->keyXml), XSD_STRING);
	pSZ->serializeAsElement("metadataType", (void*)(param->metadataType), XSD_STRING);
	pSZ->serializeAsElement("metadataXml", (void*)(param->metadataXml), XSD_STRING);

	pSZ->serialize("</", Axis_TypeName_OsmsRegisterDigitalItemInstanceRequest, ">", NULL);
	return AXIS_SUCCESS;
}

/*
 * This static method deserialize a OsmsRegisterDigitalItemInstanceRequest type of object
 */
int Axis_DeSerialize_OsmsRegisterDigitalItemInstanceRequest(OsmsRegisterDigitalItemInstanceRequest* param, IWrapperSoapDeSerializer* pIWSDZ)
{
	param->auxDataXml = pIWSDZ->getElementAsString("auxDataXml",0);
	param->keyXml = pIWSDZ->getElementAsString("keyXml",0);
	param->metadataType = pIWSDZ->getElementAsString("metadataType",0);
	param->metadataXml = pIWSDZ->getElementAsString("metadataXml",0);
	return pIWSDZ->getStatus();
}
void* Axis_Create_OsmsRegisterDigitalItemInstanceRequest(OsmsRegisterDigitalItemInstanceRequest* pObj, bool bArray = false, int nSize=0)
{
	if (bArray && (nSize > 0))
	{
		if (pObj)
		{
			OsmsRegisterDigitalItemInstanceRequest* pNew = new OsmsRegisterDigitalItemInstanceRequest[nSize];
			memcpy(pNew, pObj, sizeof(OsmsRegisterDigitalItemInstanceRequest)*nSize/2);
			memset(pObj, 0, sizeof(OsmsRegisterDigitalItemInstanceRequest)*nSize/2);
			delete [] pObj;
			return pNew;
		}
		else
		{
			return new OsmsRegisterDigitalItemInstanceRequest[nSize];
		}
	}
	else
		return new OsmsRegisterDigitalItemInstanceRequest;
}

/*
 * This static method delete a OsmsRegisterDigitalItemInstanceRequest type of object
 */
void Axis_Delete_OsmsRegisterDigitalItemInstanceRequest(OsmsRegisterDigitalItemInstanceRequest* param, bool bArray = false, int nSize=0)
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
 * This static method gives the size of OsmsRegisterDigitalItemInstanceRequest type of object
 */
int Axis_GetSize_OsmsRegisterDigitalItemInstanceRequest()
{
	return sizeof(OsmsRegisterDigitalItemInstanceRequest);
}

OsmsRegisterDigitalItemInstanceRequest::OsmsRegisterDigitalItemInstanceRequest()
{
	/*do not allocate memory to any pointer members here
	 because deserializer will allocate memory anyway. */
	memset( &auxDataXml, 0, sizeof( xsd__string));
	memset( &keyXml, 0, sizeof( xsd__string));
	memset( &metadataType, 0, sizeof( xsd__string));
	memset( &metadataXml, 0, sizeof( xsd__string));
}

OsmsRegisterDigitalItemInstanceRequest::~OsmsRegisterDigitalItemInstanceRequest()
{
	/*delete any pointer and array members here*/
}