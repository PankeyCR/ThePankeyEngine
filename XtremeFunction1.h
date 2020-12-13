
#ifndef XtremeFunction1_h
#define XtremeFunction1_h

#include "ArrayList.h"
#include "ModifiableFunction.h"

class XtremeFunction1 : public ModifiableFunction<float,float>{
	public:
		
		XtremeFunction1(){
			this->constants = new ArrayList<float,20>;
			this->variables = new ArrayList<float,200>;
			for(int x=0; x <= 20; x++){
				this->constants->add(new float(0.0f));
			}
			for(int x=0; x <= 200; x++){
				this->variables->add(new float(0.0f));
			}
		}
		
		virtual ~XtremeFunction1(){
			delete this->constants;
			delete this->variables;
		}
    
		//cppObject part
		String getClassName(){
			return "XtremeFunction1";
		}
		String toString(){
			return "XtremeFunction1";
		}
		virtual float f(float x){
			return 	(*this->constants->getByPos(0)) * (*this->variables->getByPos(0) ) * x - (*this->constants->getByPos(0)) * (*this->variables->getByPos(1) ) *x +  (*this->variables->getByPos(2) ) *x -  (*this->variables->getByPos(3) ) *x + (*this->constants->getByPos(0)) * (*this->variables->getByPos(4) ) *x*x - (*this->constants->getByPos(0)) * (*this->variables->getByPos(5) ) *x*x + (*this->constants->getByPos(0)) * (*this->variables->getByPos(6) )  - (*this->constants->getByPos(0)) * (*this->variables->getByPos(7) ) +  (*this->variables->getByPos(8) )  *  (*this->variables->getByPos(9) ) +
					(*this->constants->getByPos(1)) * (*this->variables->getByPos(10)) * x - (*this->constants->getByPos(1)) * (*this->variables->getByPos(11)) *x +  (*this->variables->getByPos(12)) *x -  (*this->variables->getByPos(13)) *x + (*this->constants->getByPos(1)) * (*this->variables->getByPos(14)) *x*x - (*this->constants->getByPos(1)) * (*this->variables->getByPos(15)) *x*x + (*this->constants->getByPos(1)) * (*this->variables->getByPos(16))  - (*this->constants->getByPos(1)) * (*this->variables->getByPos(17)) +  (*this->variables->getByPos(18))  *  (*this->variables->getByPos(19)) +
					(*this->constants->getByPos(2)) * (*this->variables->getByPos(20)) * x - (*this->constants->getByPos(2)) * (*this->variables->getByPos(21)) *x +  (*this->variables->getByPos(22)) *x -  (*this->variables->getByPos(23)) *x + (*this->constants->getByPos(2)) * (*this->variables->getByPos(24)) *x*x - (*this->constants->getByPos(2)) * (*this->variables->getByPos(25)) *x*x + (*this->constants->getByPos(2)) * (*this->variables->getByPos(26))  - (*this->constants->getByPos(2)) * (*this->variables->getByPos(27)) +  (*this->variables->getByPos(28))  *  (*this->variables->getByPos(29)) +
					(*this->constants->getByPos(3)) * (*this->variables->getByPos(30)) * x - (*this->constants->getByPos(3)) * (*this->variables->getByPos(31)) *x +  (*this->variables->getByPos(32)) *x -  (*this->variables->getByPos(33)) *x + (*this->constants->getByPos(3)) * (*this->variables->getByPos(34)) *x*x - (*this->constants->getByPos(3)) * (*this->variables->getByPos(35)) *x*x + (*this->constants->getByPos(3)) * (*this->variables->getByPos(36))  - (*this->constants->getByPos(3)) * (*this->variables->getByPos(37)) +  (*this->variables->getByPos(38))  *  (*this->variables->getByPos(39)) +
					(*this->constants->getByPos(4)) * (*this->variables->getByPos(40)) * x - (*this->constants->getByPos(4)) * (*this->variables->getByPos(41)) *x +  (*this->variables->getByPos(42)) *x -  (*this->variables->getByPos(43)) *x + (*this->constants->getByPos(4)) * (*this->variables->getByPos(44)) *x*x - (*this->constants->getByPos(4)) * (*this->variables->getByPos(45)) *x*x + (*this->constants->getByPos(4)) * (*this->variables->getByPos(46))  - (*this->constants->getByPos(4)) * (*this->variables->getByPos(47)) +  (*this->variables->getByPos(48))  *  (*this->variables->getByPos(49)) +
					(*this->constants->getByPos(5)) * (*this->variables->getByPos(50)) * x - (*this->constants->getByPos(5)) * (*this->variables->getByPos(51)) *x +  (*this->variables->getByPos(52)) *x -  (*this->variables->getByPos(53)) *x + (*this->constants->getByPos(5)) * (*this->variables->getByPos(54)) *x*x - (*this->constants->getByPos(5)) * (*this->variables->getByPos(55)) *x*x + (*this->constants->getByPos(5)) * (*this->variables->getByPos(56))  - (*this->constants->getByPos(5)) * (*this->variables->getByPos(57)) +  (*this->variables->getByPos(58))  *  (*this->variables->getByPos(59)) +
					(*this->constants->getByPos(6)) * (*this->variables->getByPos(60)) * x - (*this->constants->getByPos(6)) * (*this->variables->getByPos(61)) *x +  (*this->variables->getByPos(62)) *x -  (*this->variables->getByPos(63)) *x + (*this->constants->getByPos(6)) * (*this->variables->getByPos(64)) *x*x - (*this->constants->getByPos(6)) * (*this->variables->getByPos(65)) *x*x + (*this->constants->getByPos(6)) * (*this->variables->getByPos(66))  - (*this->constants->getByPos(6)) * (*this->variables->getByPos(67)) +  (*this->variables->getByPos(68))  *  (*this->variables->getByPos(69)) +
					(*this->constants->getByPos(7)) * (*this->variables->getByPos(70)) * x - (*this->constants->getByPos(7)) * (*this->variables->getByPos(71)) *x +  (*this->variables->getByPos(72)) *x -  (*this->variables->getByPos(73)) *x + (*this->constants->getByPos(7)) * (*this->variables->getByPos(74)) *x*x - (*this->constants->getByPos(7)) * (*this->variables->getByPos(75)) *x*x + (*this->constants->getByPos(7)) * (*this->variables->getByPos(76))  - (*this->constants->getByPos(7)) * (*this->variables->getByPos(77)) +  (*this->variables->getByPos(78))  *  (*this->variables->getByPos(79)) +
					(*this->constants->getByPos(8)) * (*this->variables->getByPos(80)) * x - (*this->constants->getByPos(8)) * (*this->variables->getByPos(81)) *x +  (*this->variables->getByPos(82)) *x -  (*this->variables->getByPos(83)) *x + (*this->constants->getByPos(8)) * (*this->variables->getByPos(84)) *x*x - (*this->constants->getByPos(8)) * (*this->variables->getByPos(85)) *x*x + (*this->constants->getByPos(8)) * (*this->variables->getByPos(86))  - (*this->constants->getByPos(8)) * (*this->variables->getByPos(87)) +  (*this->variables->getByPos(88))  *  (*this->variables->getByPos(89)) +
					(*this->constants->getByPos(9)) * (*this->variables->getByPos(90)) * x - (*this->constants->getByPos(9)) * (*this->variables->getByPos(91)) *x +  (*this->variables->getByPos(92)) *x -  (*this->variables->getByPos(93)) *x + (*this->constants->getByPos(9)) * (*this->variables->getByPos(94)) *x*x - (*this->constants->getByPos(9)) * (*this->variables->getByPos(95)) *x*x + (*this->constants->getByPos(9)) * (*this->variables->getByPos(96))  - (*this->constants->getByPos(9)) * (*this->variables->getByPos(97)) +  (*this->variables->getByPos(98))  *  (*this->variables->getByPos(99)) +
					
					(*this->constants->getByPos(10)) * (*this->variables->getByPos(100)) * x - (*this->constants->getByPos(10)) * (*this->variables->getByPos(101)) *x +  (*this->variables->getByPos(102)) *x -  (*this->variables->getByPos(103)) *x + (*this->constants->getByPos(10)) * (*this->variables->getByPos(104)) *x*x - (*this->constants->getByPos(10)) * (*this->variables->getByPos(105)) *x*x + (*this->constants->getByPos(10)) * (*this->variables->getByPos(106))  - (*this->constants->getByPos(10)) * (*this->variables->getByPos(107)) +  (*this->variables->getByPos(108))  *  (*this->variables->getByPos(109)) +
					(*this->constants->getByPos(11)) * (*this->variables->getByPos(110)) * x - (*this->constants->getByPos(11)) * (*this->variables->getByPos(111)) *x +  (*this->variables->getByPos(112)) *x -  (*this->variables->getByPos(113)) *x + (*this->constants->getByPos(11)) * (*this->variables->getByPos(114)) *x*x - (*this->constants->getByPos(11)) * (*this->variables->getByPos(115)) *x*x + (*this->constants->getByPos(11)) * (*this->variables->getByPos(116))  - (*this->constants->getByPos(11)) * (*this->variables->getByPos(117)) +  (*this->variables->getByPos(118))  *  (*this->variables->getByPos(119)) +
					(*this->constants->getByPos(12)) * (*this->variables->getByPos(120)) * x - (*this->constants->getByPos(12)) * (*this->variables->getByPos(121)) *x +  (*this->variables->getByPos(122)) *x -  (*this->variables->getByPos(123)) *x + (*this->constants->getByPos(12)) * (*this->variables->getByPos(124)) *x*x - (*this->constants->getByPos(12)) * (*this->variables->getByPos(125)) *x*x + (*this->constants->getByPos(12)) * (*this->variables->getByPos(126))  - (*this->constants->getByPos(12)) * (*this->variables->getByPos(127)) +  (*this->variables->getByPos(128))  *  (*this->variables->getByPos(129)) +
					(*this->constants->getByPos(13)) * (*this->variables->getByPos(130)) * x - (*this->constants->getByPos(13)) * (*this->variables->getByPos(131)) *x +  (*this->variables->getByPos(132)) *x -  (*this->variables->getByPos(133)) *x + (*this->constants->getByPos(13)) * (*this->variables->getByPos(134)) *x*x - (*this->constants->getByPos(13)) * (*this->variables->getByPos(135)) *x*x + (*this->constants->getByPos(13)) * (*this->variables->getByPos(136))  - (*this->constants->getByPos(13)) * (*this->variables->getByPos(137)) +  (*this->variables->getByPos(138))  *  (*this->variables->getByPos(139)) +
					(*this->constants->getByPos(14)) * (*this->variables->getByPos(140)) * x - (*this->constants->getByPos(14)) * (*this->variables->getByPos(141)) *x +  (*this->variables->getByPos(142)) *x -  (*this->variables->getByPos(143)) *x + (*this->constants->getByPos(14)) * (*this->variables->getByPos(144)) *x*x - (*this->constants->getByPos(14)) * (*this->variables->getByPos(145)) *x*x + (*this->constants->getByPos(14)) * (*this->variables->getByPos(146))  - (*this->constants->getByPos(14)) * (*this->variables->getByPos(147)) +  (*this->variables->getByPos(148))  *  (*this->variables->getByPos(149)) +
					(*this->constants->getByPos(15)) * (*this->variables->getByPos(150)) * x - (*this->constants->getByPos(15)) * (*this->variables->getByPos(151)) *x +  (*this->variables->getByPos(152)) *x -  (*this->variables->getByPos(153)) *x + (*this->constants->getByPos(15)) * (*this->variables->getByPos(154)) *x*x - (*this->constants->getByPos(15)) * (*this->variables->getByPos(155)) *x*x + (*this->constants->getByPos(15)) * (*this->variables->getByPos(156))  - (*this->constants->getByPos(15)) * (*this->variables->getByPos(157)) +  (*this->variables->getByPos(158))  *  (*this->variables->getByPos(159)) +
					(*this->constants->getByPos(16)) * (*this->variables->getByPos(160)) * x - (*this->constants->getByPos(16)) * (*this->variables->getByPos(161)) *x +  (*this->variables->getByPos(162)) *x -  (*this->variables->getByPos(163)) *x + (*this->constants->getByPos(16)) * (*this->variables->getByPos(164)) *x*x - (*this->constants->getByPos(16)) * (*this->variables->getByPos(165)) *x*x + (*this->constants->getByPos(16)) * (*this->variables->getByPos(166))  - (*this->constants->getByPos(16)) * (*this->variables->getByPos(167)) +  (*this->variables->getByPos(168))  *  (*this->variables->getByPos(169)) +
					(*this->constants->getByPos(17)) * (*this->variables->getByPos(170)) * x - (*this->constants->getByPos(17)) * (*this->variables->getByPos(171)) *x +  (*this->variables->getByPos(172)) *x -  (*this->variables->getByPos(173)) *x + (*this->constants->getByPos(17)) * (*this->variables->getByPos(174)) *x*x - (*this->constants->getByPos(17)) * (*this->variables->getByPos(175)) *x*x + (*this->constants->getByPos(17)) * (*this->variables->getByPos(176))  - (*this->constants->getByPos(17)) * (*this->variables->getByPos(177)) +  (*this->variables->getByPos(178))  *  (*this->variables->getByPos(179)) +
					(*this->constants->getByPos(18)) * (*this->variables->getByPos(180)) * x - (*this->constants->getByPos(18)) * (*this->variables->getByPos(181)) *x +  (*this->variables->getByPos(182)) *x -  (*this->variables->getByPos(183)) *x + (*this->constants->getByPos(18)) * (*this->variables->getByPos(184)) *x*x - (*this->constants->getByPos(18)) * (*this->variables->getByPos(185)) *x*x + (*this->constants->getByPos(18)) * (*this->variables->getByPos(186))  - (*this->constants->getByPos(18)) * (*this->variables->getByPos(187)) +  (*this->variables->getByPos(188))  *  (*this->variables->getByPos(189)) +
					(*this->constants->getByPos(19)) * (*this->variables->getByPos(190)) * x - (*this->constants->getByPos(19)) * (*this->variables->getByPos(191)) *x +  (*this->variables->getByPos(192)) *x -  (*this->variables->getByPos(193)) *x + (*this->constants->getByPos(19)) * (*this->variables->getByPos(194)) *x*x - (*this->constants->getByPos(19)) * (*this->variables->getByPos(195)) *x*x + (*this->constants->getByPos(19)) * (*this->variables->getByPos(196))  - (*this->constants->getByPos(19)) * (*this->variables->getByPos(197)) +  (*this->variables->getByPos(198))  *  (*this->variables->getByPos(199))
					
					;
		}
		
		virtual int getIterationSize(){
			return 200;
		}
		virtual bool instanceof(String name){return name == "XtremeFunction1" || name == "ModifiableFunction" || name == "Function";}
		
	protected:
		
		
	
};

#endif 
