
#ifndef XtremeFuntion1_cpp
#define XtremeFuntion1_cpp

#include "XtremeFuntion1.h"


	
	XtremeFuntion1::XtremeFuntion1(){
		for(int x=0; x < 21; x++){
			vars.add(0.0f);
		}
		for(int x=0; x < 201; x++){
			learningvars.add(0.0f);
		}
	}
	
	XtremeFuntion1::~XtremeFuntion1(){
		
	}
		
	//cppObject part
	String XtremeFuntion1::getClassName(){
		return "XtremeFuntion1";
	}
	String XtremeFuntion1::toString(){
		return "XtremeFuntion1";
	}
	XtremeFuntion1* XtremeFuntion1::clone(){
		return this;
	}
	
	void XtremeFuntion1::set(int p, float var){
		vars.set(p, var);
	}
	
	void XtremeFuntion1::set(String name, float var){
		
	}
		
	int XtremeFuntion1::getIterationSize(){
		return 200;
	}
		
	float XtremeFuntion1::getValue(){
		learningvars.setIteration(this->getIteration());
		return learningvars.getValue();
	}
		
	float *XtremeFuntion1::getPointer(){
		learningvars.setIteration(this->getIteration());
		return learningvars.getPointer();
	}
		
	String XtremeFuntion1::getName(){
		return "";
	}
		
	bool XtremeFuntion1::isModifiable(){
		return true;
	}
		
	void XtremeFuntion1::set(float var){
		learningvars.setIteration(this->getIteration());
		learningvars.set(var);
	}
	
	float XtremeFuntion1::f(float x){
		return 	(*vars.getByPos(0)) * (*learningvars.getByPos(0) ) * x - (*vars.getByPos(0)) * (*learningvars.getByPos(1) ) *x +  (*learningvars.getByPos(2) ) *x -  (*learningvars.getByPos(3) ) *x + (*vars.getByPos(0)) * (*learningvars.getByPos(4) ) *x*x - (*vars.getByPos(0)) * (*learningvars.getByPos(5) ) *x*x + (*vars.getByPos(0)) * (*learningvars.getByPos(6) )  - (*vars.getByPos(0)) * (*learningvars.getByPos(7) ) +  (*learningvars.getByPos(8) )  *  (*learningvars.getByPos(9) ) +
				(*vars.getByPos(1)) * (*learningvars.getByPos(10)) * x - (*vars.getByPos(1)) * (*learningvars.getByPos(11)) *x +  (*learningvars.getByPos(12)) *x -  (*learningvars.getByPos(13)) *x + (*vars.getByPos(1)) * (*learningvars.getByPos(14)) *x*x - (*vars.getByPos(1)) * (*learningvars.getByPos(15)) *x*x + (*vars.getByPos(1)) * (*learningvars.getByPos(16))  - (*vars.getByPos(1)) * (*learningvars.getByPos(17)) +  (*learningvars.getByPos(18))  *  (*learningvars.getByPos(19)) +
				(*vars.getByPos(2)) * (*learningvars.getByPos(20)) * x - (*vars.getByPos(2)) * (*learningvars.getByPos(21)) *x +  (*learningvars.getByPos(22)) *x -  (*learningvars.getByPos(23)) *x + (*vars.getByPos(2)) * (*learningvars.getByPos(24)) *x*x - (*vars.getByPos(2)) * (*learningvars.getByPos(25)) *x*x + (*vars.getByPos(2)) * (*learningvars.getByPos(26))  - (*vars.getByPos(2)) * (*learningvars.getByPos(27)) +  (*learningvars.getByPos(28))  *  (*learningvars.getByPos(29)) +
				(*vars.getByPos(3)) * (*learningvars.getByPos(30)) * x - (*vars.getByPos(3)) * (*learningvars.getByPos(31)) *x +  (*learningvars.getByPos(32)) *x -  (*learningvars.getByPos(33)) *x + (*vars.getByPos(3)) * (*learningvars.getByPos(34)) *x*x - (*vars.getByPos(3)) * (*learningvars.getByPos(35)) *x*x + (*vars.getByPos(3)) * (*learningvars.getByPos(36))  - (*vars.getByPos(3)) * (*learningvars.getByPos(37)) +  (*learningvars.getByPos(38))  *  (*learningvars.getByPos(39)) +
				(*vars.getByPos(4)) * (*learningvars.getByPos(40)) * x - (*vars.getByPos(4)) * (*learningvars.getByPos(41)) *x +  (*learningvars.getByPos(42)) *x -  (*learningvars.getByPos(43)) *x + (*vars.getByPos(4)) * (*learningvars.getByPos(44)) *x*x - (*vars.getByPos(4)) * (*learningvars.getByPos(45)) *x*x + (*vars.getByPos(4)) * (*learningvars.getByPos(46))  - (*vars.getByPos(4)) * (*learningvars.getByPos(47)) +  (*learningvars.getByPos(48))  *  (*learningvars.getByPos(49)) +
				(*vars.getByPos(5)) * (*learningvars.getByPos(50)) * x - (*vars.getByPos(5)) * (*learningvars.getByPos(51)) *x +  (*learningvars.getByPos(52)) *x -  (*learningvars.getByPos(53)) *x + (*vars.getByPos(5)) * (*learningvars.getByPos(54)) *x*x - (*vars.getByPos(5)) * (*learningvars.getByPos(55)) *x*x + (*vars.getByPos(5)) * (*learningvars.getByPos(56))  - (*vars.getByPos(5)) * (*learningvars.getByPos(57)) +  (*learningvars.getByPos(58))  *  (*learningvars.getByPos(59)) +
				(*vars.getByPos(6)) * (*learningvars.getByPos(60)) * x - (*vars.getByPos(6)) * (*learningvars.getByPos(61)) *x +  (*learningvars.getByPos(62)) *x -  (*learningvars.getByPos(63)) *x + (*vars.getByPos(6)) * (*learningvars.getByPos(64)) *x*x - (*vars.getByPos(6)) * (*learningvars.getByPos(65)) *x*x + (*vars.getByPos(6)) * (*learningvars.getByPos(66))  - (*vars.getByPos(6)) * (*learningvars.getByPos(67)) +  (*learningvars.getByPos(68))  *  (*learningvars.getByPos(69)) +
				(*vars.getByPos(7)) * (*learningvars.getByPos(70)) * x - (*vars.getByPos(7)) * (*learningvars.getByPos(71)) *x +  (*learningvars.getByPos(72)) *x -  (*learningvars.getByPos(73)) *x + (*vars.getByPos(7)) * (*learningvars.getByPos(74)) *x*x - (*vars.getByPos(7)) * (*learningvars.getByPos(75)) *x*x + (*vars.getByPos(7)) * (*learningvars.getByPos(76))  - (*vars.getByPos(7)) * (*learningvars.getByPos(77)) +  (*learningvars.getByPos(78))  *  (*learningvars.getByPos(79)) +
				(*vars.getByPos(8)) * (*learningvars.getByPos(80)) * x - (*vars.getByPos(8)) * (*learningvars.getByPos(81)) *x +  (*learningvars.getByPos(82)) *x -  (*learningvars.getByPos(83)) *x + (*vars.getByPos(8)) * (*learningvars.getByPos(84)) *x*x - (*vars.getByPos(8)) * (*learningvars.getByPos(85)) *x*x + (*vars.getByPos(8)) * (*learningvars.getByPos(86))  - (*vars.getByPos(8)) * (*learningvars.getByPos(87)) +  (*learningvars.getByPos(88))  *  (*learningvars.getByPos(89)) +
				(*vars.getByPos(9)) * (*learningvars.getByPos(90)) * x - (*vars.getByPos(9)) * (*learningvars.getByPos(91)) *x +  (*learningvars.getByPos(92)) *x -  (*learningvars.getByPos(93)) *x + (*vars.getByPos(9)) * (*learningvars.getByPos(94)) *x*x - (*vars.getByPos(9)) * (*learningvars.getByPos(95)) *x*x + (*vars.getByPos(9)) * (*learningvars.getByPos(96))  - (*vars.getByPos(9)) * (*learningvars.getByPos(97)) +  (*learningvars.getByPos(98))  *  (*learningvars.getByPos(99)) +
				
				(*vars.getByPos(10)) * (*learningvars.getByPos(100)) * x - (*vars.getByPos(10)) * (*learningvars.getByPos(101)) *x +  (*learningvars.getByPos(102)) *x -  (*learningvars.getByPos(103)) *x + (*vars.getByPos(10)) * (*learningvars.getByPos(104)) *x*x - (*vars.getByPos(10)) * (*learningvars.getByPos(105)) *x*x + (*vars.getByPos(10)) * (*learningvars.getByPos(106))  - (*vars.getByPos(10)) * (*learningvars.getByPos(107)) +  (*learningvars.getByPos(108))  *  (*learningvars.getByPos(109)) +
				(*vars.getByPos(11)) * (*learningvars.getByPos(110)) * x - (*vars.getByPos(11)) * (*learningvars.getByPos(111)) *x +  (*learningvars.getByPos(112)) *x -  (*learningvars.getByPos(113)) *x + (*vars.getByPos(11)) * (*learningvars.getByPos(114)) *x*x - (*vars.getByPos(11)) * (*learningvars.getByPos(115)) *x*x + (*vars.getByPos(11)) * (*learningvars.getByPos(116))  - (*vars.getByPos(11)) * (*learningvars.getByPos(117)) +  (*learningvars.getByPos(118))  *  (*learningvars.getByPos(119)) +
				(*vars.getByPos(12)) * (*learningvars.getByPos(120)) * x - (*vars.getByPos(12)) * (*learningvars.getByPos(121)) *x +  (*learningvars.getByPos(122)) *x -  (*learningvars.getByPos(123)) *x + (*vars.getByPos(12)) * (*learningvars.getByPos(124)) *x*x - (*vars.getByPos(12)) * (*learningvars.getByPos(125)) *x*x + (*vars.getByPos(12)) * (*learningvars.getByPos(126))  - (*vars.getByPos(12)) * (*learningvars.getByPos(127)) +  (*learningvars.getByPos(128))  *  (*learningvars.getByPos(129)) +
				(*vars.getByPos(13)) * (*learningvars.getByPos(130)) * x - (*vars.getByPos(13)) * (*learningvars.getByPos(131)) *x +  (*learningvars.getByPos(132)) *x -  (*learningvars.getByPos(133)) *x + (*vars.getByPos(13)) * (*learningvars.getByPos(134)) *x*x - (*vars.getByPos(13)) * (*learningvars.getByPos(135)) *x*x + (*vars.getByPos(13)) * (*learningvars.getByPos(136))  - (*vars.getByPos(13)) * (*learningvars.getByPos(137)) +  (*learningvars.getByPos(138))  *  (*learningvars.getByPos(139)) +
				(*vars.getByPos(14)) * (*learningvars.getByPos(140)) * x - (*vars.getByPos(14)) * (*learningvars.getByPos(141)) *x +  (*learningvars.getByPos(142)) *x -  (*learningvars.getByPos(143)) *x + (*vars.getByPos(14)) * (*learningvars.getByPos(144)) *x*x - (*vars.getByPos(14)) * (*learningvars.getByPos(145)) *x*x + (*vars.getByPos(14)) * (*learningvars.getByPos(146))  - (*vars.getByPos(14)) * (*learningvars.getByPos(147)) +  (*learningvars.getByPos(148))  *  (*learningvars.getByPos(149)) +
				(*vars.getByPos(15)) * (*learningvars.getByPos(150)) * x - (*vars.getByPos(15)) * (*learningvars.getByPos(151)) *x +  (*learningvars.getByPos(152)) *x -  (*learningvars.getByPos(153)) *x + (*vars.getByPos(15)) * (*learningvars.getByPos(154)) *x*x - (*vars.getByPos(15)) * (*learningvars.getByPos(155)) *x*x + (*vars.getByPos(15)) * (*learningvars.getByPos(156))  - (*vars.getByPos(15)) * (*learningvars.getByPos(157)) +  (*learningvars.getByPos(158))  *  (*learningvars.getByPos(159)) +
				(*vars.getByPos(16)) * (*learningvars.getByPos(160)) * x - (*vars.getByPos(16)) * (*learningvars.getByPos(161)) *x +  (*learningvars.getByPos(162)) *x -  (*learningvars.getByPos(163)) *x + (*vars.getByPos(16)) * (*learningvars.getByPos(164)) *x*x - (*vars.getByPos(16)) * (*learningvars.getByPos(165)) *x*x + (*vars.getByPos(16)) * (*learningvars.getByPos(166))  - (*vars.getByPos(16)) * (*learningvars.getByPos(167)) +  (*learningvars.getByPos(168))  *  (*learningvars.getByPos(169)) +
				(*vars.getByPos(17)) * (*learningvars.getByPos(170)) * x - (*vars.getByPos(17)) * (*learningvars.getByPos(171)) *x +  (*learningvars.getByPos(172)) *x -  (*learningvars.getByPos(173)) *x + (*vars.getByPos(17)) * (*learningvars.getByPos(174)) *x*x - (*vars.getByPos(17)) * (*learningvars.getByPos(175)) *x*x + (*vars.getByPos(17)) * (*learningvars.getByPos(176))  - (*vars.getByPos(17)) * (*learningvars.getByPos(177)) +  (*learningvars.getByPos(178))  *  (*learningvars.getByPos(179)) +
				(*vars.getByPos(18)) * (*learningvars.getByPos(180)) * x - (*vars.getByPos(18)) * (*learningvars.getByPos(181)) *x +  (*learningvars.getByPos(182)) *x -  (*learningvars.getByPos(183)) *x + (*vars.getByPos(18)) * (*learningvars.getByPos(184)) *x*x - (*vars.getByPos(18)) * (*learningvars.getByPos(185)) *x*x + (*vars.getByPos(18)) * (*learningvars.getByPos(186))  - (*vars.getByPos(18)) * (*learningvars.getByPos(187)) +  (*learningvars.getByPos(188))  *  (*learningvars.getByPos(189)) +
				(*vars.getByPos(19)) * (*learningvars.getByPos(190)) * x - (*vars.getByPos(19)) * (*learningvars.getByPos(191)) *x +  (*learningvars.getByPos(192)) *x -  (*learningvars.getByPos(193)) *x + (*vars.getByPos(19)) * (*learningvars.getByPos(194)) *x*x - (*vars.getByPos(19)) * (*learningvars.getByPos(195)) *x*x + (*vars.getByPos(19)) * (*learningvars.getByPos(196))  - (*vars.getByPos(19)) * (*learningvars.getByPos(197)) +  (*learningvars.getByPos(198))  *  (*learningvars.getByPos(199))
				
				;
	}
	
	
	
	
	
	
	
	
#endif 
