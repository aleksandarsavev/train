% Created 12-09-2016
% Author Aleksandar <savevjr@gmail.com>
%
% Family tree

parent(a,e).
parent(a,c).
parent(b,e).
parent(b,c).
parent(e,f).
parent(j,i).
parent(f,i).
parent(c,g).
parent(d,g).
parent(g,h).
parent(h,k).

% How to read relations:
%   relation_name(X,Y) ==> X is [relation_name] of Y
% Example:
%   sibling(X,Y)       ==>  X is sibling of Y
%   child(X,Y)         ==>  X is child   of Y
%   etc...

sibling(X,Y):-parent(P,X),parent(P,Y).
child(X,Y):-parent(Y,X).
ancestor(X,Y):-parent(X,Y);parent(X,C),ancestor(C,Y).
descendant(X,Y):-ancestor(Y,X).
cousin(X,Y):-parent(P_X,X),parent(P_Y,Y),(sibling(P_X,P_Y);cousin(P_X,P_Y)).
relative(X,Y):-ancestor(X,Y);ancestor(Y,X);ancestor(Z,X),ancestor(Z,Y).
