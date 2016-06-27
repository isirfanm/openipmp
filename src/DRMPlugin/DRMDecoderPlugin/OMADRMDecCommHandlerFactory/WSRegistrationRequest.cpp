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
 * This file contains functions to manipulate complex type WSRegistrationRequest
 */

#include "WSRegistrationRequest.hpp"
#include <axis/AxisWrapperAPI.hpp>

/*
 * This static method serialize a WSRegistrationRequest type of object
 */
int Axis_Serialize_WSRegistrationRequest(WSRegistrationRequest* param, IWrapperSoapSerializer* pSZ, bool bArray = false)
{
	if (bArray)
	{
		pSZ->serialize("<", Axis_TypeName_WSRegistrationRequest, ">", NULL);
	}
	else
	{
		bool blnIsNewPrefix = false;
		const AxisChar* sPrefix = pSZ->getNamespacePrefix(Axis_URI_WSRegistrationRequest, blnIsNewPrefix);
		if (!blnIsNewPrefix)
		{
			pSZ->serialize("<", Axis_TypeName_WSRegistrationRequest, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_WSRegistrationRequest, "\">", NULL);
		}
		else
		{
			pSZ->serialize("<", Axis_TypeName_WSRegistrationRequest, " xsi:type=\"", sPrefix, ":",
				Axis_TypeName_WSRegistrationRequest, "\" xmlns:", sPrefix, "=\"",
				Axis_URI_WSRegistrationRequest, "\">", NULL);
		}
	}

	pSZ->serializeAsElement("msg", (void*)(param->msg), XSD_STRING);

	pSZ->serialize("</", Axis_TypeName_WSRegistrationRequest, ">", NULL);
	return AXIS_SUCCESS;
}

/*
 * This static method deserialize a WSRegistrationRequest type of object
 */
int Axis_DeSerialize_WSRegistrationRequest(WSRegistrationRequest* param, IWrapperSoapDeSerializer* pIWSDZ)
{
	param->msg = pIWSDZ->getElementAsString("msg",0);
	return pIWSDZ->getStatus();
}
void* Axis_Create_WSRegistrationRequest(WSRegistrationRequest* pObj, bool bArray = false, int nSize=0)
{
	if (bArray && (nSize > 0))
	{
		if (pObj)
		{
			WSRegistrationRequest* pNew = new WSRegistrationRequest[nSize];
			memcpy(pNew, pObj, sizeof(WSRegistrationRequest)*nSize/2);
			memset(pObj, 0, sizeof(WSRegistrationRequest)*nSize/2);
			delete [] pObj;
			return pNew;
		}
		else
		{
			return new WSRegistrationRequest[nSize];
		}
	}
	else
		return new WSRegistrationRequest;
}

/*
 * This static method delete a WSRegistrationRequest type of object
 */
void Axis_Delete_WSRegistrationRequest(WSRegistrationRequest* param, bool bArray = false, int nSize=0)
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
 * This static method gives the size of WSRegistrationRequest type of object
 */
int Axis_GetSize_WSRegistrationRequest()
{
	return sizeof(WSRegistrationRequest);
}

WSRegistrationRequest::WSRegistrationRequest()
{
	/*do not allocate memory to any pointer members here
	 because deserializer will allocate memory anyway. */
	memset( &msg, 0, sizeof( xsd__string));
}

WSRegistrationRequest::~WSRegistrationRequest()
{
	/*delete any pointer and array members here*/
}