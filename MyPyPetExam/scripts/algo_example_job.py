

import sys
sys.path.append("./../algos/")

from Centella import centella

#help(centella.centella)# uncomment for documentation

from algo_example import *

vlevel=1 # verbosity

algos, idsts = [], [] # algorithms, input data

#idsts.append("input_data.root")

algos.append( algo_example(False,vlevel,'MyAlgoInstance') )

c= centella.centella(algos,idsts,level=vlevel)

#------------- Histogram declaration -------------#

# Line below only needed if user wants to set the histos here.
# Histograms can also be declared in initialize method of algorithms

c.hman.h1("EventID","Event ID; Number;",100,0,1000)

#-------------------------------------------------#

c.run()

