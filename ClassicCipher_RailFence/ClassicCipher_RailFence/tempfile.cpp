
#include <iostream>
using namespace std;


char tmp_text[5][32], c_text[64], d_text[64];
string Rail_Fence(string tempString, int rail, int select ){
    
    int str_size = (int)tempString.length();
    
    int col_num;
    //Encryption
    if( select == 1){
        
        // create rail
        for( col_num=0; col_num< str_size; col_num++){
            if( ((tempString[col_num] >= 'a' ) && ( tempString[col_num] <= 'z')) ||((tempString[col_num] >= 'A' ) && (tempString[col_num] <= 'Z' ))){
                
                if( col_num % 2 == 0 ) {
                    tmp_text[0][col_num / 2]  = tempString[col_num];
                }
                else{
                    tmp_text[1][col_num / 2 ]  = tempString[col_num];
                }
                
            }
            
        }
        
        // even
        if( (str_size  % 2) == 0 ){
            for( col_num =0 ; col_num < (str_size /2) ; col_num++){
                c_text[col_num] = tmp_text[0][col_num];
                c_text[col_num + (str_size/2)] = tmp_text[1][col_num];
            }
        }
        // odd
        else{
            for(col_num =0 ; col_num < (str_size /2) ; col_num++){
                c_text[col_num] = tmp_text[0][col_num];
                c_text[col_num + (str_size/2) +1] = tmp_text[1][col_num];
            }
            c_text[str_size/2] = tmp_text[0][col_num];
        }
        cout<< "cipher : "<<endl;
        for( col_num = 0; col_num < str_size ; col_num++){
            printf( "%c",c_text[col_num]);
        }
        cout<<endl;
        
        
        return c_text;
        
    }
    
    // decrtyption
    else{
        // create rail
        for( col_num=0; col_num< (str_size /2 ); col_num++){
            if( ((tempString[col_num] >= 'a' ) && ( tempString[col_num] <= 'z')) ||((tempString[col_num] >= 'A' ) && (tempString[col_num] <= 'Z' ))){
                tmp_text[0][col_num] = tempString[col_num];
                tmp_text[1][col_num] = tempString[col_num + (str_size /2) +1 ];
            }
            
        }
        
        if( str_size % 2 !=0 ){
            tmp_text[0][col_num] = tempString[(str_size/2)];
        }
        else;
        
        
        for( col_num =0 ; col_num <str_size; col_num ++){
            if( col_num % 2 == 0){
                d_text[col_num ] = tmp_text[0][col_num/2];
            }
            else{
                d_text[col_num] = tmp_text[1][col_num/2];
            }
        }
        cout<< "plain text : "<<endl;
        for( col_num = 0; col_num < str_size ; col_num++){
            printf( "%c",d_text[col_num]);
        }
        cout<<endl;
        
        
        
        return d_text;
    }
    
    
    
    
    
    
    
}

int main(int argc, const char * argv[]) {
    
    string plainText;
    string cipherText;
    string decrytionText;
    
    int rail;
    
    getline( cin, plainText);
    
    cout<< "rail수를  입력해주세요 : "<<endl;
    cin>> rail;
    
    
    cipherText= Rail_Fence(plainText,rail,1);
    decrytionText = Rail_Fence(cipherText,rail,0);
    
    
    
    
    
    
    return 0;
}
