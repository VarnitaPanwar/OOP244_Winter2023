#ifndef SDDS_POSAPP_H
#define SDDS_POSAPP_H



namespace sdds {

    class PosApp {
        char m_filename[128];
        Item* m_items[MAX_NO_ITEMS];
        int m_noOfItems;

        int menu();
        void deallocateItems();
        void loadRecs();
        void saveRecs();
        int searchItems(const char* sku)const;
        void updateQty();

        void addItem(bool isPerishable);
        void listItems()const;
        void removeItem(int index);
        void displayBill()const;
        void truncateBillFile();
        void showBill();
    public:
        PosApp(const char* filename);
        void run();
    };
}

#endif
