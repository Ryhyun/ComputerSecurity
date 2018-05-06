#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BlockCipherMode.h"
#include "des.h"
#define BLOCK_MODE 4 /* 1: CBC, 2: CFB, 3: OFB, 4: CTR */
#define BLOCK_SIZE 8
typedef char ElemType;
int main()
{
    int i;
    ElemType c_text[128] = {0,};
    
    ElemType d_text[128] = {0,};
    ElemType p_text[128]={0,};
    ElemType key[9]={0,};
    ElemType IV[9]={0,};
    ElemType DEC_IV[9]={0,};
    
    int msg_len;
    unsigned int ctr=0;
    
    
    
    
    /* 평문 입력 */
    printf("평문 입력: ");
    gets((char *)p_text);
    /* 비밀키 입력 */
    printf("비밀키 입력: ");
    scanf("%s", key);
    fflush(stdin);
    
    if(BLOCK_MODE!=4){
        /* 초기화 벡터 입력 */
        printf("초기화 벡터 입력: ");
        scanf("%s", IV);
    }
    else{
        /* 카운터 입력 */
        printf("ctr 입력: ");
        scanf("%u", &ctr);
    }
    
 
    
    /* 메시지 길이 계산 */
    msg_len=(strlen((char *)p_text) % BLOCK_SIZE) ? ((strlen((char *)p_text) / BLOCK_SIZE +1)*8):strlen((char *)p_text);
   
    for(i=0; i<BLOCK_SIZE; i++)
        DEC_IV[i] = IV[i];
    
    
    // Encryption
    if(BLOCK_MODE==1)
        DES_CBC_Enc(p_text, c_text, IV, key, msg_len);//DES-CBC 암호화
    else if(BLOCK_MODE==2)
        DES_CFB_Enc(p_text, c_text, IV, key, msg_len);//DES-CFB 암호화
    else if(BLOCK_MODE==3)
        DES_OFB_Enc(p_text, c_text, IV, key, msg_len);//DES-OFB 암호화
    else
        DES_CTR_Enc(p_text, c_text, key, ctr, msg_len);//DES-CTR 암호화
    
    
    /* 암호문 출력 */
    printf("\n암호문: ");
    for(i=0; i<msg_len; i++)
           printf("%c", c_text[i]);
    printf("\n");
    
    
    
    // Decryption
    if(BLOCK_MODE==1)
        DES_CBC_Dec(c_text, d_text, DEC_IV, key, msg_len);//DES-CBC 복호화
    else if(BLOCK_MODE==2)
        DES_CFB_Dec(c_text, d_text, DEC_IV, key, msg_len);//DES-CFB 복호화
    else if(BLOCK_MODE==3)
        DES_OFB_Dec(c_text, d_text, DEC_IV, key, msg_len);//DES-CFB 복호화
    else
        DES_CTR_Dec(c_text, d_text, key, ctr, msg_len);//DES-CTR 복호화
    
    
    /* 복호문 출력 */
    printf("\n복호문: ");
    for(i=0; i<msg_len; i++)
        printf("%c", d_text[i]);
    printf("\n");
                         
    return 0;
}
