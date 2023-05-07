#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Car {
private:
	string marca;
	string model;
	string culoare;
	int an;
	bool disponibil;
public:
	Car(string Marca, string Model, string Culoare, int An, bool Disponibil)
	{
		marca = Marca;
		model = Model;
		culoare = Culoare;
		an = An;
		disponibil = Disponibil;
	}

	void setMarca(string marca)
	{
		this->marca = marca;
	}
	void setModel(string model)
	{
		this->model = model;
	}
	void setCuloare(string culoare)
	{
		this->culoare = culoare;
	}
	void setAn(int an)
	{
		this->an = an;
	}
	void setDisponibil(bool disponibil)
	{
		this->disponibil = disponibil;
	}
	string getMarca()const {
		return marca;
	}
	string getModel() const {
		return model;
	}
	string getCuloare() const {
		return culoare;
	}
	int getAn() const {
		return an;
	}
	bool getDisponibil()const {
		return disponibil;
	}

};

class carRentalSystem {
private:
	vector<Car> flota;
public:
	carRentalSystem()
	{
		flota.push_back(Car("Mercedes-Benz", "C Class", "White", 2017, true));
		flota.push_back(Car("Toyota", "Corolla", "Gray", 2020, true));
		flota.push_back(Car("Renault", "Talisman", "Blue", 2020, true));
		flota.push_back(Car("BMW", "3 Series", "White", 2017, true));
		flota.push_back(Car("Volkswagen", "Passat-CC", "Black", 2016, true));
		flota.push_back(Car("Ford", "Mondeo", "White ", 2022, true));
	}
	void displayAvaliableCars()
	{
		cout << "Masini disponibile: " << endl;
		for (int i = 0; i <= flota.size() - 1; i++)
		{
		
			if (flota[i].getDisponibil()) 
			{
				cout <<i+1<<". "<< flota[i].getMarca() << " " << flota[i].getModel() << " " << flota[i].getAn() << endl;
			}
		}
	}
	void rentCar(int carIndex)
	{
		if (carIndex >= 1 && carIndex <= flota.size() && flota[carIndex - 1].getDisponibil())
		{
			flota[carIndex - 1].setDisponibil(false);
			cout << "Ati inchiriat: " << flota[carIndex - 1].getMarca() << " " << flota[carIndex - 1].getModel() << " " << flota[carIndex - 1].getAn() << endl;
		}
		else
		{
			cout << "Selectie invalida/Masina nu este disponibila!" << endl;
		}
	}
	void returnCar(int carIndex)
	{
		if (carIndex >= 1 && carIndex <= flota.size() && !flota[carIndex - 1].getDisponibil())
		{
			flota[carIndex - 1].setDisponibil(true);
			cout<<"Ati returnat: " << flota[carIndex - 1].getMarca() << " " << flota[carIndex - 1].getModel() << " " << flota[carIndex - 1].getAn() << endl;
		}
		else
		{
			cout << "Selectie invalida/Masina este deja returnata!" << endl;
		}
	}
};


int main()
{
	carRentalSystem ob;
	int optiune;
	
	do {
		cout << endl;
		cout << "===Inchiriere masini===" << endl;
		cout << "1.Vizualizare masini disponibile" << endl;
		cout << "2.Inchiriere masina" << endl;
		cout << "3.Returnare masina" << endl;
		cout << "4. Parasire meniu" << endl;
		cout << "Alege optiunea: " << endl;
		cin >> optiune;
		system("cls");
		switch (optiune)
		{
		case 1: 
		    ob.displayAvaliableCars();
			break;
		case 2:
			int carIndex;
			ob.displayAvaliableCars();
			cout << "Alege indexul masinii dorite: ";
			cin >> carIndex;
			ob.rentCar(carIndex);
			break;
		case 3:
			int carIndex1;
			ob.displayAvaliableCars();
			cout << "Alege indexul masinii de returnat: ";
			cin >> carIndex1;
			ob.returnCar(carIndex1);
			break;
		case 4:
			cout << "Se inchide programul...." << endl;
			break;
		default:
			cout << "Alegere invalida, selectati din nou!" << endl;
			break;

		}
	} while (optiune != 4);
   
}

