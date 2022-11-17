
#ifndef TR_Array_Testing_hpp
#define TR_Array_Testing_hpp

#include "TestResult.hpp"

#include "Array.hpp"
#include "Cast.hpp"
#include "MemoryRam.hpp"

namespace ame{
	
	TestResult TR_Array_Testing(){
		TestResult result;
  
		{

		Array<int> array_0;

		array_0.addLocalValue(1);
		array_0.addLocalValue(2);
		array_0.addLocalValue(3);
		array_0.addLocalValue(4);
		array_0.addLocalValue(5);

		if(array_0[0] != 1 || array_0[1] != 2 || array_0[2] != 3 || array_0[3] !=4 || array_0[4] != 5){
			result.catchError(0, "addLocalValue is not working because the array[0] dont catches the value");
		}

  		array_0.set(2, 91);

		if(array_0[2] != 91){
			result.catchError(1, "set method didnt change the value");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};

		if(array_1[0] != 1 || array_1[1] != 2 || array_1[2] != 3 || array_1[3] !=4 || array_1[4] != 5){
			result.catchError(2, "Contructor that initialize the array class with args... is not working because the array[0] dont catches the value");
		}
		
		Array<int> array_2 = array_1;

		if(array_2[0] != 1 || array_2[1] != 2 || array_2[2] != 3 || array_2[3] !=4 || array_2[4] != 5){
			result.catchError(3, "Contructor that initialize the array class with args... is not working because the array[0] dont catches the value");
		}

  		Array<int> array_3 = array_2.addArray(array_1);

		if(array_3.getPosition() != 10){
			result.catchError(4, "addArray didnt work");
		}

		if(array_3[0] != 1 || array_3[1] != 2 || array_3[2] != 3 || array_3[3] !=4 || array_3[4] != 5 ||  array_3[5] != 1 || array_3[6] != 2 || array_3[7] != 3 || array_3[8] !=4 || array_3[9] != 5){
			result.catchError(5, "addArray didnt work");
		}
  
  		array_3.addLocal();

		if(array_3.getPosition() != 20){
			result.catchError(6, "addLocal didnt work");
		}

		array_3.addLocalValue(15);
  
		if(!array_3.contain(15)){
			result.catchError(7, "array didnt contain value 15");
		}
  
		int index = array_3.getFirstIndex(3);
  
		if(index != 2){
			result.catchError(8, "counld capture first index");
		}
  
		int last_index = array_3.getLastIndex(3);
  
		if(index == -1){
			result.catchError(8, "counld capture last index");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};
		
		array_1.remove(2);//position of the array

		if(array_1.contain(3)){
			result.catchError(9, "remove didnt work because it did contain a 3 value");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 2, 4, 5};

		array_1.removeFirst(2);//value of the array

		if(array_1[1] == 2){
			result.catchError(10, "removeFirst didnt work");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 2, 4, 5};

		array_1.removeLast(2);//value of the array

		if(array_1[3] == 2){
			result.catchError(11, "removeLast didnt work");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};

		array_1 = Array<int>(5,4,3,2,1);

		if(array_1[0] != 5 || array_1[1] != 4 || array_1[2] != 3 || array_1[3] !=2 || array_1[4] != 1){
			result.catchError(12, "operator= error");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};

		array_1 = move(Array<int>(5,4,3,2,1));

		if(array_1[0] != 5 || array_1[1] != 4 || array_1[2] != 3 || array_1[3] !=2 || array_1[4] != 1){
			result.catchError(12, "operator=&& error");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};

		array_1 = 5;

		if(array_1[0] != 5){
			result.catchError(12, "operator= value error");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};

		array_1.remove(1,3);//1 = start, 3 = size

		if(array_1[0] != 1 || array_1[1] != 5){
			result.catchError(12, "remove error");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};

		array_1.insertLocalValue(2, 150);

		if(array_1[2] != 150){
			result.catchError(12, "insertLocalValue error");
		}

		}

		{

		Array<int> array_1 = { 1, 2, 3, 4, 5};
		Array<int> array_2 = { 1, 2, 3, 4, 5};

  		array_1.insertLocalArray(2, array_2);

		if(array_1[2] != 1){
			result.catchError(12, "insertLocalArray error");
		}

		}
		
		
		return result;
	}
}

#endif
