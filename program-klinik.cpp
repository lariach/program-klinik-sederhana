#include <iostream>
#include <string>


struct DataDokter{
    std::string kodeDokter, namaDokter, dokterApa, biaya;
    DataDokter *prev;
    DataDokter *next;
};
DataDokter *head, *tail, *cur, *newNode, *del;

struct DataObat{
    std::string kodeObat, namaObat, hargaObat;
    DataObat *sblm;
    DataObat *stlh;
};
DataObat *pala, *ekor, *now, *baruNode, *hps;

// Create DLL Data Dokter
void createDLLDataDokter(std::string data[2]){
    head = new DataDokter;
    head->kodeDokter = data[0];
    head->namaDokter = data[1];
    head->dokterApa = data[2];
    head->biaya = data[3];
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

// Print DLL Data Dokter
void printDLLDataDokter(){
    if(head == NULL){
        std::cout << "Data dokter tidak tersedia";
    }else{
        cur = head;
        while(cur != NULL){
            //print
            std::cout << "Kode   : " << cur->kodeDokter << std::endl;
            std::cout << "Nama   : " << cur->namaDokter << std::endl;
            std::cout << "Bagian : " << cur->dokterApa <<  std::endl;
            std::cout << "Biaya  : " << cur->biaya << "\n" << std::endl;
            //step
            cur = cur->next;
        }
    }
}

// Create DLL Data Obat
void createDLLDataObat(std::string data[5]){
    pala = new DataObat;
    pala->kodeObat = data[0];
    pala->namaObat = data[1];
    pala->hargaObat = data[2];
    pala->sblm = NULL;
    pala->stlh = NULL;
    ekor = pala;
}

// Print DLL Data Obat
void printDLLDataObat(){
    if(pala == NULL){
        std::cout << "Data obat tidak tersedia";
    }else{
        now = pala;
        while(now != NULL){
            //print
            std::cout << "Kode  : " << now->kodeObat  << std::endl;
            std::cout << "Nama  : " << now->namaObat  << std::endl;
            std::cout << "Harga : " << now->hargaObat << "\n" << std::endl;
            //step
            now = now->stlh;
        }
    }
}

//=================DR001=================//
// Antrian DR001
int maksimalAntrianDR001 = 5, front = 0, back = 0;

//ruang antrian DR001
std::string antrianDR001[5];

//isFull 001
bool isFull001(){
    if(back == maksimalAntrianDR001){
        return true;
    }else{
        return false;
    }
}

//isEmpty 001
bool isEmpty001(){
    if (back == 0){
        return true;
    }else{
        return false;
    }
}

//enqueue 001 (penambahan data/antrian)
void enqueue001(std::string pasien001){
    if (isFull001()){
        std::cout << "Maaf, Antrian penuh!" << std::endl;
    }else{
        //cek apakah antrian kosong atau tidak
        if (isEmpty001()){
            //kalau antrian kosong
            antrianDR001[0] = pasien001;
            front++;
            back++;
        }else{
            //kalau antrian tidak kosong
            antrianDR001[back] = pasien001;
            back++;
        }
    }   
}

// Dequeue 001
void dequeue001(){
    if (isEmpty001()){
        std::cout << "Antrian kosong" << std::endl;
    }else{
        for (int i=0; i < back; i++){
            antrianDR001[1] = antrianDR001[i+1];
            back++;
        }
    }
}

//display 001
void view001(){
    std::cout << "Data Antrian Dokter Umum : " << std::endl;
    for (int i=0; i < maksimalAntrianDR001; i++){

        //cek apakah antrian kosong atau tidak
        if (antrianDR001[i] != ""){
            //kalau tidak kosong
            std:: cout << i+1 << ". " << antrianDR001[i] << std::endl;
        }else{
            //kalau kosong
            std:: cout << i+1 << ". (tersedia)" << std::endl;
        }

    }
}

//print invoice 001
void printInvoice001(std::string pasien001, std::string keluhan001){
    std::cout << "Anda mendaftar untuk : " << std::endl;
    std::string Dok1[4] = {"DR001", "Hendrawan Prasetyo", "Dokter Umum", "Rp50000"};
    createDLLDataDokter(Dok1);
    printDLLDataDokter();

    std::cout << "\nPendaftar" << std::endl;
    std::cout << "Nama    : " << pasien001 << std::endl;
    std::cout << "Keluhan : " << keluhan001 << "\n" << std::endl;
    
    view001();
    std::cout << "Terima Kasih" << std::endl;
}


//=================DR002=================//

// Antrian DR002
int maksimalAntrianDR002 = 3, dpn = 0, blkng = 0;

//ruang antrian DR002
std::string antrianDR002[3];

//isFull 002
bool isFull002(){
    if(blkng == maksimalAntrianDR002){
        return true;
    }else{
        return false;
    }
}

//isEmpty 002
bool isEmpty002(){
    if (blkng == 0){
        return true;
    }else{
        return false;
    }
}

//enqueue 002 (penambahan data/antrian)
void enqueue002(std::string pasien002){
    if (isFull002()){
        std::cout << "Maaf, Antrian penuh!" << std::endl;
    }else{
        //cek apakah antrian kosong atau tidak
        if (isEmpty002()){
            //kalau antrian kosong
            antrianDR002[0] = pasien002;
            dpn++;
            blkng++;
        }else{
            //kalau antrian tidak kosong
            antrianDR002[blkng] = pasien002;
            blkng++;
        }
    }   
}

// Dequeue 002
void dequeue002(){
    if (isEmpty002()){
        std::cout << "Antrian kosong" << std::endl;
    }else{
        for (int j=0; j < blkng; j++){
            antrianDR002[1] = antrianDR002[j+1];
            blkng++;
        }
    }
}

//display 002
void view002(){
    std::cout << "Data Antrian Dokter Gigi : " << std::endl;
    for (int j=0; j < maksimalAntrianDR002; j++){

        //cek apakah antrian kosong atau tidak
        if (antrianDR002[j] != ""){
            //kalau tidak kosong
            std:: cout << j+1 << ". " << antrianDR002[j] << std::endl;
        }else{
            //kalau kosong
            std:: cout << j+1 << ". (tersedia)" << std::endl;
        }

    }
}

//print invoice 002
void printInvoice002(std::string pasien002, std::string keluhan002){
    std::cout << "Anda mendaftar untuk : " << std::endl;
    std::string Dok2[4] = {"DR002", "Kurniawan Aji", "Dokter Gigi", "Rp75000"};
    createDLLDataDokter(Dok2);
    printDLLDataDokter();

    std::cout << "\nPendaftar" << std::endl;
    std::cout << "Nama    : " << pasien002 << std::endl;
    std::cout << "Keluhan : " << keluhan002 << "\n" << std::endl;
    
    view002();
    std::cout << "Terima Kasih" << std::endl;
}

//=================Obat=================//

// Antrian Obat
int maksimalAntrianObat = 10, hareup = 0, tukang = 0;

//ruang antrian Obat
std::string antrianObat[10];

//isFull Obat
bool isFullObat(){
    if(tukang == maksimalAntrianObat){
        return true;
    }else{
        return false;
    }
}

//isEmpty Obat
bool isEmptyObat(){
    if (tukang == 0){
        return true;
    }else{
        return false;
    }
}

//enqueue Obat (penambahan data/antrian)
void enqueueObat(std::string cust){
    if (isFullObat()){
        std::cout << "Maaf, Antrian penuh!" << std::endl;
    }else{
        //cek apakah antrian kosong atau tidak
        if (isEmptyObat()){
            //kalau antrian kosong
            antrianObat[0] = cust;
            hareup++;
            tukang++;
        }else{
            //kalau antrian tidak kosong
            antrianObat[tukang] = cust;
            tukang++;
        }
    }   
}

// Dequeue Obat
void dequeueObat(){
    if (isEmptyObat()){
        std::cout << "Antrian kosong" << std::endl;
    }else{
        for (int k=0; k < tukang; k++){
            antrianObat[1] = antrianObat[k+1];
            tukang++;
        }
    }
}

//display Obat
void viewObat(){
    std::cout << "\nData Antrian Obat : " << std::endl;
    for (int k=0; k < maksimalAntrianObat; k++){

        //cek apakah antrian kosong atau tidak
        if (antrianObat[k] != ""){
            //kalau tidak kosong
            std:: cout << k+1 << ". " << antrianObat[k] << std::endl;
        }else{
            //kalau kosong
            std:: cout << k+1 << ". (tersedia)" << std::endl;
        }

    }
} 

//print invoice Obat
void printInvoiceObat(std::string cust){

    std::cout << "\nPembeli" << std::endl;
    std::cout << "Nama   : " << cust << std::endl;

}

//invoice antrian

int main(){
    int pilAnt;
    std::string pilDok, pilMed, pasien001, keluhan001, pasien002, keluhan002, cust;


        start:
        system("cls");
        std::cout << std::endl;
        std::cout <<" ============================" << std::endl;
        std::cout <<" |   KLINIK KOMEDI TERUS    |" << std::endl;
        std::cout <<" ============================" << std::endl;
        std::cout <<" | 1. Antrian Dokter        |" << std::endl;
        std::cout <<" | 2. Antrian Obat          |" << std::endl;
        std::cout <<" ============================" << std::endl;        std::cout <<" Masukan Pilihan : "; std::cin >> pilAnt;

        switch(pilAnt){ //pilAnt = pilihan antrian
            case 1: {system("cls");
                std::cout << "Pilihan Dokter" << std::endl;

                std::string Dok1[4] = {"DR001", "Hendrawan Prasetyo", "Dokter Umum", "Rp50000"};
                createDLLDataDokter(Dok1);
                printDLLDataDokter();

                std::string Dok2[4] = {"DR002", "Kurniawan Aji", "Dokter Gigi", "Rp75000"};
                createDLLDataDokter(Dok2);
                printDLLDataDokter();

                std::cout << "Masukkan kode dokter yang dipilih!" << std::endl;
                std::cout << "Masukkan pilihan: "; std::cin >> pilDok;
                
                    if(pilDok == "DR001"){
                        system("cls");
                        view001();
                        std::cin.ignore();
                        std::cout << "\n\nNama Pasien : "; std::getline(std::cin, pasien001);
                        enqueue001(pasien001);
                        std::cout << "\nKeluhan : "; std::getline(std::cin, keluhan001);
                        system("cls");
                        
                        printInvoice001(pasien001, keluhan001);

                        system("pause");
                        goto start;
                        
                    }else if(pilDok == "DR002"){
                        system("cls");
                        view002();
                        std::cin.ignore();
                        std::cout << "\n\nNama Pasien : "; std::getline(std::cin, pasien002);
                        enqueue002(pasien002);
                        std::cout << "\nKeluhan : "; std::getline(std::cin, keluhan002);
                        system("cls");
                        
                        printInvoice002(pasien002, keluhan002);

                        system("pause");
                        goto start;
                    }else{
                        system("cls");
                        std::cout << "Kode dokter yang anda masukan salah!";
                    }
                
            }break;
            case 2: {system("cls");

                viewObat();
                std::cin.ignore();
                std::cout << "\n\nNama Pelanggan : "; std::getline(std::cin, cust);
                enqueueObat(cust);
                system("cls");

                if(isFullObat()){
                    std::cout << "Maaf, Antrian Penuh" << std::endl;
                    system("pause");
                    goto start;
                }else{
                    pilihObat:
                    std::cout << "Pilihan Obat" << std::endl;

                    std::string Med1[3] = {"MDCN001", "Paracetamol", "Rp5000"};
                    createDLLDataObat(Med1);
                    printDLLDataObat();

                    std::string Med2[3] = {"MDCN002", "Ibuprofen", "Rp8000"};
                    createDLLDataObat(Med2);
                    printDLLDataObat();

                    std::string Med3[3] = {"MDCN003", "Piroxicam", "Rp10000"};
                    createDLLDataObat(Med3);
                    printDLLDataObat();

                    std::string Med4[3] = {"MDCN004", "Vitamin C", "Rp12000"};
                    createDLLDataObat(Med4);
                    printDLLDataObat();

                    std::string Med5[3] = {"MDCN005", "Antibiotik", "Rp15000"};
                    createDLLDataObat(Med5);
                    printDLLDataObat();

                    
                    std::cout << "Masukkan kode Obat yang dipilih!" << std::endl;
                    std::cout << "Masukkan pilihan: "; std::cin >> pilMed;

                    if(pilMed == "MDCN001"){
                        system("cls");
                        std::cout << "Pesan Obat:" << std::endl;
                        std::string Med1[3] = {"MDCN001", "Paracetamol", "Rp5000"};
                        createDLLDataObat(Med1);
                        printDLLDataObat();

                        printInvoiceObat(cust);
                        viewObat();
                        std::cout << "Terima Kasih" << std::endl;
                        system("pause");
                        goto start;

                    }else if(pilMed == "MDCN002"){
                        system("cls");
                        std::cout << "Pesan Obat:" << std::endl;
                        std::string Med2[3] = {"MDCN002", "Ibuprofen", "Rp8000"};
                        createDLLDataObat(Med2);
                        printDLLDataObat();

                        printInvoiceObat(cust);
                        viewObat();
                        std::cout << "Terima Kasih" << std::endl;
                        system("pause");
                        goto start;
                        
                    }else if(pilMed == "MDCN003"){
                        system("cls");
                        std::cout << "Pesan Obat:" << std::endl;
                        std::string Med3[3] = {"MDCN003", "Piroxicam", "Rp10000"};
                        createDLLDataObat(Med3);
                        printDLLDataObat();

                        printInvoiceObat(cust);
                        viewObat();
                        std::cout << "Terima Kasih" << std::endl;
                        system("pause");
                        goto start;

                    }else if(pilMed == "MDCN004"){
                        system("cls");
                        std::cout << "Pesan Obat:" << std::endl;
                        std::string Med4[3] = {"MDCN004", "Vitamin C", "Rp12000"};
                        createDLLDataObat(Med4);
                        printDLLDataObat();

                        printInvoiceObat(cust);
                        viewObat();
                        std::cout << "Terima Kasih" << std::endl;
                        system("pause");
                        goto start;

                    }else if(pilMed == "MDCN005"){
                        system("cls");
                        std::cout << "Pesan Obat:" << std::endl;
                        std::string Med5[3] = {"MDCN005", "Antibiotik", "Rp15000"};
                        createDLLDataObat(Med5);
                        printDLLDataObat();

                        printInvoiceObat(cust);
                        viewObat();
                        std::cout << "Terima Kasih" << std::endl;
                        system("pause");
                        goto start;

                    }else{
                        system("cls");
                        std::cout << "Kode Obat yang Anda Masukkan Salah!" << std::endl;
                        system("pause");
                        goto pilihObat;
                    }

                } 
            break;
            }
            default: {system("cls");
                std::cout << "Maaf, Pilihan yang anda pilih tidak tersedia!" << std::endl;
                system("pause");
                goto start;
            }
        }
    
} 
