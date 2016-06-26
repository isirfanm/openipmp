/*
 * Copyright 2003,2004 The Apache Software Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * $Log: XSerializationException.hpp,v $
 * Revision 1.1  2005/07/26 02:26:52  craigm
 * Added for xerces 2.3 support (for Mac port)
 *
 * Revision 1.2  2004/09/08 13:56:14  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.1  2003/09/18 18:31:24  peiyongz
 * OSU: Object Serialization Utilities
 *
 * $Id: XSerializationException.hpp,v 1.1 2005/07/26 02:26:52 craigm Exp $
 *
 */


#if !defined(XSERIALIZATION_EXCEPTION_HPP)
#define XSERIALIZATION_EXCEPTION_HPP

#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/XMLException.hpp>

XERCES_CPP_NAMESPACE_BEGIN

MakeXMLException(XSerializationException, XMLUTIL_EXPORT)

XERCES_CPP_NAMESPACE_END

#endif
