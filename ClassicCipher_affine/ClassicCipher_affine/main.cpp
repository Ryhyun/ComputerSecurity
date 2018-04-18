#include <iostream>

using namespace std;

string encryption(string tempString, int tempKey1, int tempKey2){
    
    int str_size = (int)tempString.length();
    for( int i=0; i< str_size; i++){
        
        if( (tempString[i] >= 'A' ) && (tempString[i] <= 'Z' ) ){
            tempString[i] = tempString[i] - 'A' ;
            if(  ( tempString[i] + tempKey1) < 0 ){
                tempString[i] = tempString[i] + 26;
            }
            
            tempString[i] = ( tempString[i]* tempKey1 + tempKey2 ) % 26;
            tempString[i] = tempString[i] + 'A' ;
            
        }
        else if( (tempString[i] >= 'a' ) && ( tempString[i] <= 'z')){
            tempString[i] = tempString[i] -'a';
            if( (tempString[i] + tempKey1) < 0 ){
                tempString[i] = tempString[i] + 26;
            }
            
            tempString[i] = (tempString[i]* tempKey1 + tempKey2) % 26;
            tempString[i] = tempString[i] + 'a';
        }
    }
    return tempString;
    
}

string decryption(string tempString, int tempKey1, int tempKey2){
    
    int str_size = (int)tempString.length();
    for( int i=0; i< str_size; i++){
        
        if( (tempString[i] >= 'A' ) && (tempString[i] <= 'Z' ) ){
            tempString[i] = tempString[i] - 'A' ;
            if(  ( tempString[i] + tempKey1) < 0 ){
                tempString[i] = tempString[i] + 26;
            }
            
            tempString[i] = ( (tempString[i]- tempKey2) / tempKey1 ) % 26;
            tempString[i] = tempString[i] + 'A' ;
            
        }
        else if( (tempString[i] >= 'a' ) && ( tempString[i] <= 'z')){
            tempString[i] = tempString[i] -'a';
            if( (tempString[i] + tempKey1) < 0 ){
                tempString[i] = tempString[i] + 26;
            }
            
            tempString[i] =( (tempString[i]- tempKey2) / tempKey1 ) % 26;
            tempString[i] = tempString[i] + 'a';
        }
    }
    return tempString;
    
}



int main(int argc, const char * argv[]) {

    string plainText;
    string cipherText;
    string decrytionText;
    int key1,key2;
    getline( cin, plainText);
    
    cin>> key1 >> key2;
    
    cipherText= encryption( plainText, key1, key2);
    
    cout << cipherText<<endl;
    
    decrytionText = decryption( cipherText, key1, key2);
    
    cout<< decrytionText<<endl;
    
    
    
    
    
    
    return 0;
}
