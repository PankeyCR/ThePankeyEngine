
#ifndef MapFileFunction_cpp
#define MapFileFunction_cpp

#include "MapFileFunction.h"

	template<class K,class V>
	MapFileFunction<K,V>::MapFileFunction(){
		
	}
	
	template<class K,class V>
	MapFileFunction<K,V>::~MapFileFunction(){
		// if(this->fileFunctions != nullptr){
			// delete this->fileFunctions;
		// }
	}
	
	template<class K,class V>
	bool MapFileFunction<K,V>::SaveFileFunction(MonkeyFile* file,cppObject* instance,String path,String key){
		
		
		return false;
	}
	
	template<class K,class V>
	cppObject* MapFileFunction<K,V>::LoadFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
		
		
		return nullptr;
	}
	
	template<class K,class V>
	bool MapFileFunction<K,V>::DeleteFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
		
		
		return false;
	}
	
	template<>
	bool MapFileFunction<String,String>::SaveFileFunction(MonkeyFile* file,cppObject* instance,String path,String key){
		file->create(path+".txt");
		Map<String,String>* map = (Map<String,String>*)instance;
		String mapS="";
		mapS.concat(String(map->getSize()));
		iterate(map){
			mapS.concat(map->getKey());
			mapS.concat(enter);
			mapS.concat(map->getValue());
			mapS.concat(enter);
		}
		file->write(path+".txt", mapS);
		//Serial.println(file->read(path+".txt"));
		return true;
	}
	
	template<>
	cppObject* MapFileFunction<String,String>::LoadFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
		
		if(!file->exist(path+".txt")){
			return nullptr;
		}
		Serial.println(file->read(path+".txt"));
		Serial.println("prenote ");
		
		Note n;
		Serial.println("posnote ");
		n=file->read(path+".txt");
		Serial.println("posposnote ");
		
		Serial.println("note " +n.toString());
		Serial.println("sentence " +n.getSentence(0));
		int size = n.getSentence(0).toInt();
		Map<String,String>* map;
		
		if(attachable == nullptr){
			map = new PrimitiveMap<String,String>();
		}else{
			map = (PrimitiveMap<String,String>*)attachable;
		}
		
		for(int x= 0; x < size; x++){
			map->add(n.getSentence((x*2)+1),n.getSentence((x*2)+2));
		}
		
		return map;
	}
	
	template<>
	bool MapFileFunction<String,String>::DeleteFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
		
		return file->deleteRootFile(path+".txt");
	}
	
	
	template class MapFileFunction<String,String>;
#endif 