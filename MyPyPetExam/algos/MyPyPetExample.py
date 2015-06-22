
from Centella.AAlgo import AAlgo
from Centella.physical_constants import *

class MyPyPetExample(AAlgo):

    def __init__(self,param=False,level = 1,label="",**kargs):

        """
        
        Deal here with your parameters in param and kargs.
        If param is an instace of ParamManager, parameters
        will be set as algorithm parameters by AAlgo.
            
        """
        
            
        self.name='MyPyPetExample'
        
        AAlgo.__init__(self,param,level,self.name,0,label,kargs)

        # deal with input parameters 
        
        try: self.mypar = self.ints["MyIntPar"]

        except KeyError: self.mypar = 0
 

    def initialize(self):

        """

        You can use here:

            self.hman     -----> histoManager instance
            self.tman     -----> treeManager instance
            self.logman   -----> logManager instance
            self.autoDoc  -----> latex_gen instance
        
        """
        
        self.m.log(1,'+++Init method of MyPyPetExample algorithm+++')
        
        self.m.log(1,"Input integer parameter:",self.mypar)
        
        # create histogram
        self.hman.h1("EventID","Event ID; Number;",10000,0,10000)
        
        # store a variable within the algorithm
        self.strings["MyPythonVar"]="ei"
        
        # store a vaiarble in the log manager
        self.logman["USER"].strings["MyPythonVar2"]="ei"

        return

    def execute(self,event=""):

        """
        
        You can also use here:

            self.event ----> current event from the input data 
            
        """
        
        self.hman.fill("EventID",event.GetID())

        return True

    def finalize(self):

        
        self.m.log(1,'+++End method of MyPyPetExample algorithm+++')

        return

    
