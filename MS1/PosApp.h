#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_

#include <iostream>

const int MAX_LEN_FILENAME = 255;

namespace sdds {
    class PosApp {

    public:

        // IMPLEMENTED
        void menu();
        PosApp(char * filename);
        void run();

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

