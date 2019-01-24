#/ * Parameters * / 
param n>0 integer; #/ * the number of course * / 
param t>0 integer; #/ * the number of time point * / 
param m>0 integer; #/ * the maximum number of choosed course * /

#/ * Sets * / 
set courses:=1..n; 
set timepoints:=1..t;
#/* parametry */

param occupy{timepoints,courses}>=0;  

#/* Decision variables * /

#/ * variable * / 
var choose{courses} >=0 binary;

#/* Objective function * /

maximize Value: sum{j in courses} choose[j];

#/ * Constraints * / 
s.t. ResourceConstraints{i in timepoints}: sum{j in courses} occupy[i,j] * choose[j] <= m ;
solve;

display{j in Items: choose[j]=1} choose[j];
