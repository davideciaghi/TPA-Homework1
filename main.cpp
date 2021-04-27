#include <iostream>
#include "libraries/Livella.h"

using namespace std;


int main() {
    

    Livella * mylivella;
    mylivella = livella_init();


    bool check_param = 1;
    bool check_device = 1;

    while (check_param != 0 || check_device != 0) {
        
        check_param = param_control(mylivella);
        check_device = device_control(mylivella);
    }

    
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
