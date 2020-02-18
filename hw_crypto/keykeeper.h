// Copyright 2018 The Beam Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once
#include "kdf.h"
#include "coinid.h"
#include "sign.h"

typedef struct
{
	BeamCrypto_Kdf m_MasterKey;

	// TODO: state, Slot management, etc.

} BeamCrypto_KeyKeeper;

typedef struct
{
	BeamCrypto_UintBig m_Secret;
	BeamCrypto_Point m_CoFactorG;
	BeamCrypto_Point m_CoFactorJ;

} BeamCrypto_KdfPub;

void BeamCrypto_KeyKeeper_GetKdfPub(const BeamCrypto_KeyKeeper*, BeamCrypto_KdfPub*, uint32_t* pChild); // if pChild is NULL then the master kdfpub (owner key) is returned

typedef uint64_t BeamCrypto_Height;

typedef struct
{
	BeamCrypto_Amount m_Fee;
	BeamCrypto_Height m_hMin;
	BeamCrypto_Height m_hMax;

	BeamCrypto_Point m_Commitment;
	BeamCrypto_Signature m_Signature;

} BeamCrypto_TxKernel;

void BeamCrypto_TxKernel_getID(const BeamCrypto_TxKernel*, BeamCrypto_UintBig* pMsg);
int BeamCrypto_TxKernel_IsValid(const BeamCrypto_TxKernel*);