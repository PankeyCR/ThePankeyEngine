
#include "ame_Enviroment.hpp"

#if defined(DISABLE_XtremeFunction1)
	#define XtremeFunction1_hpp
#endif

#ifndef XtremeFunction1_hpp
#define XtremeFunction1_hpp
#define XtremeFunction1_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "ModifiableFunction.hpp"

#ifdef XtremeFunction1LogApp
	#include "Logger.hpp"
	#define XtremeFunction1Log(name,method,type,mns) Log(name,method,type,mns)
#else
	#define XtremeFunction1Log(name,method,type,mns)
#endif

namespace ame{

template<class T, class... args>
class XtremeFunction1 : public ModifiableFunction<T,args...>{
	public:
		
		XtremeFunction1(){
			this->constants = new PrimitiveList<T>;
			this->multivariables = new PrimitiveList<T>;
			this->modifiablevariables = new PrimitiveList<T>;
			for(int x=0; x <= 20; x++){
				this->constants->addPointer(new T());
			}
			for(int x=0; x <= 200; x++){
				this->modifiablevariables->addPointer(new T());
			}
		}
		
		virtual ~XtremeFunction1(){
			delete this->constants;
			delete this->multivariables;
			delete this->modifiablevariables;
		}
    
		//cppObject part
		cppObjectClass* getClass(){
			return Class<XtremeFunction1>::classType;
		}
		String toString(){
			return "XtremeFunction1";
		}
		virtual T f(args... a){
			XtremeFunction1Log("XtremeFunction1", "f", "println","");
			this->multivariables->resetDelete();
			this->multivariables->addPack(a...);
			T t;
			for(int x = 0; x < this->multivariables->getPosition(); x++){
				XtremeFunction1Log("XtremeFunction1", "f", "println",String(x));
				T xt = *this->multivariables->getByPosition(x);
				for(int x2 = 0; x2 < this->constants->getPosition(); x2++){
					T ct = *this->constants->getByPosition(x2);
					t += ct * xt;
				}
				for(int x3 = 0; x3 < this->modifiablevariables->getPosition(); x3++){
					T mt = *this->modifiablevariables->getByPosition(x3);
					t += mt * xt;
				}
			}
			XtremeFunction1Log("XtremeFunction1", "f", "println",String(t));
			return t;
			// return 	(*this->constants->getByPosition(0)) * (*this->modifiablevariables->getByPosition(0) ) * x - (*this->constants->getByPosition(0)) * (*this->modifiablevariables->getByPosition(1) ) *x +  (*this->modifiablevariables->getByPosition(2) ) *x -  (*this->modifiablevariables->getByPosition(3) ) *x + (*this->constants->getByPosition(0)) * (*this->modifiablevariables->getByPosition(4) ) *x*x - (*this->constants->getByPosition(0)) * (*this->modifiablevariables->getByPosition(5) ) *x*x + (*this->constants->getByPosition(0)) * (*this->modifiablevariables->getByPosition(6) )  - (*this->constants->getByPosition(0)) * (*this->modifiablevariables->getByPosition(7) ) +  (*this->modifiablevariables->getByPosition(8) )  *  (*this->modifiablevariables->getByPosition(9) ) +
					// (*this->constants->getByPosition(1)) * (*this->modifiablevariables->getByPosition(10)) * x - (*this->constants->getByPosition(1)) * (*this->modifiablevariables->getByPosition(11)) *x +  (*this->modifiablevariables->getByPosition(12)) *x -  (*this->modifiablevariables->getByPosition(13)) *x + (*this->constants->getByPosition(1)) * (*this->modifiablevariables->getByPosition(14)) *x*x - (*this->constants->getByPosition(1)) * (*this->modifiablevariables->getByPosition(15)) *x*x + (*this->constants->getByPosition(1)) * (*this->modifiablevariables->getByPosition(16))  - (*this->constants->getByPosition(1)) * (*this->modifiablevariables->getByPosition(17)) +  (*this->modifiablevariables->getByPosition(18))  *  (*this->modifiablevariables->getByPosition(19)) +
					// (*this->constants->getByPosition(2)) * (*this->modifiablevariables->getByPosition(20)) * x - (*this->constants->getByPosition(2)) * (*this->modifiablevariables->getByPosition(21)) *x +  (*this->modifiablevariables->getByPosition(22)) *x -  (*this->modifiablevariables->getByPosition(23)) *x + (*this->constants->getByPosition(2)) * (*this->modifiablevariables->getByPosition(24)) *x*x - (*this->constants->getByPosition(2)) * (*this->modifiablevariables->getByPosition(25)) *x*x + (*this->constants->getByPosition(2)) * (*this->modifiablevariables->getByPosition(26))  - (*this->constants->getByPosition(2)) * (*this->modifiablevariables->getByPosition(27)) +  (*this->modifiablevariables->getByPosition(28))  *  (*this->modifiablevariables->getByPosition(29)) +
					// (*this->constants->getByPosition(3)) * (*this->modifiablevariables->getByPosition(30)) * x - (*this->constants->getByPosition(3)) * (*this->modifiablevariables->getByPosition(31)) *x +  (*this->modifiablevariables->getByPosition(32)) *x -  (*this->modifiablevariables->getByPosition(33)) *x + (*this->constants->getByPosition(3)) * (*this->modifiablevariables->getByPosition(34)) *x*x - (*this->constants->getByPosition(3)) * (*this->modifiablevariables->getByPosition(35)) *x*x + (*this->constants->getByPosition(3)) * (*this->modifiablevariables->getByPosition(36))  - (*this->constants->getByPosition(3)) * (*this->modifiablevariables->getByPosition(37)) +  (*this->modifiablevariables->getByPosition(38))  *  (*this->modifiablevariables->getByPosition(39)) +
					// (*this->constants->getByPosition(4)) * (*this->modifiablevariables->getByPosition(40)) * x - (*this->constants->getByPosition(4)) * (*this->modifiablevariables->getByPosition(41)) *x +  (*this->modifiablevariables->getByPosition(42)) *x -  (*this->modifiablevariables->getByPosition(43)) *x + (*this->constants->getByPosition(4)) * (*this->modifiablevariables->getByPosition(44)) *x*x - (*this->constants->getByPosition(4)) * (*this->modifiablevariables->getByPosition(45)) *x*x + (*this->constants->getByPosition(4)) * (*this->modifiablevariables->getByPosition(46))  - (*this->constants->getByPosition(4)) * (*this->modifiablevariables->getByPosition(47)) +  (*this->modifiablevariables->getByPosition(48))  *  (*this->modifiablevariables->getByPosition(49)) +
					// (*this->constants->getByPosition(5)) * (*this->modifiablevariables->getByPosition(50)) * x - (*this->constants->getByPosition(5)) * (*this->modifiablevariables->getByPosition(51)) *x +  (*this->modifiablevariables->getByPosition(52)) *x -  (*this->modifiablevariables->getByPosition(53)) *x + (*this->constants->getByPosition(5)) * (*this->modifiablevariables->getByPosition(54)) *x*x - (*this->constants->getByPosition(5)) * (*this->modifiablevariables->getByPosition(55)) *x*x + (*this->constants->getByPosition(5)) * (*this->modifiablevariables->getByPosition(56))  - (*this->constants->getByPosition(5)) * (*this->modifiablevariables->getByPosition(57)) +  (*this->modifiablevariables->getByPosition(58))  *  (*this->modifiablevariables->getByPosition(59)) +
					// (*this->constants->getByPosition(6)) * (*this->modifiablevariables->getByPosition(60)) * x - (*this->constants->getByPosition(6)) * (*this->modifiablevariables->getByPosition(61)) *x +  (*this->modifiablevariables->getByPosition(62)) *x -  (*this->modifiablevariables->getByPosition(63)) *x + (*this->constants->getByPosition(6)) * (*this->modifiablevariables->getByPosition(64)) *x*x - (*this->constants->getByPosition(6)) * (*this->modifiablevariables->getByPosition(65)) *x*x + (*this->constants->getByPosition(6)) * (*this->modifiablevariables->getByPosition(66))  - (*this->constants->getByPosition(6)) * (*this->modifiablevariables->getByPosition(67)) +  (*this->modifiablevariables->getByPosition(68))  *  (*this->modifiablevariables->getByPosition(69)) +
					// (*this->constants->getByPosition(7)) * (*this->modifiablevariables->getByPosition(70)) * x - (*this->constants->getByPosition(7)) * (*this->modifiablevariables->getByPosition(71)) *x +  (*this->modifiablevariables->getByPosition(72)) *x -  (*this->modifiablevariables->getByPosition(73)) *x + (*this->constants->getByPosition(7)) * (*this->modifiablevariables->getByPosition(74)) *x*x - (*this->constants->getByPosition(7)) * (*this->modifiablevariables->getByPosition(75)) *x*x + (*this->constants->getByPosition(7)) * (*this->modifiablevariables->getByPosition(76))  - (*this->constants->getByPosition(7)) * (*this->modifiablevariables->getByPosition(77)) +  (*this->modifiablevariables->getByPosition(78))  *  (*this->modifiablevariables->getByPosition(79)) +
					// (*this->constants->getByPosition(8)) * (*this->modifiablevariables->getByPosition(80)) * x - (*this->constants->getByPosition(8)) * (*this->modifiablevariables->getByPosition(81)) *x +  (*this->modifiablevariables->getByPosition(82)) *x -  (*this->modifiablevariables->getByPosition(83)) *x + (*this->constants->getByPosition(8)) * (*this->modifiablevariables->getByPosition(84)) *x*x - (*this->constants->getByPosition(8)) * (*this->modifiablevariables->getByPosition(85)) *x*x + (*this->constants->getByPosition(8)) * (*this->modifiablevariables->getByPosition(86))  - (*this->constants->getByPosition(8)) * (*this->modifiablevariables->getByPosition(87)) +  (*this->modifiablevariables->getByPosition(88))  *  (*this->modifiablevariables->getByPosition(89)) +
					// (*this->constants->getByPosition(9)) * (*this->modifiablevariables->getByPosition(90)) * x - (*this->constants->getByPosition(9)) * (*this->modifiablevariables->getByPosition(91)) *x +  (*this->modifiablevariables->getByPosition(92)) *x -  (*this->modifiablevariables->getByPosition(93)) *x + (*this->constants->getByPosition(9)) * (*this->modifiablevariables->getByPosition(94)) *x*x - (*this->constants->getByPosition(9)) * (*this->modifiablevariables->getByPosition(95)) *x*x + (*this->constants->getByPosition(9)) * (*this->modifiablevariables->getByPosition(96))  - (*this->constants->getByPosition(9)) * (*this->modifiablevariables->getByPosition(97)) +  (*this->modifiablevariables->getByPosition(98))  *  (*this->modifiablevariables->getByPosition(99)) +
					
					// (*this->constants->getByPosition(10)) * (*this->modifiablevariables->getByPosition(100)) * x - (*this->constants->getByPosition(10)) * (*this->modifiablevariables->getByPosition(101)) *x +  (*this->modifiablevariables->getByPosition(102)) *x -  (*this->modifiablevariables->getByPosition(103)) *x + (*this->constants->getByPosition(10)) * (*this->modifiablevariables->getByPosition(104)) *x*x - (*this->constants->getByPosition(10)) * (*this->modifiablevariables->getByPosition(105)) *x*x + (*this->constants->getByPosition(10)) * (*this->modifiablevariables->getByPosition(106))  - (*this->constants->getByPosition(10)) * (*this->modifiablevariables->getByPosition(107)) +  (*this->modifiablevariables->getByPosition(108))  *  (*this->modifiablevariables->getByPosition(109)) +
					// (*this->constants->getByPosition(11)) * (*this->modifiablevariables->getByPosition(110)) * x - (*this->constants->getByPosition(11)) * (*this->modifiablevariables->getByPosition(111)) *x +  (*this->modifiablevariables->getByPosition(112)) *x -  (*this->modifiablevariables->getByPosition(113)) *x + (*this->constants->getByPosition(11)) * (*this->modifiablevariables->getByPosition(114)) *x*x - (*this->constants->getByPosition(11)) * (*this->modifiablevariables->getByPosition(115)) *x*x + (*this->constants->getByPosition(11)) * (*this->modifiablevariables->getByPosition(116))  - (*this->constants->getByPosition(11)) * (*this->modifiablevariables->getByPosition(117)) +  (*this->modifiablevariables->getByPosition(118))  *  (*this->modifiablevariables->getByPosition(119)) +
					// (*this->constants->getByPosition(12)) * (*this->modifiablevariables->getByPosition(120)) * x - (*this->constants->getByPosition(12)) * (*this->modifiablevariables->getByPosition(121)) *x +  (*this->modifiablevariables->getByPosition(122)) *x -  (*this->modifiablevariables->getByPosition(123)) *x + (*this->constants->getByPosition(12)) * (*this->modifiablevariables->getByPosition(124)) *x*x - (*this->constants->getByPosition(12)) * (*this->modifiablevariables->getByPosition(125)) *x*x + (*this->constants->getByPosition(12)) * (*this->modifiablevariables->getByPosition(126))  - (*this->constants->getByPosition(12)) * (*this->modifiablevariables->getByPosition(127)) +  (*this->modifiablevariables->getByPosition(128))  *  (*this->modifiablevariables->getByPosition(129)) +
					// (*this->constants->getByPosition(13)) * (*this->modifiablevariables->getByPosition(130)) * x - (*this->constants->getByPosition(13)) * (*this->modifiablevariables->getByPosition(131)) *x +  (*this->modifiablevariables->getByPosition(132)) *x -  (*this->modifiablevariables->getByPosition(133)) *x + (*this->constants->getByPosition(13)) * (*this->modifiablevariables->getByPosition(134)) *x*x - (*this->constants->getByPosition(13)) * (*this->modifiablevariables->getByPosition(135)) *x*x + (*this->constants->getByPosition(13)) * (*this->modifiablevariables->getByPosition(136))  - (*this->constants->getByPosition(13)) * (*this->modifiablevariables->getByPosition(137)) +  (*this->modifiablevariables->getByPosition(138))  *  (*this->modifiablevariables->getByPosition(139)) +
					// (*this->constants->getByPosition(14)) * (*this->modifiablevariables->getByPosition(140)) * x - (*this->constants->getByPosition(14)) * (*this->modifiablevariables->getByPosition(141)) *x +  (*this->modifiablevariables->getByPosition(142)) *x -  (*this->modifiablevariables->getByPosition(143)) *x + (*this->constants->getByPosition(14)) * (*this->modifiablevariables->getByPosition(144)) *x*x - (*this->constants->getByPosition(14)) * (*this->modifiablevariables->getByPosition(145)) *x*x + (*this->constants->getByPosition(14)) * (*this->modifiablevariables->getByPosition(146))  - (*this->constants->getByPosition(14)) * (*this->modifiablevariables->getByPosition(147)) +  (*this->modifiablevariables->getByPosition(148))  *  (*this->modifiablevariables->getByPosition(149)) +
					// (*this->constants->getByPosition(15)) * (*this->modifiablevariables->getByPosition(150)) * x - (*this->constants->getByPosition(15)) * (*this->modifiablevariables->getByPosition(151)) *x +  (*this->modifiablevariables->getByPosition(152)) *x -  (*this->modifiablevariables->getByPosition(153)) *x + (*this->constants->getByPosition(15)) * (*this->modifiablevariables->getByPosition(154)) *x*x - (*this->constants->getByPosition(15)) * (*this->modifiablevariables->getByPosition(155)) *x*x + (*this->constants->getByPosition(15)) * (*this->modifiablevariables->getByPosition(156))  - (*this->constants->getByPosition(15)) * (*this->modifiablevariables->getByPosition(157)) +  (*this->modifiablevariables->getByPosition(158))  *  (*this->modifiablevariables->getByPosition(159)) +
					// (*this->constants->getByPosition(16)) * (*this->modifiablevariables->getByPosition(160)) * x - (*this->constants->getByPosition(16)) * (*this->modifiablevariables->getByPosition(161)) *x +  (*this->modifiablevariables->getByPosition(162)) *x -  (*this->modifiablevariables->getByPosition(163)) *x + (*this->constants->getByPosition(16)) * (*this->modifiablevariables->getByPosition(164)) *x*x - (*this->constants->getByPosition(16)) * (*this->modifiablevariables->getByPosition(165)) *x*x + (*this->constants->getByPosition(16)) * (*this->modifiablevariables->getByPosition(166))  - (*this->constants->getByPosition(16)) * (*this->modifiablevariables->getByPosition(167)) +  (*this->modifiablevariables->getByPosition(168))  *  (*this->modifiablevariables->getByPosition(169)) +
					// (*this->constants->getByPosition(17)) * (*this->modifiablevariables->getByPosition(170)) * x - (*this->constants->getByPosition(17)) * (*this->modifiablevariables->getByPosition(171)) *x +  (*this->modifiablevariables->getByPosition(172)) *x -  (*this->modifiablevariables->getByPosition(173)) *x + (*this->constants->getByPosition(17)) * (*this->modifiablevariables->getByPosition(174)) *x*x - (*this->constants->getByPosition(17)) * (*this->modifiablevariables->getByPosition(175)) *x*x + (*this->constants->getByPosition(17)) * (*this->modifiablevariables->getByPosition(176))  - (*this->constants->getByPosition(17)) * (*this->modifiablevariables->getByPosition(177)) +  (*this->modifiablevariables->getByPosition(178))  *  (*this->modifiablevariables->getByPosition(179)) +
					// (*this->constants->getByPosition(18)) * (*this->modifiablevariables->getByPosition(180)) * x - (*this->constants->getByPosition(18)) * (*this->modifiablevariables->getByPosition(181)) *x +  (*this->modifiablevariables->getByPosition(182)) *x -  (*this->modifiablevariables->getByPosition(183)) *x + (*this->constants->getByPosition(18)) * (*this->modifiablevariables->getByPosition(184)) *x*x - (*this->constants->getByPosition(18)) * (*this->modifiablevariables->getByPosition(185)) *x*x + (*this->constants->getByPosition(18)) * (*this->modifiablevariables->getByPosition(186))  - (*this->constants->getByPosition(18)) * (*this->modifiablevariables->getByPosition(187)) +  (*this->modifiablevariables->getByPosition(188))  *  (*this->modifiablevariables->getByPosition(189)) +
					// (*this->constants->getByPosition(19)) * (*this->modifiablevariables->getByPosition(190)) * x - (*this->constants->getByPosition(19)) * (*this->modifiablevariables->getByPosition(191)) *x +  (*this->modifiablevariables->getByPosition(192)) *x -  (*this->modifiablevariables->getByPosition(193)) *x + (*this->constants->getByPosition(19)) * (*this->modifiablevariables->getByPosition(194)) *x*x - (*this->constants->getByPosition(19)) * (*this->modifiablevariables->getByPosition(195)) *x*x + (*this->constants->getByPosition(19)) * (*this->modifiablevariables->getByPosition(196))  - (*this->constants->getByPosition(19)) * (*this->modifiablevariables->getByPosition(197)) +  (*this->modifiablevariables->getByPosition(198))  *  (*this->modifiablevariables->getByPosition(199))
					
					// ;
		}
		
		virtual int getIterationSize(){
			return 200;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<XtremeFunction1>::classType || ModifiableFunction::instanceof(cls);
			}
		
	protected:
		
		
	
};

}

#endif