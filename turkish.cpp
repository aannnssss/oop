#include "turkish.hpp"

std::string translationIntoTurkish(int n) {
    int p = n;
    std::string result = "";
    if (p/10!=0) {   
        switch (p/10) {
            case 1: {result = "on"; break;}
            case 2: {result = "yirmi"; break;}
            case 3: {result = "otuz"; break;}
            case 4: {result = "kırk"; break;}
            case 5: {result = "elli"; break;}
            case 6: {result = "altmış"; break;}
            case 7: {result = "yetmiş"; break;}
            case 8: {result = "seksen"; break;}
            case 9: {result = "doksan"; break;}
        }
        p%=10;
        if (p) result +=" ";
    }
    switch (p) {
        case 0: {if (n/10!=0) break; else {result = "sifir"; break;}}
        case 1: {result += "bir"; break;}
        case 2: {result += "iki"; break;}
        case 3: {result += "üç"; break;}
        case 4: {result += "dört"; break;}
        case 5: {result += "beş"; break;}
        case 6: {result += "altı"; break;}
        case 7: {result += "yedi"; break;}
        case 8: {result += "sekiz"; break;}
        case 9: {result += "dokuz"; break;}
    }
    return result;
}