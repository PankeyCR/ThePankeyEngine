
#ifndef TR_Note_Testing_hpp
#define TR_Note_Testing_hpp

#include "TestResult.hpp"

#include "Note.hpp"
#include "MemoryRam.hpp"

namespace ame{
	
	TestResult TR_Note_Testing(){
		TestResult result;
		
		#if defined(Note_AVAILABLE)

		{

		Note i_note = "note test";

		if(i_note != "note test"){
			result.catchError(0, "Contructor char* or operator!= has an error");
		}

		}

		{

		Note i_note = "note";
		i_note.addLocalArrayPointer(" ");
		i_note.addLocalArrayPointer("test");
		i_note.addLocalArrayPointer(" ");
		i_note.addLocalArrayPointer("example");

		if(i_note != "note test example"){
			result.catchError(1, "Contructor char* or operator!= has an error");
		}

		}

		{

		Note i_note = "note";
  		Note n_note = i_note.addArrayPointer(" test example");

		if(n_note != "note test example"){
			result.catchError(2, "Contructor char* or operator!= has an error");
		}

		}

		#if defined(ame_ArduinoIDE)
		{

		Note i_note = String("note test example");

		if(i_note != "note test example"){
			result.catchError(3, "Contructor char* or operator!= has an error");
		}

		}
		#endif

		{
		
		Note i_note = "note";
		i_note += " test example";

		if(i_note != "note test example"){
			result.catchError(4, "Contructor char* or operator!= has an error");
		}

		}

		{
		
		Note i_note = 150;

		if(i_note != "150"){
			result.catchError(5, "Contructor int error");
		}

		}

		{
		
		Note i_note = -150;

		if(i_note != "-150"){
			result.catchError(6, "Contructor int error with negative value");
		}

		}

		{
		
		Note i_note = "hi user";
  		Note subNote = i_note.getArrayPart(3);

		if(subNote != "user"){
			result.catchError(7, "Contructor int error with negative value");
		}

		}

		{
		
  		Note i_note = Note("note") + Note(" ") + Note("test example");

		if(i_note != "note test example"){
			result.catchError(8, "Contructor int error with negative value");
		}

		}

		{
		
  		Note i_note = "note test";

		if(i_note.get(0) != 'n' && i_note.get(1) != 'o'){
			result.catchError(9, "get error");
		}

		}

		{
		
		Note i_note = "hi username";
  		Note subNote = i_note.getArrayPart(3, 7);

		if(subNote != "user"){
			result.catchError(10, "subNote error");
		}

		}

		{
		
		Note i_note = 1234567l;

		if(i_note != "1234567"){
			result.catchError(11, "Contructor long error");
		}

		}

		{
		
		Note i_note = 'h';

		if(i_note != "h"){
			result.catchError(12, "Contructor char error");
		}

		}

		{
		
		Note i_note = "hol";
		char c = 'a';
		i_note.addLocalValue(c);

		if(i_note != "hola"){
			result.catchError(13, "addLocalValue error");
		}

		}

		{
		
		Note i_note = "hola ";
  		i_note.addLocalBool(true);

		if(i_note != "hola 1"){
			result.catchError(14, "addLocalBool error");
		}

		}

		{
		
		Note i_note = "user:  hola";
  		i_note.insertLocalBool(6, true);

		if(i_note != "user: 1 hola"){
			result.catchError(15, "insertLocalBool error");
		}

		}

		{
		
		Note i_note = "hola ";
  		i_note.addLocalInt(150);

		if(i_note != "hola 150"){
			result.catchError(16, "addLocalInt error");
		}

		}

		{
		
		Note i_note = "user:  hola";
  		i_note.insertLocalInt(6, 150);

		if(i_note != "user: 150 hola"){
			result.catchError(17, "insertLocalInt error");
		}

		}

		{
		
		Note i_note = "hola ";
  		i_note.addLocalLong(1234567l);

		if(i_note != "hola 1234567"){
			result.catchError(18, "addLocalLong error");
		}

		}

		{
		
		Note i_note = "user:  hola";
  		i_note.insertLocalLong(6, 1234567l);

		if(i_note != "user: 1234567 hola"){
			result.catchError(19, "insertLocalLong error");
		}

		}

		{
		
		Note i_note = "hola ";
  		i_note.addLocalFloat(123.456f);

		if(i_note != "hola 123.4560"){
			result.catchError(20, "addLocalFloat error");
		}

		}

		{
		
		Note i_note = "user:  hola";
  		i_note.insertLocalFloat(6, 123.456f);

		if(i_note != "user: 123.4560 hola"){
			result.catchError(21, Note("insertLocalFloat error: ") + i_note);
		}

		}

		{
		
		Note i_note = true;

		if(i_note.toBool() != true){
			result.catchError(22, "toInt error");
		}

		}

		{
		
		Note i_note = false;

		if(i_note.toBool() != false){
			result.catchError(23, "toInt error");
		}

		}

		{
		
		Note i_note = 123;

		if(i_note.toInt() != 123){
			result.catchError(24, "toInt error");
		}

		}

		{
		
		Note i_note = -123;

		if(i_note.toInt() != -123){
			result.catchError(25, "toInt error");
		}

		}

		{
		
		Note i_note = 1234567l;

		if(i_note.toLong() != 1234567l){
			result.catchError(26, "toLong error");
		}

		}

		{
		
		Note i_note = -1234567l;

		if(i_note.toLong() != -1234567l){
			result.catchError(27, "toLong error");
		}

		}

		{
		
		Note i_note = 123.456f;

		if(i_note.toFloat() != 123.4560f){
			result.catchError(28, Note("toFloat error: ") + Note(i_note.toFloat()));
		}

		}

		{
		
		Note i_note = -123.456f;

		if(i_note.toFloat() != -123.4560f){
			result.catchError(29, Note("toFloat error: ") + Note(i_note.toFloat()));
		}

		}
		
		
		#endif
		
		return result;
	}
}

#endif
