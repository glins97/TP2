#include "kwic/kwic.hpp"
using namespace std;

void clearConsole(){
    printf("\033c");
}

int handleChoice(int minValue, int maxValue){
    int choice = minValue - 1;
    cin >> choice;
    while (choice < minValue || choice > maxValue) {
        cout << "Escolha invalida. Tente novamente: ";
        cin >> choice;
    }
    return choice;
}

int requestMenuChoice(list<string> headers){
    cout << "Escolha uma opçao abaixo:\n";
    int count = 1;
    int maxValue = headers.size();
    for (string header: headers){
        cout << "\t" << count << ". " << header << ";" << endl;
        count++;
    }

    int choice = handleChoice(1, maxValue);
    return choice;
}

int main(){
    char i;
    char filename[] = "resources/2";
    auto kwic = KWIC();

    cout << "\nQual a forma de INPUT desejada?" << endl;
    int choice = requestMenuChoice(list<string>({"Texto", "CSV", "XML", "SQL", "DBLP"}));
    switch (choice){
        case 1:
            kwic.inputManager = new TextInputManager(filename); 
            break;
        case 2: 
            kwic.inputManager = new CSVInputManager(filename);
            break;
        case 3: 
            kwic.inputManager = new XMLInputManager(filename);
            break;
        case 4: 
            kwic.inputManager = new SQLInputManager();
            break;
        case 5: 
            kwic.inputManager = new DBLPInputManager();
            break;
        default:
            cout << "Not yet implemented. Enter [0] to continue." << endl;
            cin >> i;
            kwic.inputManager = new BaseInputManager();
            break;
    };

    cout << "\nQual a forma de SHIFTING desejada?" << endl;
    choice = requestMenuChoice(list<string>({"Com SW", "Sem SW"}));
    switch (choice){
        case 1:
            kwic.shifterManager = new StopWordsShifterManager(
                list<string>({
                    "o", "a", "os", "as", 
                    "um", "uma", "uns", "umas", 
                    "de", "da", "do", "dos", "das", 
                    " ", ""
                })); 
            break;
        case 2:
            kwic.shifterManager = new NoStopWordsShifterManager(); 
            break;
        default:
            cout << "Not yet implemented. Enter [0] to continue." << endl;
            cin >> i;
            kwic.shifterManager = new ShifterManager(); 
            break;
    };

    cout << "\nQual a forma de SORTING desejada?" << endl;
    choice = requestMenuChoice(list<string>({"Quick", "Crappy"}));
    switch (choice){
        case 1:
            kwic.alphabetizerManager = new QuickAlphabetizer(); 
            break;
        case 2:
            kwic.alphabetizerManager = new CrappyAlphabetizerManager(); 
            break;
        default:
            cout << "Not yet implemented. Enter [0] to continue." << endl;
            cin >> i;
            kwic.alphabetizerManager = new AlphabetizerManager(); 
            break;
    };

    cout << "\nQual a forma de OUTPUT desejada?" << endl;
    choice = requestMenuChoice(list<string>({"Print", "Texto", "CSV", "XML", "HTML"}));
    switch (choice){
        case 1:
            kwic.outputManager = new PrintOutputManager(); 
            break;
        case 2:
            kwic.outputManager = new TextOutputManager(); 
            break;
        case 3:
            kwic.outputManager = new CSVOutputManager(); 
            break;
        case 4:
            kwic.outputManager = new XMLOutputManager(); 
            break;
        case 5:
            kwic.outputManager = new HTMLOutputManager(); 
            break;
        default:
            cout << "Not yet implemented. Enter [0] to continue." << endl;
            cin >> i;
            kwic.outputManager = new BaseOutputManager(); 
            break;
    };

    cout << endl;
    kwic.run();
    cout << "Execução finalizada." << endl;
    return 0;
}