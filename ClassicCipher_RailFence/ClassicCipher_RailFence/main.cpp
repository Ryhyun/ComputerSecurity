
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
                
                int tempi = col_num % rail ;
                tmp_text[tempi][col_num / rail] = tempString[col_num];
                    
            }
            
        }
        
        
        int i = str_size % rail;
        for( col_num =0 ; col_num < (str_size /rail) ; col_num++){
            for( int k=0 ; k< rail; k++){
                if( k==0 ){
                    c_text[col_num + (str_size/rail )* k ] = tmp_text[k][col_num];
                }
                else{
                    c_text[col_num + (str_size/rail )* k  + i ] = tmp_text[k][col_num];
                }
            }
        }
                
        for( int k = 0; k < i; k++){
            c_text[ str_size/rail  * (k+1) ] = tmp_text[k][col_num + k];
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
        for( col_num=0; col_num< (str_size /rail ); col_num++){
            if( ((tempString[col_num] >= 'a' ) && ( tempString[col_num] <= 'z')) ||((tempString[col_num] >= 'A' ) && (tempString[col_num] <= 'Z' ))){
                int tempi = str_size % rail ;
                
                
                for( int i=0; i<rail ; i++){
                    if( i == 0 ){
                        tmp_text[i][col_num] = tempString[col_num + (str_size /rail)* i  ];
                    }
                    else{
                        tmp_text[i][col_num] = tempString[col_num + (str_size /rail)*i  + tempi];
                    }
                    
                }
    
            }
        }
        int tempi =str_size % rail;
        
        if( tempi != 0 ){
            for(int i=0; i < tempi; i++){
                tmp_text[i][col_num] = tempString[(str_size/rail * ( i+1))];
            }
        }
        

        for( col_num =0 ; col_num <str_size; col_num ++){
        
            int tempi = col_num % rail ;
            d_text[col_num] = tmp_text[tempi][col_num/rail];
            
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
