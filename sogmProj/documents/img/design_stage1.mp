%begin and end
Begin.b;
End.e;

%cochlear stage
Begin.bcoch;
State.ycoch("cochlear filterbank")();
End.ecochnul;
End.ecoch;
End.ecochtwee;

State.coch("Chochlear")(bcoch, ycoch, ecoch, ecochtwee, ecochnul);
coch.info.left := coch.info.right := 20;
coch.info.drawNameLine := 1;

leftToRight(20)(bcoch, ycoch, ecoch);
topToBottom(20)(ecochnul, ecoch, ecochtwee);

%auditory nerves
Begin.baun;
State.diff("differentiator")();
State.comp("non-linear compression")();
State.lop("low-pass filter")();
End.eaun;

State.aun("Auditory Nerves")(baun, diff, comp, lop, eaun);
aun.info.left := aun.info.right := 20;
aun.info.drawNameLine := 1;

leftToRight(20)(baun, diff, comp, lop, eaun);

%lateral inhibitory network
Begin.blin;
State.derv("derivative tonotopic axis")();
State.hwr("half-wave rectifier")();
End.elin;

State.lin("Lateral Inhibitory Network")(blin, derv, hwr, elin);
lin.info.left := lin.info.right := 20;
lin.info.drawNameLine := 1;

leftToRight(20)(blin, derv, hwr, elin);

%final
Begin.bfin;
State.ineg("integration over w[n]")();
End.efin;

State.fin("Final")(bfin, ineg, efin);
fin.info.left := fin.info.right := 20;
fin.info.drawNameLine := 1;

leftToRight(20)(bfin, ineg, efin);

%arrange stages:
topToBottom(20)(b, coch, aun, lin, fin, e);

%draw all
drawObjects(b, coch, aun, lin, fin, e);

%label cochlear phase
item(iAssoc)("x[n]")(obj.nw = bcoch.s);
item(iAssoc)("y[0][n]")(obj.nw = ecochnul.s);
item(iAssoc)("y[1][n]")(obj.nw = ecoch.s);
item(iAssoc)("y[M-1][n]")(obj.nw = ecochtwee.s);

clink(transition)(bcoch, ycoch);
clink(transition)(ycoch, ecoch);
clink(transition)(ycoch, ecochtwee);
clink(transition)(ycoch, ecochnul);

%label auditory nerves
item(iAssoc)("x[m][n]")(obj.nw = baun.s);
item(iAssoc)("y[m][n]")(obj.nw = eaun.s);

clink(transition)(baun, diff);
clink(transition)(diff, comp);
clink(transition)(comp, lop);
clink(transition)(lop, eaun);

%label lateral inhibitory network
item(iAssoc)("x[m][n]")(obj.nw = blin.s);
item(iAssoc)("y[m][n]")(obj.nw = elin.s);

clink(transition)(blin, derv);
clink(transition)(derv, hwr);
clink(transition)(hwr, elin);

%label final
item(iAssoc)("x[m][n]")(obj.nw = bfin.s);
item(iAssoc)("y[m][n]")(obj.nw = efin.s);
item(iAssoc)("x[n]")(obj.nw = b.s);
item(iAssoc)("y[m][n]")(obj.nw = e.s);

clink(transition)(bfin, ineg);
clink(transition)(ineg, efin);

%link all
clink(transition)(b, coch);
clink(transition)(coch, aun);
clink(transition)(aun, lin);
clink(transition)(lin, fin);
clink(transition)(fin, e);

