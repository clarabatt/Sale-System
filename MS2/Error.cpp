#include <iostream>
#include <cstring>
#include "Error.h"

using namespace std;

namespace sdds {

    Error::Error(){
        error_message = nullptr;
    };

    Error::Error(const char* msg){
        if (msg != nullptr and msg[0] != '\0'){
            error_message = new char [strlen(msg)+1];
            strcpy(error_message, msg);
        }
    };
    Error::Error(Error& copyError){
        if (copyError.error_message != nullptr and copyError.error_message[0] != '\0'){
            error_message = new char [strlen(copyError.error_message)+1];
            strcpy(error_message, copyError.error_message);
        }
    };
    Error::~Error(){
        delete [] error_message;
        error_message = nullptr;
    };
    Error& Error::operator=(Error& copyError){
        if (copyError.error_message != nullptr and copyError.error_message[0] != '\0'){
            error_message = new char [strlen(copyError.error_message)+1];
            strcpy(error_message, copyError.error_message);
        }
        return *this;
    };

    Error& Error::clear(){
        delete [] error_message;
        error_message = nullptr;
        return *this;
    };

    Error::operator bool() const{
        return error_message != nullptr and error_message[0] != '\0';
    };

    char* Error::getMessage() const{
        return error_message;
    };

    Error& Error::operator=(const char* msg){
        if (msg == nullptr || *msg == '\0') {
            clear();
        } else {
            if (error_message != nullptr) {
                delete[] error_message;
            }
            int len = strlen(msg);
            error_message = new char[len + 1];
            strcpy(error_message, msg);
        }
        return *this;
    };

    ostream& operator<<(ostream& ostr, const Error& right){
        if (right) {
            ostr << right.getMessage();
        }
        return ostr;
    };

}