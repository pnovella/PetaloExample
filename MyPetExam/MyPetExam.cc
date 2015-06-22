
#include<MyPetExam.h>

ClassImp(MyPetExam)

//==========================================================================
MyPetExam::MyPetExam(gate::VLEVEL vl, std::string label) : 
IAlgo(vl,"MyPetExam",0,label){
//==========================================================================


}

//==========================================================================
MyPetExam::MyPetExam(const gate::ParamStore& gs, 
			   gate::VLEVEL vl, std::string label) :
  IAlgo(gs,vl,"MyPetExam",0,label){
//==========================================================================


}

//==========================================================================
bool MyPetExam::initialize(){
//==========================================================================

  _m.message("Intializing algorithm",this->getAlgoLabel(),gate::NORMAL);
  
  gate::Centella::instance()
    ->hman()->h1(this->alabel("EvtID"),"EvtID",10,0,100);

  return true;

}

//==========================================================================
bool MyPetExam::execute(gate::Event& evt){
//==========================================================================

  _m.message("Executing algorithm",this->getAlgoLabel(),gate::VERBOSE);
  
  _m.message("Event number:",evt.GetEventID(),gate::VERBOSE);
  
  gate::Centella::instance()
    ->hman()->fill(this->alabel("EvtID"),evt.GetEventID());
  
  return true;

}

//==========================================================================
bool MyPetExam::finalize(){
//==========================================================================

  _m.message("Finalising algorithm",this->getAlgoLabel(),gate::NORMAL);
  
  return true;

}
