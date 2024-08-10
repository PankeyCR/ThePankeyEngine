
#ifndef TR_Array2D_Testing_hpp
#define TR_Array2D_Testing_hpp

#include "TestResult.hpp"

#include "Array2D.hpp"
#include "MemoryRam.hpp"

namespace higgs{
	
	TestResult TR_Array2D_Testing(){
		TestResult result;
		
		Array2D<int> array(5,10);
		
		if(array.getSizeX() != 5){
			result.catchError(1, "array x should be 10");
		}
		if(array.getSizeY() != 10){
			result.catchError(2, "array y should be 10");
		}
		
		array.fill(33);
		
		if(array.get(0,9) != 33){
			result.catchError(3, "value should be 33");
		}
		
		if(array.get(4,0) != 33){
			result.catchError(3, "value should be 33");
		}
		
		int t_ram_1 = getRamSize();
		
		array.createArray(5,10);
		array.createArray(5,10);
		array.createArray(5,10);
		array.createArray(5,10);
		
		int t_ram_2 = getRamSize();
		
		if(t_ram_1 != t_ram_2){
			result.catchError(4, "ram should be the same size");
		}
		
		array.createArray(2,2);
		
		array.fill(245);
		
		for(int& value : array){
			if(value != 245){
				result.catchError(5, "value should be 245");
			}
		}
		
		return result;
	}
}

#endif
