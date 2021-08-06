#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "IDBAPlugin.h"

bool TXTfile(std::string file) {
   int len = file.size();
   return (file[len-3] == 't' && file[len-2] == 'x' && file[len-1] == 't');
}

void IDBAPlugin::input(std::string file) 
{
 inputfile = file;
 if (TXTfile(file)) {
	 // Assume short first, long second
	 hybrid = true;
         std::ifstream infile2(file, std::ios::in);
	 infile2 >> inputfile; // New inputfile (Short)
	 infile2 >> longfile; // Long
 }
 else
	 hybrid = false;
}

void IDBAPlugin::run() {
   
}

void IDBAPlugin::output(std::string file) {
	//idba_hybrid -r Short_reads_together.fa -o hyb_idba -l $3

	std::string command;
if (hybrid)
	command = "idba_hybrid -r "+std::string(PluginManager::prefix())+"/"+inputfile+" -o "+file+" -l "+std::string(PluginManager::prefix())+"/"+longfile;
	else 
 command = "idba -r "+inputfile+" -o "+file;
 std::cout << command << std::endl;
 system(command.c_str());
 std::string copyCommand = "cp "+file+"/*.fa "+std::string(PluginManager::prefix());
 system(copyCommand.c_str());
}

PluginProxy<IDBAPlugin> IDBAPluginProxy = PluginProxy<IDBAPlugin>("IDBA", PluginManager::getInstance());
