

/**
 *
 * @author PankeyCR - Manuel Sanchez Badilla
 *
 */
 
#ifndef TextListFileFunction_h
#define TextListFileFunction_h

#include "Arduino.h"
#include "cppObject.h"
#include "MonkeyFile.h"

class TextListFileFunction : public MonkeyFileFunction{
    public:
		TextListFileFunction(){}
		virtual ~TextListFileFunction(){}
    	virtual bool SaveFileFunction(MonkeyFile* file,cppObject* instance,String path,String key){
			return false;
		}
    	virtual cppObject* LoadFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
			if(attachable == nullptr){
				String fileText = file->read(path);
				List<String>* list = new ArrayList<String>();
				Lexer* lexer = new Lexer();
				
				for(int x =0; x < fileText.length(); x++){
					lexer->capture(fileText.getByIndex(x));
				}
				if(lexer->syntaxError()){
					delete list;
					delete lexer;
					return nullptr;
				}
				delete lexer;
				return list;
			}
			return nullptr;
		}
    	virtual bool DeleteFileFunction(MonkeyFile* file,cppObject* attachable,String path,String key){
			return file->deleteFile(path);
		}
	protected:
	
	
};

#endif 
