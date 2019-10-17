#include "factory.hpp"

KWIC KWICFactory::request_new_kwic(){
    auto kwic = KWIC();
    auto input_manager = this->_get_input_manager();
    auto output_manager = this->_get_output_manager();
    auto alphabetizer_manager = this->_get_alphabetizer_manager();
    auto shifter_manager = this->_get_shifter_manager();
    return KWIC(
        input_manager, output_manager, alphabetizer_manager, shifter_manager
    );
}

BaseInputManager* KWICFactory::_get_input_manager(){
    cout << "\nQual a forma de INPUT desejada?" << endl;
    int choice = requestMenuChoice(list<string>({"Texto", "CSV", "XML", "SQL", "DBLP"}));
    switch (choice){
        case 1:
            return new TextInputManager("resources/2"); 
        case 2: 
            return new CSVInputManager("resources/2");
        case 3: 
            return new XMLInputManager("resources/2");
        case 4: 
            return new SQLInputManager();
        case 5: 
            return new DBLPInputManager();
    };
    return new BaseInputManager(); 
}

BaseOutputManager* KWICFactory::_get_output_manager(){
    cout << "\nQual a forma de OUTPUT desejada?" << endl;
    int choice = requestMenuChoice(list<string>({"Print", "Texto", "CSV", "XML", "HTML"}));
    switch (choice){
        case 1:
            return new PrintOutputManager(); 
        case 2:
            return new TextOutputManager(); 
        case 3:
            return new CSVOutputManager(); 
        case 4:
            return new XMLOutputManager(); 
        case 5:
            return new HTMLOutputManager(); 
    };
    return new BaseOutputManager(); 
}

BaseAlphabetizerManager* KWICFactory::_get_alphabetizer_manager(){
    cout << "\nQual a forma de SORTING desejada?" << endl;
    int choice = requestMenuChoice(list<string>({"Quick", "Crappy"}));
    switch (choice){
        case 1:
            return new QuickAlphabetizer(); 
        case 2:
            return new CrappyAlphabetizerManager(); 
    };
    return new BaseAlphabetizerManager();
}

BaseShifterManager* KWICFactory::_get_shifter_manager(){
    cout << "\nQual a forma de SHIFTING desejada?" << endl;
    int choice = requestMenuChoice(list<string>({"Com SW", "Sem SW"}));
    switch (choice){
        case 1:
            return new StopWordsShifterManager(
                list<string>({
                    "o", "a", "os", "as", "à", "ao", 
                    "um", "uma", "uns", "umas", 
                    "em", "no", "na", "nos", "nas",
                    "de", "da", "do", "dos", "das", 
                    " ", ""
                })); 
        case 2:
            return new NoStopWordsShifterManager(); 
    };
    return new BaseShifterManager();
}

void KWICFactory::clearConsole(){
    printf("\033c");
}

int KWICFactory::handleChoice(int minValue, int maxValue){
    int choice = minValue - 1;
    cin >> choice;
    while (choice < minValue || choice > maxValue) {
        cout << "Escolha invalida. Tente novamente: ";
        cin >> choice;
    }
    return choice;
}

int KWICFactory::requestMenuChoice(list<string> headers){
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