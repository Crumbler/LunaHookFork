#ifndef __LUNA_ENGINE_H
#define __LUNA_ENGINE_H

#include"stackoffset.hpp"
#include"stringutils.h"
#include"stringfilters.h"
#include "util/util.h"
#include "ithsys/ithsys.h"
#include"pchooks/pchooks.h"
#include "disasm/disasm.h"
#include"main.h"
#include"const.h"

extern WCHAR* processName,  processPath[MAX_PATH],processName_lower[MAX_PATH]; // cached
extern uintptr_t processStartAddress, processStopAddress;
extern uintptr_t processStartAddress, processStopAddress;

class ENGINE{
    public:
    const char* enginename;
    bool dontstop;//dont stop even if attached a engine
    bool is_engine_certain; //stop when match a engine ,even if not attached

    enum class CHECK_BY {
        ALL_TRUE,
        FILE, FILE_ALL,FILE_ANY,
        RESOURCE_STR,
        CUSTOM, 
    };
    CHECK_BY check_by;
    // const wchar_t* check_by_single;
    // std::vector<const wchar_t*>check_by_list; 
    // std::function<bool()>check_by_custom_function;
    typedef  std::function<bool()> check_by_custom_function;
    typedef  std::vector<const wchar_t*> check_by_list;
    typedef  const wchar_t* check_by_single;
    std::variant<check_by_single,check_by_list,check_by_custom_function>check_by_target;
    //virtual bool check_by_target(){return false;};
    virtual bool attach_function()=0;
    virtual const char* getenginename(){
        if(enginename)return enginename;
        return typeid(*this).name()+6;
    }
    ENGINE():enginename(nullptr),dontstop(false),is_engine_certain(true),check_by(CHECK_BY::ALL_TRUE){};
    bool check_function();
};

#endif