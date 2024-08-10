
#ifndef ByteArrayHelper_hpp
#define ByteArrayHelper_hpp
#define ByteArrayHelper_AVAILABLE 

#include "ByteArray.hpp"
#include "Note.hpp"
#include "PrimitiveList.hpp"

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "IPAddress.h"
#endif

namespace higgs{
	#if defined(ByteArray_AVAILABLE)
	
	#if defined(Note_AVAILABLE)
	
	Note toNote(const ByteArray& a_byteArray){
		Note i_note;
		for(int x = 0; x < a_byteArray.getPosition(); x++){
			Note i_byte;
			for(int y = 0; y < 8; y++){
				i_byte.insertLocalInt(0, a_byteArray.getBit(x,y));
			}
			i_note.addLocalNote(i_byte);
			if(x >= a_byteArray.getPosition() - 1){
				continue;
			}
			i_note.addLine();
		}
		return i_note;
	}
	
	ByteArray toByteArray(const Note& a_note){
		ByteArray i_byteArray;
		int i_cell_position = 0;
		int i_byte_position = 7;
		for(char f_char : a_note){
			if(a_note.isEndLine(f_char)){
				continue;
			}
			if(i_byte_position == 7){
				i_byteArray.addLocalValue(0);
			}
			Note f_bool = f_char;
			i_byteArray.setBit(i_cell_position, i_byte_position, f_bool.toBool());
			i_byte_position--;
			if(i_byte_position < 0){
				i_cell_position++;
				i_byte_position = 7;
			}
		}
		return i_byteArray;
	}

	#endif
	
	#else
	
		
	#endif
}

#endif