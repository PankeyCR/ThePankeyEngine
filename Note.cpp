

#ifndef Note_cpp
#define Note_cpp

#include "Note.h"

ame::MemoryChunk* ame::Note::charsChunk = nullptr;
/*
char ame::Note::space = ' ';
char ame::Note::endLine = '.';
char ame::Note::enter = '\n';
char ame::Note::empty = '\0';
*/

	void* ame::Note::operator new(size_t size){
		
	}
	
	void ame::Note::operator delete(void* pointerToDelete){
		
	}

	ame::Note::Note(){
		NoteLog("Note", "Constructor",  "println", "no parameters");
	}

	void ame::Note::init(){
		NoteLog("Note", "init",  "println", "");
	}
/*	
	ame::Note::Note(int size,int expand): PrimitiveList(size,expand){
		NoteLog("Note", "Constructor",  "println", "PrimitiveList(size,expand)");
	}
	
	ame::Note::Note(const char *cstr){
		NoteLog("Note", "Constructor",  "println", "const char *cstr");
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}

	ame::Note::Note(const int& i){
		NoteLog("Note", "Constructor",  "println", "const int& i");
		char binary[7] = {0};
		char* cstr = itoa(i,binary,10);
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}

	ame::Note::Note(const long& i){
		NoteLog("Note", "Constructor",  "println", "const long& i");
		char binary[11] = {0};
		char* cstr = ltoa(i,binary,10);
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}

	ame::Note::Note(const char& i){
		NoteLog("Note", "Constructor",  "println", "const char& i");
		this->addLValue(i);
	}

	ame::Note::Note(const String& s){
		NoteLog("Note", "Constructor",  "println", "const String& i");
		if(s.length() >= this->size){
			this->expandLocal(s.length()-this->size+5);
		}        
        
		for(int x=0; x< s.length();x++){
			this->addLValue(s.charAt(x));
		}
	}
	
	ame::Note::~Note(){
		NoteLog("Note", "Destructor",  "println", "");
		//Serial.println("Note");
	}
		
	char* ame::Note::addPointer(char* value){
		if(value == nullptr){
			return nullptr;
		}
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return nullptr;
		}
		this->values[this->pos] = value;
		this->pos++;
		return this->values[this->pos-1];
	}
		
	char* ame::Note::addLValue(char value){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return nullptr;
		}
		if(this->values[this->pos] == nullptr){
			this->values[this->pos] = new char(value);
		}
		// *this->values[this->pos] = value;
		this->pos++;
		// Serial.println(*this->values[this->pos-1]);
		// return this->values[this->pos-1];
		return nullptr;
	}
	
    size_t ame::Note::printTo(Print& p) const{
		NoteLog("Note", "printTo",  "println", "");
		for(int x = 0; x < this->pos; x++){
			if(this->values[x] != nullptr && *this->values[x] != empty){
				p.print(*this->values[x]);
			}
		}
	}
	
	void ame::Note::expandLocal(int add){
		Serial.print("expanding local: ");Serial.println(add);
		int nsize = this->size+add;
		char **nT;
		nT = new char*[nsize];
		for(int x=0; x < nsize; x++){
			if(x < this->pos){
				nT[x] = new char();
				*nT[x] = *this->values[x];
				delete this->values[x];
			}else{
				nT[x] = nullptr;
			}
		}
		delete[] this->values;
		this->values = nT;
		this->size = nsize;
	}
	
	ame::Note* ame::Note::expand(int add){
		int nsize = this->size+add;
		ame::Note* m_nte = new ame::Note(nsize,10);	
		for(int x=0; x < this->pos; x++){
			m_nte->addLValue(*this->values[x]);
		}
		return m_nte;
	}
	
	int ame::Note::length(){
		return this->pos;
	}
	
	int ame::Note::getFocus(){
		return this->focus;
	}
	
	void ame::Note::setFocus(int Focus){
		this->focus = Focus;
	}
	
	ame::PrimitiveList<int> ame::Note::getCharPositions(char chr){
		ame::PrimitiveList<int> list;
		for(int x=0; x< this->getPosition();x++){
			if(*this->getByPosition(x) == chr){
				list.addLValue(x);
			}
		}
		return list;
	}
	
	int ame::Note::getCharPosition(char chr, int pos){
		int apply=0;
		for(int x=0; x< this->getPosition();x++){
			if(*this->getByPosition(x) == chr){
				if(pos == apply){
					return x;
				}
				apply++;
			}
		}
		return apply;
	}
	
	int ame::Note::getCharSize(char chr){
		int apply=0;
		for(int x=0; x< this->getPosition();x++){
			if(*this->getByPosition(x) == chr){
				apply++;
			}
		}
		
		return apply;
	}
	
	ame::PrimitiveList<int> ame::Note::getSpacePositions(){
		ame::PrimitiveList<int> list;
		for(int x=0; x< this->getPosition();x++){
			if(*this->getByPosition(x) == space){
				list.addLValue(x);
			}
		}
		
		return list;
	}
	
	int ame::Note::getSpaceSize(){
		int apply=0;
		for(int x=0; x< this->getPosition();x++){
			if(*this->getByPosition(x) == space){
				apply++;
			}
		}
		return apply;
	}
	
	int ame::Note::getSpacingSize(){
		int spacing=0;
		for(int x=0; x< this->getPosition();x++){
			char c = *this->getByPosition(x);
			char* c1 = this->getByPosition(x+1);
			if(c1 == nullptr || (x+1) < this->getPosition()){
				return spacing;
			}
			if((c == space || c == enter) && (*c1 != space || *c1 != enter )){
					spacing++;
			}
		}
		return spacing;
	}
	//////////////////////////////////////////////////////////////////////////////////
	ame::PrimitiveList<int> ame::Note::getStringPositions(String str){
		ame::PrimitiveList<int> list;
		// int p[20];
		// int apply=0;
		// for(int x=0; x< this->getPosition();x++){
			// char c = *this->getByPosition(x);
			//char s = 
			// if(str == c){
				// p[apply] = x;
				// apply++;
			// }
		// }
		
		return list;
	}
	
	void ame::Note::fixExtraSpace(){
		int xspaces = 0;
		for(int x = (this->getPosition()-1); x >= 0; x--){
			if(*this->getByPosition(x) == space || *this->getByPosition(x) == empty){
				this->setLValue(x, '\0');				
				xspaces++;
			}else{
				break;
			}
		}
		if(xspaces>0){
			this->setPosition(this->getPosition()-xspaces);
		}
	}
	
	void ame::Note::fixEmptySpaces(){
		
	}
	
	void ame::Note::fixEndLinePoint(){
		// if(*this->getByPosition(this->getPosition()-1) == endLine){
			// this->set(this->getPosition()-1, empty);
			// this->setPos(this->getPosition()-1);
		// }
		// this->remove(empty);	
	}
	
	String ame::Note::fixExtraSpace(String s){
		ame::Note n;
		n = s;
		n.fixExtraSpace();
		return n.toString();
	}
	
	String ame::Note::fixEmptySpaces(String s){
		ame::Note n;
		n = s;
		n.fixEmptySpaces();
		return n.toString();
	}
	
	String ame::Note::fixEndLinePoint(String s){
		ame::Note n;
		n = s;
		n.fixEndLinePoint();
		return n.toString();
	}
	
	// template<int Lsize=20>
	// ArrayList<String,Lsize> ame::Note::getWords(){
		
	// }
	
	String ame::Note::getWord(int pos){
		return Split(this->toString(), pos, space);
	}
	
	String ame::Note::getSentence(int pos){
		return Split(this->toString(), pos, enter);
	}
	
	String ame::Note::getParagraph(int pos){
		int paragraph = 0;
		bool start = false;
		String p;
		for(int x = 0; x < this->pos; x++){
			if(*this->values[x] == enter && *this->values[x+1] == enter){
				paragraph++;
			}
			if(paragraph == pos && *this->values[x] != enter){
				start = true;
			}
			if(paragraph > pos){
				start = false;
				return p;
			}
			if(start){
				p.concat(*this->values[x]);
			}
		}
		return p;
	}
		
	String ame::Note::getWord(int pos, String m_nte){
		return Split(m_nte, pos, space);
	}
	String ame::Note::getSentence(int pos, String m_nte){
		return Split(m_nte, pos, enter);
	}
	String ame::Note::getParagraph(int pos, String m_nte){
		// int paragraph = 0;
		// bool start = false;
		// String p;
		// for(int x = 0; x < this->pos; x++){
			// if(*this->values[x] == enter && *this->values[x+1] == enter){
				// paragraph++;
			// }
			// if(paragraph == pos && *this->values[x] != enter){
				// start = true;
			// }
			// if(paragraph > pos){
				// start = false;
				// return p;
			// }
			// if(start){
				// p.concat(*this->values[x]);
			// }
		// }
		return m_nte;
	}
	
	int ame::Note::getSentenceSize(){
		int size = 1;
		for(int x = 0; x < this->pos; x++){
			if(*this->values[x] == enter){
				size++;
			}
		}
		return size;
	}
	
	int ame::Note::getSentenceSize(String m_nte){
		int size = 1;
		for(char c : m_nte){
			if(c == enter){
				size++;
			}
		}
		return size;
	}
	
	void ame::Note::reset(){
		
	}
	
	bool ame::Note::remove(String s){
		return true;
	}
	
	bool ame::Note::remove(char key, int pos){
		return true;
	}
	
	bool ame::Note::remove(String key, int pos){
		return true;
	}
  
	String ame::Note::Split(String divide,int parte, char limiter){     
        String return_1="";     
        int delimiter=0;
		
		for(int x = 0; x < divide.length(); x++){
			if(divide.charAt(x) == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (divide.charAt(x) != limiter)){
                return_1.concat(divide.charAt(x));
            }
		}
        return return_1;
		
        // int respuesta_len = divide.length() + 1; 
        // char respuesta_array[respuesta_len];
        // divide.toCharArray(respuesta_array, respuesta_len);
        // for(int i=0; i < respuesta_len; i++){
			// if(respuesta_array[i] == limiter){                   
                // delimiter++;  
            // }
            // if((parte == delimiter) && (respuesta_array[i] != limiter)){
                // return_1+=respuesta_array[i];
            // }
        // }
        // return return_1;
    }
  
	int ame::Note::SplitLenght(String divide, char limiter){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
			if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
        }
        return delimiter;
    }
  
	String ame::Note::Split(String divide,int parte, char limiter, char fin){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
            if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] == fin)){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] != limiter)){
                return_1=return_1+respuesta_array[i];
            }
        }
        return return_1;
	}
	
	int ame::Note::toInt(){
		int r = 0;
		ame::TemplateMath math;
		for(int x = 0; x < this->pos; x++){
			r += (*this->values[x] - 48) * math.exp(this->pos - x - 1);
		}
		return r;
	}
	long ame::Note::toLong(){
		long r = 0;
		ame::TemplateMath math;
		for(int x = 0; x < this->pos; x++){
			r += (*this->values[x] - 48) * math.exp(this->pos - x - 1);
		}
		return r;
	}
	char ame::Note::toChar(){
		if(this->pos == 1){
			return *this->values[0];
		}
		return empty;
	}
	
	char ame::Note::toChar(int x){
		if(this->pos > x){
			return *this->values[x];
		}
		return empty;
	}
	
	String ame::Note::toString(){
		String s;
		for(int x = 0; x < this->getPosition(); x++){
			if(this->getByPosition(x)!=nullptr){
				Serial.print("toString: ");
				Serial.println(*this->getByPosition(x));
				Serial.println(x);
				s.concat(*this->getByPosition(x));
			}
		}
		return s;
	}
	
	void ame::Note::operator=(const String& s){
		this->resetDelete();    
        if(s.length() == 0){
			return;
		}
        if(s.length() > this->size){
			//Serial.println("trying to expand");
			this->expandLocal(s.length()-this->size+5);
		}
		unsigned int size= s.length()+1; 
		char Array[size];
        s.toCharArray(Array, size);        
        
		for(int x=0; x< s.length();x++){
			this->addLValue(Array[x]);
		}
	}
	
	void ame::Note::operator=(const char* cstr){
		this->resetDelete(); 
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}
	
	void ame::Note::operator=(const int& i){
		this->resetDelete(); 
		char binary[7] = {0};
		char* cstr = itoa(i,binary,10);
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}
	
	void ame::Note::operator=(const long& i){
		this->resetDelete(); 
		char binary[11] = {0};
		char* cstr = ltoa(i,binary,10);
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}
	
	void ame::Note::operator=(const char& i){
		this->resetDelete(); 
		this->addLValue(i);
	}
	
	void ame::Note::operator=(ame::Note m_nte){
		this->resetDelete();
		for(int x = 0 ; x < m_nte.getPosition(); x++){
			this->addLValue(*m_nte.getByPosition(x));
		}
	}
	
	ame::Note ame::Note::operator+(ame::Note m_nte){
		for(int x = 0 ; x < m_nte.getPosition(); x++){
			this->addLValue(*m_nte.getByPosition(x));
		}
		return *this;
	}
	
	ame::Note ame::Note::operator+(const char* cstr){
		ame::Note n;
		for(int x = 0 ; x < n.getPosition(); x++){
			this->addLValue(*n.getByPosition(x));
		}
		for(  ;  *cstr != empty; cstr++){
			n.addLValue(*cstr);
		}
		return n;
	}
	
	void ame::Note::operator+=(const char* cstr){
		if(this->pos >= this->size){
			this->expandLocal(this->expandSize);
		}
		if(this->pos >= this->size){
			return;
		}
		for(  ;  *cstr != empty; cstr++){
			this->addLValue(*cstr);
		}
	}
	
	ame::Note ame::Note::operator+(const char& chr){
		this->addLValue(chr);
		return *this;
	}
	
	void ame::Note::operator+=(const char& chr){
		this->addLValue(chr);
	}
	
	// ame::Note ame::Note::operator+(const char *chr){
		// this->addLValue(chr);
		// return *this;
	// }
	
	void ame::Note::operator+=(const String& s){
		for(int x=0; x < s.length();x++){
			this->addLValue(s.charAt(x));
		}
	}
	
	void ame::Note::operator<(const char* chr){
		this->addLValue(enter);
        
		for(  ;  *chr != empty; chr++){
			this->addLValue(*chr);
		}
	}
	
	void ame::Note::operator<<(const char* chr){
		this->addLValue(enter);
		this->addLValue(enter);
        
		for(  ;  *chr != empty; chr++){
			this->addLValue(*chr);
		}
	}
	
	bool ame::Note::operator==(ame::Note m_nte){
		int x = 0 ;
		if(this->pos != m_nte.getPosition()){
			return false;
		}
		for(int x = 0; x<this->pos; x++){
			if(*m_nte.getByPosition(x) != *this->values[x]){
				return false;
			}
		}
		return true;
	}
	
	bool ame::Note::operator!=(ame::Note m_nte){
		int x = 0 ;
		if(this->pos != m_nte.getPosition()){
			return true;
		}
		for(int x = 0; x<this->pos; x++){
			if(*m_nte.getByPosition(x) != *this->values[x]){
				return true;
			}
		}
		return false;
	}
	
	bool ame::Note::operator==(const char* chr){
		int x = 0 ;
		for( ;  *chr != empty; chr++){
			if(*chr != *this->values[x]){
				return false;
			}
			x++;
		}
		if(this->pos != x){
			return false;
		}
		return true;
	}
	
	bool ame::Note::operator!=(const char* chr){
		int x = 0 ;
		for( ;  *chr != empty; chr++){
			if(*chr != *this->values[x]){
				return true;
			}
			x++;
		}
		if(this->pos != x){
			return true;
		}
		return false;
	}
	
	*/
	
#endif
