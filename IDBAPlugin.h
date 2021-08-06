#ifndef IDBAPLUGIN_H
#define IDBAPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class IDBAPlugin : public Plugin
{
public: 
 std::string toString() {return "IDBA";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
 std::string longfile;
 bool hybrid;
};

#endif
