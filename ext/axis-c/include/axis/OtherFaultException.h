/*
 *   Copyright 2003-2004 The Apache Software Foundation.
// (c) Copyright IBM Corp. 2004, 2005 All Rights Reserved
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */
#ifndef OTHERFAULTEXCEPTION_INCLUDED
#define OTHERFAULTEXCEPTION_INCLUDED


/**
 * @class OtherFaultException
 * @brief A server-generated soap fault exception
 * 
 * An exception thrown back to a client application that represents a soap
 * fault generated by the server.
 * 
 */
AXISC_STORAGE_CLASS_INFO AXISCHANDLE axiscCreateOtherFaultException(const AxiscChar * code, 
	const AxiscChar * string, const AxiscChar * actor, 
	const AxiscChar * detail, int exceptionCode);
AXISC_STORAGE_CLASS_INFO AXISCHANDLE axiscOperator=OtherFaultExceptionOtherFaultException(AXISCHANDLE otherFaultException, AXISCHANDLE other);
AXISC_STORAGE_CLASS_INFO void axiscDestroyOtherFaultException(AXISCHANDLE otherFaultException);
AXISC_STORAGE_CLASS_INFO const AxiscChar * axiscGetFaultDetail(AXISCHANDLE otherFaultException);
AXISC_STORAGE_CLASS_INFO void axiscSetFaultDetailOtherFaultException(AXISCHANDLE otherFaultException, const AxiscChar * detail);


#endif // OTHERFAULTEXCEPTION_INCLUDED
