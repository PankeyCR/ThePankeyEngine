

#ifndef Note_cpp
#define Note_cpp

#include "Note.h"

//int Note::space = ' ';
//int Note::enter = '\n';
//int Note::empty = '\0';

	Note::Note(){
		this->charList = new ArrayList<char,20>();
		for(int x=0; x< this->charList->getSize(); x++){
			this->charList->set(x, '\0');
		}
	}

	Note::Note(int scale){
		if(scale == 0){
			this->charList = new ArrayList<char,50>();
		}
		if(scale == 1){
			this->charList = new ArrayList<char,100>();
		}
		if(scale == 2){
			this->charList = new ArrayList<char,200>();
		}
		if(scale == 3){
			this->charList = new ArrayList<char,300>();
		}
		if(scale == 4){
			this->charList = new ArrayList<char,400>();
		}
		if(scale == 5){
			this->charList = new ArrayList<char,500>();
		}
		if(scale == 6){
			this->charList = new ArrayList<char,600>();
		}
		if(scale == 7){
			this->charList = new ArrayList<char,700>();
		}
		if(scale == 8){
			this->charList = new ArrayList<char,800>();
		}
		if(scale == 9){
			this->charList = new ArrayList<char,900>();
		}
		if(scale == 10){
			this->charList = new ArrayList<char,1000>();
		}
		for(int x=0; x< this->charList->getSize(); x++){
			this->charList->set(x, '\0');
		}
	}
	
	Note::~Note(){
		for(int x=0; x< this->charList->getSize(); x++){
			delete this->charList->getByPos(x);
		}
		delete this->charList;
	}
	
	char Note::getNote(int chr){
		return *this->charList->getByPos(chr);
	}
	
	String Note::getNote(){
		String s;
		for(int x = 0; x < this->charList->getPos(); x++){
			s.concat(*this->charList->getByPos(x));
		}
		return s;
	}
	
	void Note::setPos(int p){
		this->charList->setPos(p);
	}
	
	int Note::getPos(){
		return this->charList->getPos();
	}
	
	int Note::getSize(){
		return this->charList->getSize();
	}
	
	int Note::getFocus(){
		return this->focus;
	}
	
	void Note::setFocus(int Focus){
		this->focus = Focus;
	}
	 
	void Note::add(List<char> *list){
		for(int x=0; x < list->getPos(); x++){
			this->charList->add(*list->getByPos(x));
		}
	}
	
	template<int Size> 
	void Note::add(ArrayList<char,Size> list){
		for(int x=0; x < list.getPos(); x++){
			this->charList->add(*list.getByPos(x));
		}
	}
	
	void Note::add(char *value){
		this->charList->add(value);
		this->focus++;
	}
	
	void Note::add(char *value, int size){
		
		this->focus++;
	}
	
	void Note::add(char value){
		this->charList->add(value);
		this->focus++;
	}
	
	void Note::add(String value){
		
	}
	
	void Note::set(int pos,char value){
		this->charList->set(pos,value);
	}
	
	void Note::set(int pos,char *value){
		this->charList->set(pos,value);		
	}
	
	void Note::set(int pos,String value){
		
	}
	
	char Note::getChar(int x){
		return *this->charList->getByPos(x);
	}
	
	template<>ArrayList<int,20> Note::getCharPositions(char chr){
		int p[20];
		int apply=0;
		for(int x=0; x< this->charList->getPos();x++){
			if(*this->charList->getByPos(x) == chr){
				p[apply] = x;
				apply++;
			}
		}
		
		return ArrayList<int,20>(p,apply);
	}
	
	int Note::getCharSize(char chr){
		int apply=0;
		for(int x=0; x< this->charList->getPos();x++){
			if(*this->charList->getByPos(x) == chr){
				apply++;
			}
		}
		
		return apply;
	}
	
	template<>ArrayList<int,20> Note::getSpacePositions(){
		int p[20];
		int apply=0;
		for(int x=0; x< this->charList->getPos();x++){
			if(*this->charList->getByPos(x) == space){
				p[apply] = x;
				apply++;
			}
		}
		
		return ArrayList<int,20>(p,apply);
	}
	
	int Note::getSpaceSize(){
		int apply=0;
		for(int x=0; x< this->charList->getPos();x++){
			if(*this->charList->getByPos(x) == space){
				apply++;
			}
		}
		
		return apply;
	}
	
	template<>ArrayList<int,20> Note::getStringPositions(String chr){
		/*int p[20];
		int apply=0;
		for(int x=0; x< this->charList->getPos();x++){
			if(*this->charList->getByPos(x) == chr){
				p[apply] = x;
				apply++;
			}
		}
		
		return ArrayList<int,20>(p,apply);*/
	}
	
	int Note::getSpacingSize(){
		int spacing=0;
		for(int x=0; x< this->charList->getPos();x++){
			if(*this->charList->getByPos(x) == space 
				|| *this->charList->getByPos(x) == enter){
				if((*this->charList->getByPos(x+1) != space
					|| *this->charList->getByPos(x+1) != enter )						
						&&  (x+1)< this->charList->getPos()){
					spacing++;
				}
			}
		}
		
		return spacing;
	}
	
	void Note::fixExtraSpace(){
		int xspaces = 0;
		for(int x = (this->charList->getPos()-1); x >= 0; x--){
			if(*this->charList->getByPos(x) == space || *this->charList->getByPos(x) == empty){
				this->charList->set(x, '\0');				
				xspaces++;
			}else{
				break;
			}
		}
		if(xspaces>0){
			this->charList->setPos(this->charList->getPos()-xspaces);
		}
	}
	
	void Note::fixEmptySpaces(){
		this->remove(empty);	
	}
	
	void Note::fixEndLinePoint(){
		if(*this->charList->getByPos(this->charList->getPos()-1) == endLine){
			this->charList->set(this->charList->getPos()-1, empty);
			this->charList->setPos(this->charList->getPos()-1);
		}
		this->remove(empty);	
	}
	
	String Note::fixExtraSpace(String s){
		Note n;
		n = s;
		n.fixExtraSpace();
		return n.getNote();
	}
	
	String Note::fixEmptySpaces(String s){
		Note n;
		n = s;
		n.fixEmptySpaces();
		return n.getNote();
	}
	
	String Note::fixEndLinePoint(String s){
		Note n;
		n = s;
		n.fixEndLinePoint();
		return n.getNote();
	}
	
	template<int Lsize=20>
	ArrayList<String,Lsize> Note::getWords(){
		
	}
	
	String Note::getWord(String s, int pos){
		return Split(s, pos, space);
	}
	
	String Note::getSentence(String s, int pos){
		return Split(s, pos, endLine);
	}
	
	String Note::getParagraph(String s, int pos){
		return Split(s, pos, enter);
	}
	
	String Note::getWord(int pos){
		return Split(this->getNote(), pos, space);
	}
	
	String Note::getSentence(int pos){
		return Split(this->getNote(), pos, endLine);
	}
	
	String Note::getParagraph(int pos){
		return Split(this->getNote(), pos, enter);
	}
	
	bool Note::contain(String s){
		
	}
	
	bool Note::contain(const char *key, int size){
		
	}
	
	bool Note::contain(char key){
		
	}
	
	void Note::reset(){
		
	}
	
	bool Note::remove(const String& s){
		
	}
	
	bool Note::remove(String s){
		
	}
	
	bool Note::remove(char key){
		for(int x = 0; x < this->charList->getPos(); x++){
			if(*this->charList->getByPos(x) == key){
				this->charList->removeByPos(x);
				x--;
			}
		}
	}
	
	bool Note::remove(int pos){
		
	}
	
	bool Note::remove(int pos,char key){
		
	}
	
	bool Note::remove(int pos,String key){
		
	}
  
	String Note::Split(String divide,int parte, char limiter){     
        String return_1="";     
        int delimiter=0;  
        int respuesta_len = divide.length() + 1; 
        char respuesta_array[respuesta_len];
        divide.toCharArray(respuesta_array, respuesta_len);
        for(int i=0; i < respuesta_len; i++){
			if(respuesta_array[i] == limiter){                   
                delimiter++;  
            }
            if((parte == delimiter) && (respuesta_array[i] != limiter)){
                return_1=return_1+respuesta_array[i];
            }
        }
        return return_1;
    }
  
	int Note::SplitLenght(String divide,int parte, char limiter){     
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
  
	String Note::Split(String divide,int parte, char limiter, char fin){     
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
	
	/*
	void Note::removeDelete(char *key){
		
	}
	
	void Note::removeDelete(char key){
		
	}
	
	void Note::removeDeleteByPos(int p){
		
	}*/
	/*
	void Note::operator=(Note note){
		for(int x=0; x< this->charList->getPos();x++){
			this->charList->set(x, '\0');
		}
		int size= note.getNote().length()+1; 
		char Array[size];
        note.getNote().toCharArray(Array, size);        
        
		for(int x=0; x< size;x++){
			this->charList->set(x, Array[x]);
		}
		this->charList->setPos(note.getNote().length());
	}*/
	/*
	void Note::operator=(String s){
		for(int x=0; x< this->charList->getPos();x++){
			this->charList->set(x, '\0');
		}
		int size= s.length()+1; 
		char Array[size];
        s.toCharArray(Array, size);        
        
		for(int x=0; x< size;x++){
			this->charList->set(x, Array[x]);
		}
		this->charList->setPos(s.length());
	}*/
	
	void Note::operator=(const String& s){
		for(int x=0; x< this->charList->getPos();x++){
			this->charList->set(x, '\0');
		}
		int size= s.length()+1; 
		char Array[size];
        s.toCharArray(Array, size);        
        
		for(int x=0; x< size;x++){
			this->charList->set(x, Array[x]);
		}
		this->charList->setPos(s.length());
	}
	
	Note Note::operator+(char chr){
		this->add(chr);
		return *this;
	}
	
	void Note::operator+=(char chr){
		this->add(chr);
	}
	/*
	Note Note::operator+(const char *chr){
		this->add(chr);
		return *this;
	}*/
	
	void Note::operator+=(const String& s){
		int size= s.length(); 
		char Array[size+1];
        s.toCharArray(Array, size+1);        
        
		for(int x=0; x< size;x++){
			this->add(Array[x]);
		}
	}
	
#endif
