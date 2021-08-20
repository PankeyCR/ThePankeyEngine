
#ifndef MapFileFunction_cpp
#define MapFileFunction_cpp

#include "MapFileFunction.h"

	template<class K,class V>
	ame::MapFileFunction<K,V>::MapFileFunction(){
		
	}
	
	template<class K,class V>
	ame::MapFileFunction<K,V>::~MapFileFunction(){
		// if(this->fileFunctions != nullptr){
			// delete this->fileFunctions;
		// }
	}
	
	template<class K,class V>
	bool ame::MapFileFunction<K,V>::SaveFileFunction(ame::MonkeyFile* file, ame::cppObject* instance,String path,String key){
		
		
		return false;
	}
	
	template<class K,class V>
	ame::cppObject* ame::MapFileFunction<K,V>::LoadFileFunction(ame::MonkeyFile* file, ame::cppObject* attachable,String path,String key){
		
		
		return nullptr;
	}
	
	template<class K,class V>
	bool ame::MapFileFunction<K,V>::DeleteFileFunction(ame::MonkeyFile* file, ame::cppObject* attachable,String path,String key){
		
		
		return false;
	}
	
	// template<>
	// bool ame::MapFileFunction<String,String>::SaveFileFunction(ame::MonkeyFile* file, ame::cppObject* instance,String path,String key){
		// file->create(path+".txt");
		// ame::Map<String,String>* map = (ame::Map<String,String>*)instance;
		// String mapS="";
		// mapS.concat(String(map->getSize()));
		// for(int x = 0; x < map->getPosition(); x++){
			// mapS.concat(*map->getKeyByPosition(x));
			// mapS.concat(Note::enter);
			// mapS.concat(*map->getByPosition(x));
			// mapS.concat(Note::enter);
		// }
		// file->write(path+".txt", mapS);
		////Serial.println(file->read(path+".txt"));
		// return true;
	// }
	
	// template<>
	// ame::cppObject* ame::MapFileFunction<String,String>::LoadFileFunction(ame::MonkeyFile* file, ame::cppObject* attachable,String path,String key){
		
		// if(!file->exist(path+".txt")){
			// return nullptr;
		// }
		// Serial.println(file->read(path+".txt"));
		// Serial.println("prenote ");
		
		// ame::Note n;
		// Serial.println("posnote ");
		// n=file->read(path+".txt");
		// Serial.println("posposnote ");
		
		// Serial.println("note " +n.toString());
		// Serial.println("sentence " +n.getSentence(0));
		// int size = n.getSentence(0).toInt();
		// ame::Map<String,String>* map;
		
		// if(attachable == nullptr){
			// map = new ame::PrimitiveMap<String,String>();
		// }else{
			// map = (ame::PrimitiveMap<String,String>*)attachable;
		// }
		
		// for(int x= 0; x < size; x++){
			// map->addLValues(n.getSentence((x*2)+1),n.getSentence((x*2)+2));
		// }
		
		// return map;
	// }
	
	// template<>
	// bool ame::MapFileFunction<String,String>::DeleteFileFunction(ame::MonkeyFile* file, ame::cppObject* attachable,String path,String key){
		
		// return file->deleteRootFile(path+".txt");
	// }
	
	
	// template class ame::MapFileFunction<String,String>;
#endif 