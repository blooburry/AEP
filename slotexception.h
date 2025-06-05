#ifndef SLOTEXCEPTION_H
#define SLOTEXCEPTION_H

#include <exception>
#include <string>

using std::exception;
using std::string;

class SlotException: public exception {
private:
    string kaartId;
    string slotPlaats;
    string message;
public:
    SlotException(string id, string plaats): kaartId(id), slotPlaats(plaats) {
        message = "Kaart ID: " + kaartId + " slotPlaats: " + slotPlaats;
    };
    string kaartVanBinnendriger();
    string plaatsVanHetSlot();

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // SLOTEXCEPTION_H
