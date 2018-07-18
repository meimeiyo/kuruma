#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Mobil
{
	
	private :
		char jenis [40];
		char noPolisi [10];
		int harga;
	public:
		Mobil();
		Mobil (char jenis [], char noPolisi [], int harga);
		
};

Mobil::Mobil() {
	
	strcpy(Mobil::jenis, "");
	strcpy(Mobil::noPolisi, "");
	Mobil::harga = 0;
	
}

Mobil::Mobil(char jenis[], char noPolisi[], int harga)
{
	strcpy (Mobil::jenis, jenis);
	strcpy (Mobil::noPolisi, noPolisi);
	Mobil::harga = harga;
	
}

int main() {
	Mobil mobilA ("Chevrolette", "AD2235LQ", 500);
	Mobil mobilB ("Daihatsu", "AB3532QZ", 350);
	Mobil mobilC ("Toyota", "AD 1", 1000);
	
	ofstream berkasobjek ("Mobil.data", ios::binary);
	
	berkasobjek.write ((char *) & mobilA, sizeof (mobilA) );
	berkasobjek.write ((char *) & mobilB, sizeof (mobilB) );
	berkasobjek.write ((char *) & mobilC, sizeof (mobilC) );
	
	
		cout << "Data Telah DI Simpan"<< endl;
		
		
}


void Mobil::info () 
{
	cout << "Mobil" << jenis << " " << noPolisi << "Harga" << harga << "Juta" << endl;
	
}

int Main () 
{
	ifstream berkasobjek ("mobil.data", ios::binary);
	
	while ( !berkasobjek.eof() ) 
	{
		Mobil mob;	
		berkasobjek.read ((char *) & mob, sizeof(mob));
		if (berkasobjek)
				mob.info();
	}
	berkasobjek.close();
	
	return 0;
}