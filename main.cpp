#include <iostream>
#include "libraries/Livella.h"

using namespace std;


int main() {
    

    Livella * mylivella;

    // mylivella = livella_from_console();
    mylivella = livella_init(100,500,400,150,50,20,30,70,30,500);
    
    param_control(mylivella);

    device_control(mylivella);

    cout << "Informazioni su pistoni e piastra:" << endl << endl;
    info_parti(mylivella);


    string NameFile = "";
    char with_measures;
    cout << "Inserire il nome del file .svg che verrà creato: ";
    cin >> NameFile;
    cout << "Includere le misure nel file .svg ?  Y/n: ";
    cin >> with_measures;

    livella_to_svg(mylivella, "../" + NameFile, with_measures);


    livella_destroy(mylivella);

    return EXIT_SUCCESS;

}
