#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int jmlBarang[1000], hargaBarang[1000] , subtotal[1000], total, bayar, kembali; 
	string barang[1000];
	char tambah;
	int i = 0;
	
	ofstream file;
	file.open("supermarket.txt",ios::app);
	cout << "|>|====== SUPERMARKET PERSERIKATAN ======|<|" << endl;
	cout << endl;
	do{
		cout << "Nama barang : ";
		cin >> barang[i];
		cout << "Jumlah barang : ";
		cin >> jmlBarang[i];
		cout << "Harga satuan : ";
		cin >> hargaBarang[i];
		subtotal[i] = hargaBarang[i] * jmlBarang[i];
		cout << "Sub Total : " << subtotal[i] << endl;
		cout << endl;
		total += subtotal[i];
		i = i + 1;
		cout << "Apakah ingin menambah barang pembelian (y / t)? = ";
		cin >> tambah;
		cout << endl;
	} while(tambah == 'y');
	cout << "Total        : Rp. " << total << endl;//Menampilkan total harga yang harus dibayar
	cout << "Bayar        : Rp. ";
	cin >> bayar; // Input dari user untuk jumlah yang dibayar
	kembali = bayar - total;
	cout << "Kembali      : Rp. " << kembali <<endl; // Menampilkan uang kembali
	cout << endl;
	
	file << "     |>|======       STRUK BELANJA      ======|<|" << endl;
	file << "     |>|====== SUPERMARKET PERSERIKATAN ======|<|" << endl;
	file << "\n";
	file << "Nama Barang\tQty\tHarga Satuan\t\tSub Total" << endl;
	for(int a = 0; a < i; a++){
		file << barang[a] << "\t" << jmlBarang[a] << "\t\tRp." << hargaBarang[a] << "\t\tRp." << subtotal[a] << endl;
		total = total + subtotal[a];
	}
	file << endl;
	file << "Total        : Rp. " << total << endl;
	file << "Bayar        : Rp. " << bayar << endl;
	file << "Kembali      : Rp. " << kembali << endl;
	
	file.close();
	
	return 0;
}
