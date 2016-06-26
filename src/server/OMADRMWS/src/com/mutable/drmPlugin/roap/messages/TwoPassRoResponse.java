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
package com.mutable.drmPlugin.roap.messages;

import com.mutable.drmPlugin.roap.messages.extensions.RoResponseExtensions;
import com.mutable.drmPlugin.roap.messages.status.SuccessStatus;
import com.mutable.drmPlugin.roap.misc.CertificateChain;
import com.mutable.drmPlugin.roap.misc.Nonce;
import com.mutable.drmPlugin.roap.misc.RoapIdentifier;
import com.mutable.drmPlugin.roap.ro.ProtectedRos;
import com.mutable.drmPlugin.tools.*;

/**
 * Successful 
 * RoResponse server message of the
 * 2-pass  Roap rights acquisition protocol
 * 
 * 
 * 
 *
 */

public class TwoPassRoResponse extends SuccessRoResponseAbstract {
	
	protected Nonce nonce;


	public TwoPassRoResponse(SuccessStatus status, RoapIdentifier did, 
			RoapIdentifier rid, ProtectedRos ro, CertificateChain chain, 
			Base64StringVector response, RoResponseExtensions extensions, 
			Base64String signature, Nonce nonce) {
		super(status, did, rid, ro, chain, response, extensions, signature);
		if (nonce==null) throw new IllegalArgumentException();
		this.nonce = nonce;
	}

	/*
	 * accessors
	 */
	
	public Nonce getNonce() {
		return nonce;
	}



}
