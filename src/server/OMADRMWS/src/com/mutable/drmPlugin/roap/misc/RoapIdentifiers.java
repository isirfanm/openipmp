/*
 * LICENSE AND COPYRIGHT INFORMATION:
 *
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
 * The Initial Developer of the Original Code is Mutable, Inc.
 * Portions created by Mutable, Inc. are
 * Copyright (C) Mutable, Inc. 2002-2006.  All Rights Reserved.
 * 
 *
 */
package com.mutable.drmPlugin.roap.misc;

import java.util.Iterator;
import java.util.Vector;

import com.mutable.drmPlugin.roap.ro.oex.AgreementAsset;
import com.mutable.drmPlugin.xml.IElement;
import com.mutable.drmPlugin.xml.IElements;
import com.mutable.drmPlugin.xml.XmlVector;

/**
 * VectorValue holding RoapIdentifier values
 * @see RoapIdentifier
 * 
 *
 */

public class RoapIdentifiers extends XmlVector {

	protected Class elementClass() { return RoapIdentifier.class; }

	public RoapIdentifiers(Vector data) {
		super(data);
	}
	

	
	protected RoapIdentifiers() {
		super();
	}

	
	public static RoapIdentifiers instanceFromDomElement(IElement elem, String name) {
		IElements children = elem.getChildElements(name);
		return RoapIdentifiers.instanceFromDomElements(children);

	}
	
	public static RoapIdentifiers instanceFromDomElements(IElements elems) {
		Vector v = new Vector(); 
		if (elems==null || elems.isEmpty()) return null;
		for (Iterator i=elems.iterator(); i.hasNext();) 
			v.add(RoapIdentifier.instanceFromDomElement(((IElement)i.next())));
		
		return new RoapIdentifiers(v);
	
	}
	
	
}
