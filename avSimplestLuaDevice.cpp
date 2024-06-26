#include "DCS/DCS.h"

class avSimplestLuaDevice : public cockpit::avLuaDevice {

};

class avSimplestRWR : public cockpit::avRWR {
};

class ccSimplestIndicator : public cockpit::ccIndicator {

};

extern "C" __declspec(dllexport) void ed_module_initialize(void) {
    static bool first_time = true;
    if (first_time) {
        first_time = false;
        static WorldFactory<avSimplestLuaDevice> avSimplestLuaDevice_factory;
        static WorldFactory<avSimplestRWR> avSimplestRWR_factory;
        static WorldFactory<ccSimplestIndicator> ccSimplestIndicator_factory;
    }
}
