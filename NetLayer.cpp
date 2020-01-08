

#ifndef NetLayer_cpp
#define NetLayer_cpp

#include "NetLayer.h"

	NetLayer::NetLayer(){
		
	}
	
	void NetLayer::inputs(int in){
		this->inp = in;
	}
	
	int NetLayer::inputs(){
		return this->inp;
	}

	void NetLayer::outputs(int out){
		this->outp = out;
	}
	
	int NetLayer::outputs(){
		return this->outp;
	}

	void NetLayer::addInputNetNeuron(NetNeuron<float> *neuron){
		
	}

	NetNeuron<float> *NetLayer::getInputNetNeuron(int id){
		
	}

	List<NetNeuron<float>> *NetLayer::getInputNetNeurons(){
		
	}

	void NetLayer::addOutputNetNeuron(NetNeuron<float> *neuron){
		
	}

	NetNeuron<float> *NetLayer::getOutputNetNeuron(int id){
		
	}

	List<NetNeuron<float>> *NetLayer::getOutputNetNeurons(){
		
	}

		
	void NetLayer::initialize(){
		
	}

	void NetLayer::compute(){
		
	}
	
	String NetLayer::getClassName(){
		return "NetLayer";
	}
	
	String NetLayer::toString(){
		return "NetLayer";
	}
	
	bool NetLayer::equal(cppObject *b){
		if(b == this){
			return true;
		}
		if(b->getClassName() == this->getClassName()){
			return true;
		}
		return false;
	}
	
	NetLayer *NetLayer::clone(){
		NetLayer *y = new NetLayer();
		y->inputs(this->inputs());
		y->outputs(this->outputs());
		return y;
	}
	
	NetLayer NetLayer::operator=(NetLayer& n){
		
	}
	bool NetLayer::operator==(NetLayer& n){
		return getClassName() == n.getClassName();
	}
	bool NetLayer::operator!=(NetLayer& n){
		return getClassName() != n.getClassName();
	}

#endif