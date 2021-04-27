#include <iostream>
#include "libraries/Livella.h"

using namespace std;

int main() {
    
    Livella * mylivella;
    

    // Funzione di inserimento dei parametri
    mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);


    bool check_param = 1;
    bool check_device = 1;

    while (check_param != 0 || check_device != 0) {
        // Funzione che controlla se i parametri sono positivi
        check_param = param_control(mylivella);
        // Funzione che controlla se i parametri sono consistenti tra loro
        check_device = device_control(mylivella);
    }

    
    // Informazioni sulle parti del meccanismo
    cout << "Informazioni su pistoni e piastra:" << endl;
    info_parti(mylivella);


    // Creazione del file .svg
    string NameFile = "";
    cout << "Inserire il nome del file .svg che verrà creato: ";
    cin >> NameFile;

    char with_measures;
    cout << "Includere le misure nel file .svg ?  Y/n: ";
    cin >> with_measures;

    livella_to_svg(mylivella, "../" + NameFile, with_measures);


    // Distruggi istanze della struct Livella
    livella_destroy(mylivella);

    return EXIT_SUCCESS;

}
