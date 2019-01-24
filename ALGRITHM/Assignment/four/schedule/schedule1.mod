/ * Parameters * / 
param n>0 integer; / * the number of items * / 
param m>0 integer; / * the number of resources * /

/ * Sets * / 
set Items:=1..n; 
set Resources:=1..m;

/* parametry */

param capacity{Resources}>=0; / * array represents the capacity of the resources * / param consumption{Resources,Items}>=0; / * the consumption of resource by item * / param profit{Items}>=0; / * array the value of each item * /

/* Decision variables * /

/ * variable * / 
var choose{Items} >=0 binary;

/* Objective function * /

maximize Value: sum{j in Items} profit[j] * choose[j];

/ * Constraints * / 
s.t. ResourceConstraints{i in Resources}: sum{j in Items} consumption[i,j] * choose[j] <= capaci solve;

display{j in Items: choose[j]=1} choose[j];
