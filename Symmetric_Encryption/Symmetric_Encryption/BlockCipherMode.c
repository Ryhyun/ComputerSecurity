//
//  BlockCipherMode.c
//  Symmetric_Encryption
//
//  Created by ChoiChang hyun on 2018. 5. 2..
//  Copyright © 2018년 ChoiChang hyun. All rights reserved.
//

#include "BlockCipherMode.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "des.h"
#define BLOCK_SIZE 8
#define ASCII_DIFFERENCE 97
typedef char ElemType;
// Encryption
void DES_CBC_Enc(ElemType p_text[128], ElemType c_text[128], ElemType IV[9],ElemType key[9], int msg_len){
    
    ElemType* tempPlain ;
    ElemType* tempCipher ;
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    printf("CBC: %s\n", p_text);
    for( int i=0; i< msg_len/ (BLOCK_SIZE); i++){
        memcpy(tempPlain, p_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        printf("%d tempPlain : %s\n",i, tempPlain);
        
        for(int i=0; i< BLOCK_SIZE; i++){
            tempPlain[i] = tempPlain[i] ^ IV[i];
        }
        DES_Encryption(tempPlain, tempCipher, key);
        memcpy( IV, tempCipher, BLOCK_SIZE);        
        memcpy(c_text+(i*BLOCK_SIZE), tempCipher, BLOCK_SIZE);

        printf("tc: %s\n", tempCipher);
    }
    printf("%s\n", c_text);
    free(tempPlain);
    free(tempCipher);
}
void DES_CFB_Enc(ElemType p_text[128], ElemType c_text[128], ElemType IV[9],ElemType key[9], int msg_len){
    printf("CFB\n");
    
    ElemType* tempPlain ;
    ElemType* tempCipher ;
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    printf("CBC: %s\n", p_text);
    for( int i=0; i< msg_len/ (BLOCK_SIZE); i++){
        // SHIFT REGISTER
        /*
         
         */
        DES_Encryption( IV, tempCipher, key );
        // SELECT / DISCARD
        /*
         
         */
        memcpy(tempPlain, p_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        for(int i=0; i< BLOCK_SIZE; i++){
            tempCipher[i] =  tempCipher[i] ^ tempPlain[i]  ;
        }
        printf("%d tempCipher : %s\n",i, tempCipher);
        memcpy( IV, tempCipher, BLOCK_SIZE);
        memcpy(c_text+(i*BLOCK_SIZE), tempCipher, BLOCK_SIZE);
        
        
    }
    printf("%s\n", c_text);
    free(tempPlain);
    free(tempCipher);
}
void DES_OFB_Enc(ElemType p_text[128], ElemType c_text[128], ElemType IV[9],ElemType key[9], int msg_len){
    printf("OFB\n");
    
    ElemType* tempPlain ;
    ElemType* tempCipher ;
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    printf("CBC: %s\n", p_text);
    for( int i=0; i< msg_len/ (BLOCK_SIZE); i++){
        
        // SHIFT REGISTER
        /*
         
         */
        DES_Encryption( IV, tempCipher, key );
        
        // SELECT / DISCARD
        /*

         */
         
        memcpy( IV, tempCipher, BLOCK_SIZE);
        memcpy(tempPlain, p_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        for(int i=0; i< BLOCK_SIZE; i++){
            tempCipher[i] =  tempCipher[i] ^ tempPlain[i]  ;
        }
        memcpy(c_text+(i*BLOCK_SIZE), tempCipher, BLOCK_SIZE);
    }
    printf("%s\n", c_text);
    free(tempPlain);
    free(tempCipher);
}
void DES_CTR_Enc(ElemType p_text[128], ElemType c_text[128], ElemType key[9],unsigned int ctr, int msg_len ){
    printf("CTR\n");
    ElemType* tempPlain ;
    ElemType* tempCipher ;
    ElemType* ElemCTR;
    unsigned int tempCTR = ctr;
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    ElemCTR = malloc(BLOCK_SIZE * sizeof(char));
    for( int i=0; i< msg_len/ (BLOCK_SIZE); i++){
        sprintf(ElemCTR, "%x", tempCTR);
        printf("ctr + %d : %s\n",i ,ElemCTR);
        DES_Encryption( ElemCTR, tempCipher, key );
        tempCTR++;
        
        memcpy(tempPlain, p_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        for(int i=0; i< BLOCK_SIZE; i++){
            tempCipher[i] =  tempCipher[i] ^ tempPlain[i]  ;
        }
        memcpy(c_text+(i*BLOCK_SIZE), tempCipher, BLOCK_SIZE);
    }
    free(tempPlain);
    free(tempCipher);
    free(ElemCTR);
}

//Decrytion
void DES_CBC_Dec(ElemType c_text[128], ElemType d_text[128], ElemType IV[9],ElemType key[9], int msg_len){
    printf("CBC\n");
    ElemType* tempIV;
    ElemType* tempCipher ;
    ElemType* tempPlain ;
    tempIV = malloc(BLOCK_SIZE * sizeof(char));
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    
    for( int i=0; i< msg_len/ BLOCK_SIZE; i++){
        memcpy(tempCipher, c_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        memcpy( tempIV, tempCipher,BLOCK_SIZE);
        printf("tempCipher : %s\n", tempCipher);
        
        DES_Decryption(tempCipher, tempPlain, key);
        for(int i=0 ; i< BLOCK_SIZE;i++){
            tempPlain[i] = tempPlain[i] ^ IV[i];
        }
        memcpy( IV, tempIV, BLOCK_SIZE);
        memcpy(d_text+(i*BLOCK_SIZE), tempPlain, BLOCK_SIZE);
        printf("tC: %s\n", tempPlain);
        
    }
    printf("%s\n", d_text);
    free(tempPlain);
    free(tempCipher);
    free(tempIV);
}
void DES_CFB_Dec(ElemType c_text[128], ElemType d_text[128], ElemType IV[9],ElemType key[9], int msg_len){
    printf("CFB\n");
    ElemType* tempCipher ;
    ElemType* tempPlain ;
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    
    for( int i=0; i< msg_len/ BLOCK_SIZE; i++){
        memcpy(tempCipher, c_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        // SHIFT REGISTER
        /*
         
         */
        DES_Encryption( IV,tempPlain, key);
        // SELECT / DISCARD
        
        /*
         
         */
        
        for(int i=0 ; i< BLOCK_SIZE;i++){
            tempPlain[i] =  tempPlain[i] ^ tempCipher[i] ;
        }
        memcpy( IV, tempCipher, BLOCK_SIZE);
        memcpy(d_text+(i*BLOCK_SIZE), tempPlain, BLOCK_SIZE);
    }
    printf("%s\n", d_text);
    free(tempPlain);
    free(tempCipher);
}
void DES_OFB_Dec(ElemType c_text[128], ElemType d_text[128], ElemType IV[9],ElemType key[9], int msg_len){
    printf("OFB\b");
    ElemType* tempCipher ;
    ElemType* tempPlain ;
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    
    for( int i=0; i< msg_len/ BLOCK_SIZE; i++){
        memcpy(tempCipher, c_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        // SHIFT REGISTER
        /*
         
         */
        DES_Encryption( IV,tempPlain, key);
        // SELECT / DISCARD
        /*
         
         */
        memcpy( IV, tempPlain, BLOCK_SIZE);
        for(int i=0 ; i< BLOCK_SIZE;i++){
            tempPlain[i] =  tempPlain[i] ^ tempCipher[i] ;
        }
        memcpy(d_text+(i*BLOCK_SIZE), tempPlain, BLOCK_SIZE);
    }
    printf("%s\n", d_text);
    free(tempPlain);
    free(tempCipher);
}
void DES_CTR_Dec(ElemType c_text[128], ElemType d_text[128], ElemType key[9],unsigned int ctr, int msg_len ){
    printf("CTR\n");
    ElemType* tempPlain ;
    ElemType* tempCipher ;
    ElemType* ElemCTR ;
    unsigned int tempCTR = ctr;
    tempPlain = malloc(BLOCK_SIZE * sizeof(char));
    tempCipher = malloc(BLOCK_SIZE * sizeof(char));
    ElemCTR = malloc(BLOCK_SIZE * sizeof(char));
    
    for( int i=0; i< msg_len/ (BLOCK_SIZE); i++){
        sprintf(ElemCTR, "%x", tempCTR);
        printf("ctr + %d : %s\n",i ,ElemCTR);
        DES_Encryption( ElemCTR, tempPlain, key );
        tempCTR++;
        memcpy(tempCipher, c_text+(i* BLOCK_SIZE), BLOCK_SIZE);
        for(int i=0; i< BLOCK_SIZE; i++){
            tempPlain[i] =  tempPlain[i] ^ tempCipher[i]  ;
        }
        memcpy(d_text+(i*BLOCK_SIZE), tempPlain, BLOCK_SIZE);
    }
    free(tempPlain);
    free(tempCipher);
    free(ElemCTR);
}


