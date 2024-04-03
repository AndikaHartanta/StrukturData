#include <iostream>
#include <string>

using namespace std;

// Struktur data untuk menyimpan pesanan
struct Order {
    string itemName;
    int quantity;
    double price;
    Order* next;
};

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Nasi Goreng - Rp. 15000" << endl;
    cout << "2. Mie Ayam - Rp. 12000" << endl;
    cout << "3. Es Teh - Rp. 5000" << endl;
    cout << "4. Selesai Memesan" << endl;
}

// Fungsi untuk menambahkan pesanan
void addOrder(Order*& head, int& itemCount) {
    if (itemCount >= 100) {
        cout << "Maaf, pesanan sudah mencapai batas maksimal." << endl;
        return;
    }

    Order* newOrder = new Order();
    int choice;

    displayMenu();
    cout << "Masukkan pilihan (1-3) atau 4 untuk selesai: ";
    cin >> choice;

    switch (choice) {
        case 1:
            newOrder->itemName = "Nasi Goreng";
            newOrder->price = 15000;
            break;
        case 2:
            newOrder->itemName = "Mie Ayam";
            newOrder->price = 12000;
            break;
        case 3:
            newOrder->itemName = "Es Teh";
            newOrder->price = 5000;
            break;
        case 4:
            cout << "Selesai memesan." << endl;
            delete newOrder;
            return;
        default:
            cout << "Pilihan tidak valid." << endl;
            delete newOrder;
            return;
    }

    cout << "Masukkan jumlah pesanan: ";
    cin >> newOrder->quantity;

    newOrder->next = head;
    head = newOrder;
    itemCount++;

    cout << "Pesanan ditambahkan." << endl;
}

// Fungsi untuk menampilkan semua pesanan
void displayOrders(const Order* head) {
    if (!head) {
        cout << "Belum ada pesanan." << endl;
        return;
    }

    const Order* current = head;

    cout << "Daftar Pesanan:" << endl;
    cout << "------------------------------------------" << endl;
    cout << "Nama Item\t\tJumlah\t\tHarga" << endl;
    cout << "------------------------------------------" << endl;
    while (current) {
        cout << current->itemName << "\t\t\t" << current->quantity << "\t\t" << current->price * current->quantity << endl;
        current = current->next;
    }
    cout << "------------------------------------------" << endl;
}

// Fungsi untuk menghapus semua pesanan
void clearOrders(Order*& head, int& itemCount) {
    while (head) {
        Order* temp = head;
        head = head->next;
        delete temp;
    }
    itemCount = 0;
    cout << "Semua pesanan telah dihapus." << endl;
}


int main() {
    Order* orders = nullptr;
    int itemCount = 0;
    char choice;

    do {
        cout << "\n1. Tambah Pesanan" << endl;
        cout << "2. Tampilkan Pesanan" << endl;
        cout << "3. Hapus Semua Pesanan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addOrder(orders, itemCount);
                break;
            case '2':
                displayOrders(orders);
                break;
            case '3':
                clearOrders(orders, itemCount);
                break;
            case '4':
                cout << "Keluar..." << endl;
                clearOrders(orders, itemCount);
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != '4');

    return 0;
}

