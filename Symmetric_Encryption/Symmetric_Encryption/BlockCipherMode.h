//
//  BlockCipherMode.h
//  Symmetric_Encryption
//
//  Created by ChoiChang hyun on 2018. 5. 2..
//  Copyright © 2018년 ChoiChang hyun. All rights reserved.
//

#ifndef BlockCipherMode_h
#define BlockCipherMode_h

#include <stdio.h>
typedef char ElemType;
void DES_CBC_Enc(ElemType p_text[128], ElemType c_text[128], ElemType IV[9],ElemType key[9], int msg_len );
void DES_CFB_Enc(ElemType p_text[128], ElemType c_text[128], ElemType IV[9],ElemType key[9], int msg_len );
void DES_OFB_Enc(ElemType p_text[128], ElemType c_text[128], ElemType IV[9],ElemType key[9], int msg_len );
void DES_CTR_Enc(ElemType p_text[128], ElemType c_text[128], ElemType key[9],unsigned int ctr, int msg_len );


void DES_CBC_Dec(ElemType c_text[128], ElemType d_text[128], ElemType IV[9],ElemType key[9], int msg_len );
void DES_CFB_Dec(ElemType c_text[128], ElemType d_text[128], ElemType IV[9],ElemType key[9], int msg_len );
void DES_OFB_Dec(ElemType c_text[128], ElemType d_text[128], ElemType IV[9],ElemType key[9], int msg_len );
void DES_CTR_Dec(ElemType c_text[128], ElemType d_text[128], ElemType key[9],unsigned int ctr, int msg_len );



#endif /* BlockCipherMode_h */
