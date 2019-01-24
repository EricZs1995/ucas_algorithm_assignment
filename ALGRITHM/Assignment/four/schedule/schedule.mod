/ * input data * / 
param n, integer, >= 1; # the number of items 
param p, integer, >= 1, <n; # the number of items 
for selecting set E:={1..n}; # the set of items 
param c{E} >=0; # the costs of items 
/ * The variables * / 
var x{E} binary;

/ * The objective function * / 
minimize TotalCost: sum{i in E} c[i] * x[i]; 
/ * The constraint * / 
s.t. exact_p: sum{i in E} x[i] = p; 
solve;

/ * Displaying results * / 
display ’solution X’; 
display{i in E: x[i]=1 }: x[i]; 
display ’total costs=’,sum{i in E} c[i] * x[i];

/ * Data section * / 
data; 
param n:=10; 
param p:=6; 
param c:=[1] 3 [2] 2 [3] 6 [4] 3 [5] 9 [6] 5 [7] 8 [8]

end;
