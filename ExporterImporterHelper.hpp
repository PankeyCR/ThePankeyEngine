
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ExporterImporterHelper)
	#define ExporterImporterHelper_hpp
#endif

#ifndef ExporterImporterHelper_hpp
#define ExporterImporterHelper_hpp
#define ExporterImporterHelper_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "MonkeyFile.hpp"
#include "SerialMessageState.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "TextExporter.hpp"
#include "TextImporter.hpp"

#ifdef ExporterImporterHelperLogApp
	#include "Logger.hpp"
	#define ExporterImporterHelperLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define ExporterImporterHelperLog(name,method,type,mns)
#endif

namespace ame{
	
	void writeTextImporter(MonkeyImporter* importer, MonkeyFile* file, Note path){
		// if(file == nullptr || exporter == nullptr || importer == nullptr){
			// return;
		// }
		// if(!file->exist(path)){
			// return;
		// }
		// Note f_text = file->readText(path);
		// if(f_text == ""){
			// importer->write(file, path);
			// return;
		// }
		
		// TextImporter f_importer = f_text;
		
		// CommandReader cmd;
		// cmd.setText(f_text);
		
		// for(int x = 0; x < importer->ids.getPosition(); x++){
			// ElementId i_id = importer->ids[x];
			// f_importer.remove(i_id);
		// }
		
		// file->writeText(text, path);
	}

}

#endif