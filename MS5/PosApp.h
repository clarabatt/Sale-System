// *****************************************************************************
// Author  : Clara Verena Brito Battesini
// Student ID(s)#: 143430213
// Email        : cverena-brito-battes@senecacollege.ca
// 12/03/2023
//
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
// *****************************************************************************

#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_

const int MAX_LEN_FILENAME = 255;

namespace sdds {

    class PosApp {
        char filename[MAX_LEN_FILENAME];

    public:
        // IMPLEMENTED
        int menu();
        PosApp(const char filename[]);
        void run();

        // Deleting copy constructor and assignment operators
        PosApp(const PosApp&) = delete;
        PosApp& operator=(const PosApp&) = delete;

        // MOCK
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs();
        void loadRecs();

    };

}
#endif // !SDDS_POSAPP_H_

