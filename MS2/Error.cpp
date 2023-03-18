#include <iostream>
#include "Error.h"

using namespace std;

namespace sdds {

    Error::Error(const char* msg){
        if (msg != nullptr and msg[0] != '\0'){
            error_message = new char [len(msg+1)];
            strcpy(error_message, msg);
        }
    };
    Error::Error(Error& copyError){
        if (copyError.error_message != nullptr and copyError.error_message[0] != '\0'){
            error_message = new char [len(msg+1)];
            strcpy(error_message, copyError.error_message);
            delete [] copyError.error_message;
            copyError.error_message = nullptr;
        }
    };
    Error::~Error(){
        delete [] error_message;
        error_message = nullptr;
    };
    Error& Error::operator=(Error& copyError){
        if (copyError.error_message != nullptr and copyError.error_message[0] != '\0'){
            error_message = new char [len(msg+1)];
            strcpy(error_message, copyError.error_message);
            delete [] copyError.error_message;
            copyError.error_message = nullptr;
        }
    };

}