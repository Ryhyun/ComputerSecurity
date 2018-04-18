#include <iostream>

using namespace std;

string Gronsfeld(string tempString, string tempKey, int select){
    
    int str_size = (int)tempString.length();
    int key_size = (int)tempKey.length();
    int j=0 ;
    
    for(int i=0; i< str_size; i++){
        j =  i % key_size;
        // 암호화
        if( select == 1){
            if( (tempString[i] >= 'a' ) && ( tempString[i] <= 'z')){
                tempString[i] -='a';
                tempKey[j] -= '0';
                
                if( tempString[i] + tempKey[j] < 0 ){
                    tempString[i] +=26;
                }
                tempString[i] = (tempString[i] + tempKey[j]) % 26;
                tempString[i] += 'a';
                tempKey[j] += '0';
            }
        
            else if( (tempString[i] >= 'A' ) && (tempString[i] <= 'Z' ) ){
                
                tempString[i] -='A';
                tempKey[j] -= '0';
                
                if( tempString[i] + tempKey[j] < 0 ){
                    tempString[i] +=26;
                }
                tempString[i] = (tempString[i] + tempKey[j]) % 26;
                tempString[i] += 'A';
                tempKey[j] += '0';
            }
            
        }
        //복호화
        else {
            if( (tempString[i] >= 'a' ) && ( tempString[i] <= 'z')){
                tempString[i] -='a';
                tempKey[j] -= '0';
                
                if( tempString[i] + tempKey[j] < 0 ){
                    tempString[i] +=26;
                }
                tempString[i] = (tempString[i] - tempKey[j]) % 26;
                tempString[i] += 'a';
                tempKey[j] += '0';
            }
            else if( (tempString[i] >= 'A' ) && (tempString[i] <= 'Z' ) ){

                tempString[i] -='A';
                tempKey[j] -= '0';
                    
                if( tempString[i] + tempKey[j] < 0 ){
                    tempString[i] +=26;
                }
                tempString[i] = (tempString[i] - tempKey[j]) % 26;
                tempString[i] += 'A';
                tempKey[j] += '0';
                
            }

        }
    
    }
    
    if( select ==1 ){
        cout<< "encryption : " << tempString<<endl;
    }
    else{
        cout<< "decryption : " << tempString<<endl;
    }
    
    return tempString;
}


int main(int argc, const char * argv[]) {
    
    string plainText;
    string cipherText;
    string decrytionText;
    
    string key;
    
    getline( cin, plainText);
    
    cout<< "key 입력해주세요( 10자 ) : "<<endl;
    cin>> key;
    
    
    cipherText= Gronsfeld(plainText,key,1);
    decrytionText = Gronsfeld(cipherText,key,0);
    
    
    
    
    
    
    

    
    
    return 0;
}
