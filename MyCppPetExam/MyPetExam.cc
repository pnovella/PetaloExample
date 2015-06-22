
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
    ->hman()->h1(this->alabel("EvtID"),"EvtID",10000,0,10000);
  
 
  
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

  gate::Run* run = &gate::Centella::instance()->getRun();

  run->find_dstore("num_events");
 
  int nevt = gate::int_from_string(run->fetch_sstore("num_events"));
  
  _m.message("Number of generated events in file:",nevt,gate::NORMAL);

  run->store("MyIntVar",3);
  run->store("MyDoubleVar",3.14);
  run->store("MyStrVar","3.14");

  store("MyIntVar",3);
  store("MyDoubleVar",3.14);
  store("MyStrVar","3.14");

  return true;

}
