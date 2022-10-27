#include <iostream>
#include <string>
#include <array>
#include <vector>

namespace Kochbuch{

class Zutat {
    public:
    Zutat(std::string name_, double menge_, std::string einheit_)
    : name{name_}, menge{menge_}, einheit{einheit_}{

    }

    std::string name{};
    double menge{};
    std::string einheit{};

};

class Zubereitung_Zeit{
    public:
    Zubereitung_Zeit(std::string name_, double zeit_, std::string einheit_)
    : name{name_}, zeit{zeit_}, einheit{einheit_}{

    }

    std::string name{};
    double zeit{};
    std::string einheit{};

};

class Kaesekuchen{
    public:
    Kaesekuchen(std::vector<Zutat> boden_, std::vector<Zubereitung_Zeit> boden_zeit_)
    : boden{boden_}, boden_zeit{boden_zeit_}
    {

    }

    Kaesekuchen(std::vector<Zutat> boden_, std::vector<Zutat> fuellung_, std::vector<Zubereitung_Zeit> boden_zeit_, std::vector<Zubereitung_Zeit> fuellung_zeit_)
    : boden{boden_}, fuellung{fuellung_}, boden_zeit{boden_zeit_}, fuellung_zeit{fuellung_zeit_}
    {

    }

    void get_info_boden(int anzahl_){
        std::cout << "Benoetigte Zutaten für: " << anzahl_ << " Boden/Boeden." << "\n";
        for(int i = 0 ; i < boden.size()  ; i++){
            std::cout << boden[i].name + " " << anzahl_ * boden[i].menge << " " << boden[i].einheit + " " << "\n";
        }
    }
    void get_info_fuellung(int anzahl_){
        std::cout << "Benötigte Zutaten für: " << anzahl_ << " Fuellung/Fuellungen." << "\n";
        for(int i = 0 ; i < fuellung.size()  ; i++){
            std::cout << fuellung[i].name + " " << anzahl_ * fuellung[i].menge << " " << fuellung[i].einheit + " " << "\n";
        }
    }

    private:
    std::vector<Zutat> boden{};
    std::vector<Zutat> fuellung{};
    std::vector<Zubereitung_Zeit> boden_zeit{};
    std::vector<Zubereitung_Zeit> fuellung_zeit{};

};

}


int main(){
    std::vector<Kochbuch::Zutat> boden{ {"kekse", 100 ,"gramm"},
                                        {"zucker", 100, "gramm"},
                                        {"butter", 100, "gramm"}};

    std::vector<Kochbuch::Zubereitung_Zeit> zeiten_boden{ {"ruhezeit", 20, "min"},
                                                          {"backzeit", 20, "min" }};

    std::vector<Kochbuch::Zutat> fuellung{  {"mehl", 150 , "gramm"},
                                            {"eier", 6 , "stück"},
                                            {"zucker", 200, "gramm"},
                                            {"frischkaese",150,"gramm"},
                                            {"sourcreme",50, "gramm"},
                                            {"schlagsahne",100,"gramm"},
                                            {"zitronensaft",2,"TL"},
                                            {"vanilleextrakt",1,"EL"},
                                            {"butter",2,"EL"}};

    std::vector<Kochbuch::Zubereitung_Zeit> zeiten_fuellung{{"ruhezeit", 12, "stunden"},
                                                            {"backzeit", 30, "minuten"}};


    Kochbuch::Kaesekuchen Classic{boden, fuellung, zeiten_boden, zeiten_fuellung};
    Kochbuch::Kaesekuchen Classic_boden{boden, zeiten_boden};
    Classic.get_info_boden(2);
    Classic.get_info_fuellung(2);
}
