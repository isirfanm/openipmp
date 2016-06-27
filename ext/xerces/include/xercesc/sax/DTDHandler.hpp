/*
 * Copyright 1999-2000,2004 The Apache Software Foundation.
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
 * $Log: DTDHandler.hpp,v $
 * Revision 1.1  2005/07/26 02:26:41  craigm
 * Added for xerces 2.3 support (for Mac port)
 *
 * Revision 1.5  2004/09/08 13:56:19  peiyongz
 * Apache License Version 2.0
 *
 * Revision 1.4  2003/03/07 18:10:06  tng
 * Return a reference instead of void for operator=
 *
 * Revision 1.3  2002/11/04 14:56:25  tng
 * C++ Namespace Support.
 *
 * Revision 1.2  2002/02/20 18:17:01  tng
 * [Bug 5977] Warnings on generating apiDocs.
 *
 * Revision 1.1.1.1  2002/02/01 22:22:08  peiyongz
 * sane_include
 *
 * Revision 1.5  2000/02/24 20:12:54  abagchi
 * Swat for removing Log from API docs
 *
 * Revision 1.4  2000/02/12 03:31:55  rahulj
 * Removed duplicate CVS Log entries.
 *
 * Revision 1.3  2000/02/12 01:27:19  aruna1
 * Documentation updated
 *
 * Revision 1.2  2000/02/06 07:47:57  rahulj
 * Year 2K copyright swat.
 *
 * Revision 1.1.1.1  1999/11/09 01:07:44  twl
 * Initial checkin
 *
 * Revision 1.2  1999/11/08 20:44:54  rahul
 * Swat for adding in Product name and CVS comment log variable.
 *
 */


#ifndef DTDHANDLER_HPP
#define DTDHANDLER_HPP

#include <xercesc/util/XercesDefs.hpp>

XERCES_CPP_NAMESPACE_BEGIN

/**
  * Receive notification of basic DTD-related events.
  *
  * <p>If a SAX application needs information about notations and
  * unparsed entities, then the application implements this
  * interface and registers an instance with the SAX parser using
  * the parser's setDTDHandler method.  The parser uses the
  * instance to report notation and unparsed entity declarations to
  * the application.</p>
  *
  * <p>The SAX parser may report these events in any order, regardless
  * of the order in which the notations and unparsed entities were
  * declared; however, all DTD events must be reported after the
  * document handler's startDocument event, and before the first
  * startElement event.</p>
  *
  * <p>It is up to the application to store the information for
  * future use (perhaps in a hash table or object tree).
  * If the application encounters attributes of type "NOTATION",
  * "ENTITY", or "ENTITIES", it can use the information that it
  * obtained through this interface to find the entity and/or
  * notation corresponding with the attribute value.</p>
  *
  * <p>The HandlerBase class provides a default implementation
  * of this interface, which simply ignores the events.</p>
  *
  * @see Parser#setDTDHandler
  * @see HandlerBase#HandlerBase
  */

class SAX_EXPORT DTDHandler
{
public:
    /** @name Constructors and Destructor */
    //@{
    /** Default Constructor */
    DTDHandler()
    {
    }

    /** Destructor */
    virtual ~DTDHandler()
    {
    }

    //@}

    /** @name The DTD handler interface */
    //@{
  /**
    * Receive notification of a notation declaration event.
    *
    * <p>It is up to the application to record the notation for later
    * reference, if necessary.</p>
    *
    * <p>If a system identifier is present, and it is a URL, the SAX
    * parser must resolve it fully before passing it to the
    * application.</p>
    *
    * @param name The notation name.
    * @param publicId The notation's public identifier, or null if
    *        none was given.
    * @param systemId The notation's system identifier, or null if
    *        none was given.
    * @exception SAXException Any SAX exception, possibly
    *            wrapping another exception.
    * @see #unparsedEntityDecl
    * @see AttributeList#AttributeList
    */
	virtual void notationDecl
    (
        const   XMLCh* const    name
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
    ) = 0;

  /**
    * Receive notification of an unparsed entity declaration event.
    *
    * <p>Note that the notation name corresponds to a notation
    * reported by the notationDecl() event.  It is up to the
    * application to record the entity for later reference, if
    * necessary.</p>
    *
    * <p>If the system identifier is a URL, the parser must resolve it
    * fully before passing it to the application.</p>
    *
    * @exception SAXException Any SAX exception, possibly
    *            wrapping another exception.
    * @param name The unparsed entity's name.
    * @param publicId The entity's public identifier, or null if none
    *        was given.
    * @param systemId The entity's system identifier (it must always
    *        have one).
    * @param notationName The name of the associated notation.
    * @see #notationDecl
    * @see AttributeList#AttributeList
    */
    virtual void unparsedEntityDecl
    (
        const   XMLCh* const    name
        , const XMLCh* const    publicId
        , const XMLCh* const    systemId
        , const XMLCh* const    notationName
    ) = 0;

    /**
    * Reset the DocType object on its reuse
    *
    * <p>This method helps in reseting the DTD object implementational
    * defaults each time the DTD is begun.</p>
    *
    */
    virtual void resetDocType() = 0;

    //@}

private :
    /* Unimplemented constructors and operators */

    /* Copy constructor */
    DTDHandler(const DTDHandler&);

    /* Assignment operator */
    DTDHandler& operator=(const DTDHandler&);

};

XERCES_CPP_NAMESPACE_END

#endif