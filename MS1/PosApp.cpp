#include <iostream>
#include <fstream>
#include <cstring>
#include "PosApp.h"
#include "utils.h"

using namespace std;

namespace sdds {

    PosApp::PosApp(const char* filename) :
        m_noOfItems(0)
    {
        if (filename != nullptr && filename[0] != '\0') {
            strncpy(m_filename, filename, 127);
            m_filename[127] = '\0';
            loadRecs();
        }
        else {
            *this = PosApp(nullptr);
        }
    }

    void PosApp::run()
    {
        int selection;

        while ((selection = menu()) != 0) {
            switch (selection) {
            case 1:
                listItems();
                break;
            case 2:
                addItem(false);
                break;
            case 3:
                removeItem(searchItems(readSku("Enter the SKU: ")));
                break;
            case 4:
                updateQty();
                break;
            case 5:
                POS();
                break;
            default:
                cout << "===Invalid Selection, try again===" << endl;
            }
        }

        cout << "Goodbye!" << endl;
        saveRecs();
    }

    int PosApp::menu()
    {
        int selection = -1;
        cout << "The Sene-Store" << endl
            << "1- List items" << endl
            << "2- Add item" << endl
            << "3- Remove item" << endl
            << "4- Stock item" << endl
            << "5- Point of Sale" << endl
            << "0- exit program" << endl
            << "> ";
        selection = readInt();
        return selection;
    }

    void PosApp::deallocateItems()
    {
        for (int i = 0; i < m_noOfItems; i++) {
            delete m_items[i];
        }
        m_noOfItems = 0;
    }

    void PosApp::loadRecs()
    {
        deallocateItems();

        fstream file(m_filename, ios::in);
        if (!file) {
            file.clear();
            file.open(m_filename, ios::out);
            file.close();
        }
        else {
            while (m_noOfItems < MAX_NO_ITEMS && !file.eof()) {
                char itemType = '\0';
                file >> itemType;
                file.ignore();

                if (itemType == 'P') {
                    m_items[m_noOfItems] = new Perishable();
                }
                else {
                    m_items[m_noOfItems] = new NonPerishable();
                }

                if (file.good()) {
                    m_items[m_noOfItems]->load(file);
                    m_noOfItems++;
                }
            }

            file.close();
        }
    }

    void PosApp::saveRecs()
    {
        fstream file(m_filename, ios::out);

        if (file) {
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i]->save(file);
            }

            file.close();
        }
    }

    int PosApp::searchItems(const char* sku) const
    {
        int found = -1;
        for (int i = 0; i < m_noOfItems; i++) {
            if (*m_items[i] == sku) {
                found = i;
                break;
            }
        }
        return found;
    }

    void PosApp::updateQty()
    {
        cout << "Please enter the SKU: ";
        char sku[MAX_SKU_LEN + 1];
        cin.getline(sku, MAX_SKU_LEN);

        int found = searchItems(sku);

        if (found == -1) {
            cout << "Not found!" << endl;
        }
        else {
            m_items[found]->write(cout, false);
            cout << endl << "Please enter the number of purchased items: ";
            int num = readInt();

            *m_items[found] += num;
            saveRecs();
            cout << "Updated!" << endl;
        }
    }

    void PosApp::addItem(bool isPerishable)
    {
        if (m_noOfItems == MAX_NO_ITEMS) {
            cout << "Too many items!" << endl;
        }
        else {
            m_items[m_noOfItems] = isPerishable ? new Perishable() : new NonPerishable();
            m_items[m_noOfItems]->conInput(cin);
            if (cin.fail()) {
                cout << *m_items[m_noOfItems] << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                delete m_items[m_noOfItems];
            }
            else {
                cout << "Item added." << endl;
                m_noOfItems++;
                saveRecs();
            }
        }
    }

    void PosApp::listItems() const
    {
        double total = 0;
        cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl
            << "-----|--------|--------------------|-------|---|----|---------|" << endl;
        for (int i = 0; i < m_noOfItems; i++) {
            cout << right << setw(4) << i + 1 << " | ";
            m_items[i]->write(cout, true);
            cout << endl;
            total += *m_items[i];
        }
        cout << "-----^--------^--------------------^-------^---^----^---------^" << endl
            << "                               Total Asset: $  | " << setw(14) << fixed << setprecision(2) << total << "|" << endl
            << "-----------------------------------------------^--------------^" << endl;
    }

    void PosApp::removeItem(int index)
    {
        if (index == -1) {
            cout << "Not found!" << endl;
        }
        else {
            cout << "The following item will be deleted:" << endl;
            m_items[index]->write(cout, false);
            cout << endl << "Are you sure? (Y)es/(N)o: ";
            char response = cin.get();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (response == 'y' || response == 'Y') {
                delete m_items[index];
                for (int i = index; i < m_noOfItems 1; i++) {
                    m_items[i] = m_items[i + 1];
                }
                m_noOfItems--;
                saveRecs();
                cout << "Deleted!" << endl;
            }
            else {
                cout << "Cancelled!" << endl;
            }
        }
    }
    void PosApp::removeItem()
    {
        cout << "Please enter the SKU: ";
        char sku[MAX_SKU_LEN + 1];
        cin.getline(sku, MAX_SKU_LEN);
        scss
            Copy code
            int found = searchItems(sku);

        removeItem(found);
    }
    void PosApp::run()
    {
        int sel = -1;
        while (sel != 0) {
            sel = menu();
            switch (sel) {
            case 1:
                listItems();
                break;
            case 2:
                addItem(false);
                break;
            case 3:
                removeItem();
                break;
            case 4:
                updateQty();
                break;
            case 5:
                POS();
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "===Invalid Selection, try again===" << endl;
                break;
            }
        }
    }
    int PosApp::menu()
    {
        int selection = -1;
        cout << "The Sene-Store" << endl
            << "1- List items" << endl
            << "2- Add item" << endl
            << "3- Remove item" << endl
            << "4- Stock item" << endl
            << "5- Point of Sale" << endl
            << "0- exit program" << endl
            << "> ";
        selection = readInt(0, 5, "> ", "Invalid Integer, try again: ", "[0<=value<=5]");
        return selection;
    }
