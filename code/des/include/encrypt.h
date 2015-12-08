/*
*  Copyright (c) 1999 O'Reilly & Associates, Inc.
*
*  Mastering Algorithms with C
*  Kyle Loudon
*
*  Permission is hereby granted, free of charge, to any person obtaining a
*  copy of this software and associated documentation files (the "Software"),
*  to deal in the Software without restriction, including without limitation
*  the rights to use, copy, modify, merge, publish, distribute, sublicense,
*  and/or sell copies of the Software, and to permit persons to whom the
*  Software is furnished to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT. IN NO EVENT SHALL
*  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES, OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
*  FROM, OUT OF, OR IN CONNECTION WITH THE SOFTWARE OR THE USE, OR ANY OTHER
*  DEALINGS IN THE SOFTWARE.
*/

/*****************************************************************************
*                                                                            *
*  ------------------------------- encrypt.h ------------------------------  *
*                                                                            *
*****************************************************************************/

#ifndef ENCRYPT_H
#define ENCRYPT_H

/*****************************************************************************
*                                                                            *
*  In a secure implementation, Huge should be at least 400 decimal digits,   *
*  instead of the 10 below (ULONG_MAX = 4294967295).                         *
*                                                                            *
*****************************************************************************/

typedef unsigned long Huge;

/*****************************************************************************
*                                                                            *
*  Define a structure for RSA public keys.                                   *
*                                                                            *
*****************************************************************************/

typedef struct RsaPubKey_ {

Huge               e;
Huge               n;

} RsaPubKey;

/*****************************************************************************
*                                                                            *
*  Define a structure for RSA private keys.                                  *
*                                                                            *
*****************************************************************************/

typedef struct RsaPriKey_ {

Huge               d;
Huge               n;

} RsaPriKey;

/*****************************************************************************
*                                                                            *
*  --------------------------- Public Interface ---------------------------  *
*                                                                            *
*****************************************************************************/

void des_encipher(const unsigned char *plaintext, unsigned char *ciphertext,
   const unsigned char *key);

void des_decipher(const unsigned char *ciphertext, unsigned char *plaintext,
   const unsigned char *key);

void rsa_encipher(Huge plaintext, Huge *ciphertext, RsaPubKey pubkey);

void rsa_decipher(Huge ciphertext, Huge *plaintext, RsaPriKey prikey);

#endif
