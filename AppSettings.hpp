
#ifndef AppSettings_hpp
	#define AppSettings_hpp

	#include "Note.hpp"

	namespace pankey{
		
		class AppSettings{
			public:
				virtual ~AppSettings(){}
				
				virtual void addInt(const Note& a_name,int a_var)=0;
				virtual void putInt(const Note& a_name, int a_var)=0;
				virtual void setInt(const Note& a_name, int a_var)=0;
				virtual void changeInt(const Note& a_name, int a_var)=0;
				virtual int getInt(const Note& a_name)=0;
				virtual void removeInt(const Note& a_name)=0;
				virtual bool containInt(const Note& a_name)=0;
				
				virtual void addLong(const Note& a_name, long a_var)=0;
				virtual void putLong(const Note& a_name, long a_var)=0;
				virtual void setLong(const Note& a_name, long a_var)=0;
				virtual void changeLong(const Note& a_name, long a_var)=0;
				virtual long getLong(const Note& a_name)=0;
				virtual void removeLong(const Note& a_name)=0;
				virtual bool containLong(const Note& a_name)=0;
				
				virtual void addFloat(const Note& a_name, float a_var)=0;
				virtual void putFloat(const Note& a_name, float a_var)=0;
				virtual void setFloat(const Note& a_name, float a_var)=0;
				virtual void changeFloat(const Note& a_name, float a_var)=0;
				virtual float getFloat(const Note& a_name)=0;
				virtual void removeFloat(const Note& a_name)=0;
				virtual bool containFloat(const Note& a_name)=0;
				
				virtual void addNote(const Note& a_name, const Note& a_var)=0;
				virtual void putNote(const Note& a_name, const Note& a_var)=0;
				virtual void setNote(const Note& a_name, const Note& a_var)=0;
				virtual void changeNote(const Note& a_name, const Note& a_var)=0;
				virtual Note getNote(const Note& a_name)=0;
				virtual void removeNote(const Note& a_name)=0;
				virtual bool containNote(const Note& a_name)=0;
				
				virtual void addBoolean(const Note& a_name, bool a_var)=0;
				virtual void putBoolean(const Note& a_name, bool a_var)=0;
				virtual void setBoolean(const Note& a_name, bool a_var)=0;
				virtual void changeBoolean(const Note& a_name, bool a_var)=0;
				virtual bool getBoolean(const Note& a_name)=0;
				virtual void removeBoolean(const Note& a_name)=0;
				virtual bool containBoolean(const Note& a_name)=0;

				virtual void add(const Note& a_name, var a_var)=0;
				virtual void put(const Note& a_name, var a_var)=0;
				virtual void set(const Note& a_name, var a_var)=0;
				virtual void change(const Note& a_name, var a_var)=0;
				virtual var get(const Note& a_name)=0;
				virtual void remove(const Note& a_name)=0;
				virtual bool contain(const Note& a_name)=0;
		};

	}

#endif
