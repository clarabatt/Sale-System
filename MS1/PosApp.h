#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_

const int MAX_LEN_FILENAME = 255;

namespace sdds {

    class PosApp {
        int noItems = 6;

    public:
        // IMPLEMENTED
        void menu();
        PosApp(char * filename);
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

