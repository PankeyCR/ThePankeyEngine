
#ifndef TransporterObject_hpp
#define TransporterObject_hpp

#include "ElementId.hpp"
#include "MonkeyExporter.hpp"
#include "MonkeyImporter.hpp"
#include "MonkeyTransporter.hpp"

namespace ame{

class TransporterObject : public MonkeyTransporter, public Printable{
    public:
		TransporterObject(){}
		TransporterObject(const TransporterObject& obj){
			intMap = obj.intMap;
			floatMap = obj.floatMap;
			stringMap = obj.stringMap;
			longMap = obj.longMap;
			byteMap = obj.byteMap;
			emptyInstance = obj.emptyInstance;
		}
		virtual ~TransporterObject(){}
		
		size_t printTo(Print& p) const{
			size_t size = 0;
			size += p.print("Integers: \n");
			for(int x = 0; x < intMap.getPosition(); x++){
				String iName = *intMap.getKeyByPosition(x);
				int iVar = *intMap.getByPosition(x);
				size += p.print("Int Name: ");
				size += p.print(iName);
				size += p.print(" Int Value: ");
				size += p.print(iVar);
				size += p.print('\n');
			}
			size += p.print('\n');
			size += p.print("Float: \n");
			for(int x = 0; x < floatMap.getPosition(); x++){
				String iName = *floatMap.getKeyByPosition(x);
				float iVar = *floatMap.getByPosition(x);
				size += p.print("Float Name: ");
				size += p.print(iName);
				size += p.print(" Float Value: ");
				size += p.print(iVar);
				size += p.print('\n');
			}
			size += p.print('\n');
			size += p.print("String: \n");
			for(int x = 0; x < stringMap.getPosition(); x++){
				String iName = *stringMap.getKeyByPosition(x);
				String iVar = *stringMap.getByPosition(x);
				size += p.print("String Name: ");
				size += p.print(iName);
				size += p.print(" String Value: ");
				size += p.print(iVar);
				size += p.print('\n');
			}
			size += p.print('\n');
			size += p.print("Long: \n");
			for(int x = 0; x < longMap.getPosition(); x++){
				String iName = *longMap.getKeyByPosition(x);
				long iVar = *longMap.getByPosition(x);
				size += p.print("Long Name: ");
				size += p.print(iName);
				size += p.print(" Long Value: ");
				size += p.print(iVar);
				size += p.print('\n');
			}
			size += p.print('\n');
			size += p.print("ByteArray: \n");
			for(int x = 0; x < byteMap.getPosition(); x++){
				String iName = *byteMap.getKeyByPosition(x);
				ByteArray iVar = *byteMap.getByPosition(x);
				size += p.print("ByteArray Name: ");
				size += p.print(iName);
				size += p.print(" ByteArray Value: ");
				size += p.print(iVar);
				size += p.print('\n');
			}
			size += p.print('\n');
			size += p.print("Instances: \n");
			for(int x = 0; x < emptyInstance.getPosition(); x++){
				String iName = *emptyInstance.getByPosition(x);
				size += p.print("Class Name: ");
				size += p.print(iName);
				size += p.print('\n');
			}
			return size;
		}
		
		//int
		//////////////////////////////////////////////////////////////////////////////
		
		virtual int putInt(const char* s, int i){
			intMap.put(String(s),i);
			return i;
		}
		virtual int putInt(String s, int i){
			intMap.put(s,i);
			return i;
		}
		virtual int getInt(String s, int defaultV){
			int* i = intMap.getByLValue(s);
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containInt(String s){
			return intMap.getByLValue(s) != nullptr;
		}
		
		virtual int putInt(ElementId s, int i){
			intMap.put(s.getId(),i);
			return i;
		}
		virtual int getInt(ElementId s, int defaultV){
			int* i = intMap.getByLValue(s.getId());
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containInt(ElementId s){
			return intMap.getByLValue(s.getId()) != nullptr;
		}
		
		//float
		//////////////////////////////////////////////////////////////////////////////
		
		virtual float putFloat(const char* s, float i){
			floatMap.put(String(s),i);
			return i;
		}
		virtual float putFloat(String s, float i){
			floatMap.put(s,i);
			return i;
		}
		virtual float getFloat(String s, float defaultV){
			float* i = floatMap.getByLValue(s);
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containFloat(String s){
			return floatMap.getByLValue(s) != nullptr;
		}
		
		virtual float putFloat(ElementId s, float i){
			floatMap.put(s.getId(),i);
			return i;
		}
		virtual float getFloat(ElementId s, float defaultV){
			float* i = floatMap.getByLValue(s.getId());
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containFloat(ElementId s){
			return floatMap.getByLValue(s.getId()) != nullptr;
		}
		
		//String
		//////////////////////////////////////////////////////////////////////////////
		
		virtual String putString(const char* s, const char* i){
			stringMap.put(String(s),String(i));
			return i;
		}
		virtual String putString(const char* s, String i){
			stringMap.put(String(s),i);
			return i;
		}
		virtual String putString(String s, String i){
			stringMap.put(s,i);
			return i;
		}
		virtual String getString(String s, String defaultV){
			String* i = stringMap.getByLValue(s);
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containString(String s){
			return stringMap.getByLValue(s) != nullptr;
		}
		
		virtual String putString(ElementId s, String i){
			stringMap.put(s.getId(),i);
			return i;
		}
		virtual String getString(ElementId s, String defaultV){
			String* i = stringMap.getByLValue(s.getId());
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containString(ElementId s){
			return stringMap.getByLValue(s.getId()) != nullptr;
		}
		
		//Boolean
		//////////////////////////////////////////////////////////////////////////////
		
		virtual bool putBoolean(const char* s, bool i){
			booleanMap.put(String(s),i);
			return i;
		}
		virtual bool putBoolean(String s, bool i){
			booleanMap.put(s,i);
			return i;
		}
		virtual bool getBoolean(String s, bool defaultV){
			bool* i = booleanMap.getByLValue(s);
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containBoolean(String s){
			return booleanMap.getByLValue(s) != nullptr;
		}
		
		virtual bool putBoolean(ElementId s, bool i){
			booleanMap.put(s.getId(),i);
			return i;
		}
		virtual bool getBoolean(ElementId s, bool defaultV){
			bool* i = booleanMap.getByLValue(s.getId());
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containBoolean(ElementId s){
			return booleanMap.getByLValue(s.getId()) != nullptr;
		}
		
		//long
		//////////////////////////////////////////////////////////////////////////////
		
		virtual long putLong(const char* s, long i){
			longMap.put(String(s),i);
			return i;
		}
		virtual long putLong(String s, long i){
			longMap.put(s,i);
			return i;
		}
		virtual long getLong(String s, long defaultV){
			long* i = longMap.getByLValue(s);
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containLong(String s){
			return longMap.getByLValue(s) != nullptr;
		}
		
		virtual long putLong(ElementId s, long i){
			longMap.put(s.getId(),i);
			return i;
		}
		virtual long getLong(ElementId s, long defaultV){
			long* i = longMap.getByLValue(s.getId());
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containLong(ElementId s){
			return longMap.getByLValue(s.getId()) != nullptr;
		}
		
		//ByteArray
		//////////////////////////////////////////////////////////////////////////////
		
		virtual ByteArray putByteArray(const char* s, ByteArray i){
			byteMap.put(String(s),i);
			return i;
		}
		virtual ByteArray putByteArray(String s, ByteArray i){
			byteMap.put(s,i);
			return i;
		}
		virtual ByteArray getByteArray(String s, ByteArray defaultV){
			ByteArray* i = byteMap.getByLValue(s);
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containByteArray(String s){
			return byteMap.getByLValue(s) != nullptr;
		}
		
		virtual ByteArray putByteArray(ElementId s, ByteArray i){
			byteMap.put(s.getId(),i);
			return i;
		}
		virtual ByteArray getByteArray(ElementId s, ByteArray defaultV){
			ByteArray* i = byteMap.getByLValue(s.getId());
			if(i == nullptr){
				return defaultV;
			}
			return *i;
		}
		virtual bool containByteArray(ElementId s){
			return byteMap.getByLValue(s.getId()) != nullptr;
		}
		
		//Object
		//////////////////////////////////////////////////////////////////////////////
		
		virtual void putObject(const char* s){
			int index = emptyInstance.getIndexByLValue(String(s));
			if(index != -1){
				return;
			}
			emptyInstance.add(String(s));
		}
		virtual void putObject(String s){
			int index = emptyInstance.getIndexByLValue(s);
			if(index == -1){
				return;
			}
			emptyInstance.add(s);
		}
		virtual void putObject(ElementId s){
			int index = emptyInstance.getIndexByLValue(s.getId());
			if(index == -1){
				return;
			}
			emptyInstance.add(s.getId());
		}
		
		virtual void putObject(ElementId s, TransporterObject i){
			for(int x = 0; x < i.intMap.getPosition(); x++){
				String iName = *i.intMap.getKeyByPosition(x);
				int iInt = *i.intMap.getByPosition(x);
				intMap.put(s.child(iName).getId(), iInt);
			}
			for(int x = 0; x < i.floatMap.getPosition(); x++){
				String iName = *i.floatMap.getKeyByPosition(x);
				float iFloat = *i.floatMap.getByPosition(x);
				floatMap.put(s.child(iName).getId(), iFloat);
			}
			for(int x = 0; x < i.stringMap.getPosition(); x++){
				String iName = *i.stringMap.getKeyByPosition(x);
				String iString = *i.stringMap.getByPosition(x);
				stringMap.put(s.child(iName).getId(), iString);
			}
			for(int x = 0; x < i.booleanMap.getPosition(); x++){
				String iName = *i.booleanMap.getKeyByPosition(x);
				bool iBool = *i.booleanMap.getByPosition(x);
				booleanMap.put(s.child(iName).getId(), iBool);
			}
			for(int x = 0; x < i.longMap.getPosition(); x++){
				String iName = *i.longMap.getKeyByPosition(x);
				long ilong = *i.longMap.getByPosition(x);
				longMap.put(s.child(iName).getId(), ilong);
			}
			for(int x = 0; x < i.byteMap.getPosition(); x++){
				String iName = *i.byteMap.getKeyByPosition(x);
				ByteArray iVar = *i.byteMap.getByPosition(x);
				byteMap.put(s.child(iName).getId(), iVar);
			}
			for(int x = 0; x < i.emptyInstance.getPosition(); x++){
				String iName = *i.emptyInstance.getByPosition(x);
				String ns = s.child(iName).getId();
				if(i.emptyInstance.containByLValue(ns)){
					continue;
				}
				emptyInstance.add(ns);
			}
		}
		
		virtual TransporterObject getObject(ElementId s){
			TransporterObject t;
			
			for(int x = 0; x < intMap.getPosition(); x++){
				String iName = *intMap.getKeyByPosition(x);
				int iVar = *intMap.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putInt(s, iVar);
			}
			for(int x = 0; x < floatMap.getPosition(); x++){
				String iName = *floatMap.getKeyByPosition(x);
				float iVar = *floatMap.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putFloat(s, iVar);
			}
			for(int x = 0; x < stringMap.getPosition(); x++){
				String iName = *stringMap.getKeyByPosition(x);
				String iVar = *stringMap.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putString(s, iVar);
			}
			for(int x = 0; x < booleanMap.getPosition(); x++){
				String iName = *booleanMap.getKeyByPosition(x);
				bool iVar = *booleanMap.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putBoolean(s, iVar);
			}
			for(int x = 0; x < longMap.getPosition(); x++){
				String iName = *longMap.getKeyByPosition(x);
				long iVar = *longMap.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putLong(s, iVar);
			}
			for(int x = 0; x < byteMap.getPosition(); x++){
				String iName = *byteMap.getKeyByPosition(x);
				ByteArray iVar = *byteMap.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putByteArray(s, iVar);
			}
			for(int x = 0; x < emptyInstance.getPosition(); x++){
				String iName = *emptyInstance.getByPosition(x);
				if(!s.containChild(iName)){
					continue;
				}
				t.putObject(s);
			}
			
			return t;
		}
		
		virtual bool containObject(ElementId s){
			for(int x = 0; x < intMap.getPosition(); x++){
				String iName = *intMap.getKeyByPosition(x);
				int iVar = *intMap.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			for(int x = 0; x < floatMap.getPosition(); x++){
				String iName = *floatMap.getKeyByPosition(x);
				float iVar = *floatMap.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			for(int x = 0; x < stringMap.getPosition(); x++){
				String iName = *stringMap.getKeyByPosition(x);
				String iVar = *stringMap.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			for(int x = 0; x < booleanMap.getPosition(); x++){
				String iName = *booleanMap.getKeyByPosition(x);
				bool iVar = *booleanMap.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			for(int x = 0; x < longMap.getPosition(); x++){
				String iName = *longMap.getKeyByPosition(x);
				long iVar = *longMap.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			for(int x = 0; x < byteMap.getPosition(); x++){
				String iName = *byteMap.getKeyByPosition(x);
				ByteArray iVar = *byteMap.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			for(int x = 0; x < emptyInstance.getPosition(); x++){
				String iName = *emptyInstance.getByPosition(x);
				if(s.containChild(iName)){
					return true;
				}
			}
			
			return false;
		}
		
    	virtual void write(ElementId id, MonkeyExporter* exporter){
			for(int x = 0; x < emptyInstance.getPosition(); x++){
				String iName = *emptyInstance.getByPosition(x);
				exporter->write(id.child(iName).child("instance"), String());
			}
			for(int x = 0; x < intMap.getPosition(); x++){
				String iName = *intMap.getKeyByPosition(x);
				int iVar = *intMap.getByPosition(x);
				exporter->write(id.child(iName), iVar);
			}
			for(int x = 0; x < floatMap.getPosition(); x++){
				String iName = *floatMap.getKeyByPosition(x);
				float iVar = *floatMap.getByPosition(x);
				exporter->write(id.child(iName), iVar);
			}
			for(int x = 0; x < stringMap.getPosition(); x++){
				String iName = *stringMap.getKeyByPosition(x);
				String iVar = *stringMap.getByPosition(x);
				exporter->write(id.child(iName), iVar);
			}
			for(int x = 0; x < booleanMap.getPosition(); x++){
				String iName = *booleanMap.getKeyByPosition(x);
				bool iVar = *booleanMap.getByPosition(x);
				exporter->write(id.child(iName), iVar);
			}
			for(int x = 0; x < longMap.getPosition(); x++){
				String iName = *longMap.getKeyByPosition(x);
				long iVar = *longMap.getByPosition(x);
				exporter->write(id.child(iName), iVar);
			}
			for(int x = 0; x < byteMap.getPosition(); x++){
				String iName = *byteMap.getKeyByPosition(x);
				ByteArray iVar = *byteMap.getByPosition(x);
				exporter->write(id.child(iName), iVar);
			}
		}
		
    	virtual void read(ElementId parent, MonkeyImporter* importer){
			PrimitiveList<ElementId> ids = importer->getIds();
			for(int x = 0; x < ids.getPosition(); x++){
				ElementId id = ids[x];
				String typeVar = importer->readType(id);
				if(typeVar == "int"){
					int i = importer->read(id,-1);
					intMap.add(id.remove(parent).getId(),i);
				}
				if(typeVar == "float"){
					float i = importer->read(id,-1.0f);
					floatMap.add(id.remove(parent).getId(),i);
				}
				if(typeVar == "String"){
					if(id.hppasPart("instance")){
						emptyInstance.add(id.remove(parent).removePart("instance").getId());
						continue;
					}
					String i = importer->read(id,String());
					stringMap.add(id.remove(parent).getId(),i);
				}
				if(typeVar == "bool"){
					bool i = importer->read(id,false);
					booleanMap.add(id.remove(parent).getId(),i);
				}
				if(typeVar == "long"){
					long i = importer->read(id,0l);
					floatMap.add(id.remove(parent).getId(),i);
				}
				if(typeVar == "ByteArray"){
					ByteArray i = importer->read(id,ByteArray());
					byteMap.add(id.remove(parent).getId(),i);
				}
			}
		}
	protected:
		PrimitiveMap<String,int> intMap;
		PrimitiveMap<String,float> floatMap;
		PrimitiveMap<String,String> stringMap;
		PrimitiveMap<String,bool> booleanMap;
		PrimitiveMap<String,long> longMap;
		PrimitiveMap<String,ByteArray> byteMap;
		PrimitiveList<String> emptyInstance;
};

}

#endif 
