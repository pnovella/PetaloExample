#ifndef _MyPetExam__
#define _MyPetExam__

#include <GATE/Centella.h>

class MyPetExam : public gate::IAlgo {

 public:
  
  //! default contructor
  MyPetExam(gate::VLEVEL=gate::NORMAL,
	       std::string label="MyPetExamInstance");
  
  //! constructor with store with input parameters 
  MyPetExam(const gate::ParamStore& gs,
	       gate::VLEVEL=gate::NORMAL,
	       std::string label="MyPetExamInstance");
  
  //! destructor
  virtual ~MyPetExam(){};
  
  //! initialize algorithm
  bool initialize();        
  
  //! execute algorithm: process current event
  bool execute(gate::Event& evt);  
  
  //! finalize algorithm
  bool finalize();          
  
 private:
  
  ClassDef(MyPetExam,0)
    
};

#endif
