/***********************************************************************;
 * Copyright (c) 2015, Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************************/

#include <tss2/tpm20.h>
#include "sysapi_util.h"

void Marshal_TPMS_AUTH_COMMAND(
	TSS2_SYS_CONTEXT *sysContext,
	TPMS_AUTH_COMMAND *authCommand
	)
{
	if( SYS_CONTEXT->rval != TSS2_RC_SUCCESS )
		return;

	Marshal_UINT32( SYS_CONTEXT->tpmInBuffPtr, SYS_CONTEXT->maxCommandSize, &(SYS_CONTEXT->nextData), authCommand->sessionHandle, &( SYS_CONTEXT->rval ) );
	MARSHAL_SIMPLE_TPM2B( sysContext, (TPM2B *)&authCommand->nonce );
	Marshal_TPMA_SESSION( sysContext, authCommand->sessionAttributes );
	MARSHAL_SIMPLE_TPM2B( sysContext, (TPM2B *)&authCommand->hmac );

	return;
}
