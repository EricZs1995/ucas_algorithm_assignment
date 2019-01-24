param n>0 integer;
param r>=0;

set D:=1..n;
set D1:=2..n;

param distance{D} >=0;


var m>=0;
var station{D}>=0;

minimize Value: m;

s.t. stationConstraints{j in D1}:station[j]-station[j-1] <= m;
s.t. distance1Constraints{i in D}:distance[i]-station[i] <= r;
s.t. distance2Constraints{i in D}:station[i]-distance[i] <= r;

solve;
display:m;
display{j in D}: station[j];
