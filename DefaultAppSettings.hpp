
#ifndef DefaultAppSettings_hpp
	#define DefaultAppSettings_hpp

	#include "AppSettings.hpp"
	#include "PrimitiveRawMap.hpp"

	namespace higgs{

		class DefaultAppSettings : public AppSettings{
			public:
				DefaultAppSettings(){}

				virtual ~DefaultAppSettings(){}
				
				virtual void addInt(const Note& a_name, int a_var){
					m_int_map.add(a_name, a_var);
				}

				virtual void putInt(const Note& a_name, int a_var){
					m_int_map.put(a_name, a_var);
				}

				virtual void setInt(const Note& a_name, int a_var){
					m_int_map.set(a_name, a_var);
				}

				virtual void changeInt(const Note& a_name, int a_var){
					m_int_map.remove(a_name);
					m_int_map.add(a_name, a_var);
				}

				virtual int getInt(const Note& a_name){
					return m_int_map.get(a_name);
				}

				virtual void removeInt(const Note& a_name){
					m_int_map.removeDeleteByKeyLValue(a_name);
				}

				virtual bool containInt(const Note& a_name){
					return m_int_map.contain(a_name);
				}
				
				virtual void addLong(const Note& a_name, long a_var){
					m_long_map.add(a_name, a_var);
				}

				virtual void putLong(const Note& a_name, long a_var){
					m_long_map.put(a_name, a_var);
				}

				virtual void setLong(const Note& a_name, long a_var){
					m_long_map.set(a_name, a_var);
				}

				virtual void changeLong(const Note& a_name, long a_var){
					m_long_map.remove(a_name);
					m_long_map.add(a_name, a_var);
				}

				virtual long getLong(const Note& a_name){
					return m_long_map.get(a_name);
				}

				virtual void removeLong(const Note& a_name){
					m_long_map.removeDeleteByKeyLValue(a_name);
				}

				virtual bool containLong(const Note& a_name){
					return m_long_map.contain(a_name);
				}
				
				virtual void addFloat(const Note& a_name, float a_var){
					m_float_map.add(a_name, a_var);
				}

				virtual void putFloat(const Note& a_name, float a_var){
					m_float_map.put(a_name, a_var);
				}

				virtual void setFloat(const Note& a_name, float a_var){
					m_float_map.set(a_name, a_var);
				}

				virtual void changeFloat(const Note& a_name, float a_var){
					m_float_map.remove(a_name);
					m_float_map.add(a_name, a_var);
				}

				virtual float getFloat(const Note& a_name){
					return m_float_map.get(a_name);
				}

				virtual void removeFloat(const Note& a_name){
					m_float_map.removeDeleteByKeyLValue(a_name);
				}

				virtual bool containFloat(const Note& a_name){
					return m_float_map.contain(a_name);
				}
				
				virtual void addNote(const Note& a_name, const Note& a_var){
					m_note_map.add(a_name, a_var);
				}

				virtual void putNote(const Note& a_name, const Note& a_var){
					m_note_map.put(a_name, a_var);
				}

				virtual void setNote(const Note& a_name, const Note& a_var){
					m_note_map.set(a_name, a_var);
				}

				virtual void changeNote(const Note& a_name, const Note& a_var){
					m_note_map.remove(a_name);
					m_note_map.add(a_name, a_var);
				}

				virtual Note getNote(const Note& a_name){
					return m_note_map.get(a_name);
				}

				virtual void removeNote(const Note& a_name){
					m_note_map.removeDeleteByKeyLValue(a_name);
				}

				virtual bool containNote(const Note& a_name){
					return m_note_map.contain(a_name);
				}
				
				virtual void addBoolean(const Note& a_name, bool a_var){
					m_boolean_map.add(a_name, a_var);
				}

				virtual void putBoolean(const Note& a_name, bool a_var){
					m_boolean_map.put(a_name, a_var);
				}

				virtual void setBoolean(const Note& a_name, bool a_var){
					m_boolean_map.set(a_name, a_var);
				}

				virtual void changeBoolean(const Note& a_name, bool a_var){
					m_boolean_map.remove(a_name);
					m_boolean_map.add(a_name, a_var);
				}

				virtual bool getBoolean(const Note& a_name){
					return m_boolean_map.get(a_name);
				}

				virtual void removeBoolean(const Note& a_name){
					m_boolean_map.removeDeleteByKeyLValue(a_name);
				}

				virtual bool containBoolean(const Note& a_name){
					return m_boolean_map.contain(a_name);
				}
				
				virtual void add(const Note& a_name, var a_var){
					m_var_map.add(a_name, a_var);
				}

				virtual void put(const Note& a_name, var a_var){
					m_var_map.put(a_name, a_var);
				}

				virtual void set(const Note& a_name, var a_var){
					m_var_map.set(a_name, a_var);
				}

				virtual void change(const Note& a_name, var a_var){
					m_var_map.remove(a_name);
					m_var_map.add(a_name, a_var);
				}

				virtual var get(const Note& a_name){
					return m_var_map.get(a_name);
				}

				virtual void remove(const Note& a_name){
					m_var_map.removeDeleteByKeyLValue(a_name);
				}

				virtual bool contain(const Note& a_name){
					return m_var_map.contain(a_name);
				}
				
				
			protected:
				PrimitiveRawMap<Note,int> m_int_map;
				PrimitiveRawMap<Note,float> m_long_map;
				PrimitiveRawMap<Note,float> m_float_map;
				PrimitiveRawMap<Note,Note> m_note_map;
				PrimitiveRawMap<Note,bool> m_boolean_map;
				PrimitiveRawMap<Note,var> m_var_map;
		};

	}

#endif