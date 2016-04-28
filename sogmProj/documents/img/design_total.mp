Begin.b;
Begin.bm;
End.e;

State.pr("Pre-Processing")();
State.nn("Learning")();
State.cl("Result interpretation")();

leftToRight(20)(bm, b);
topToBottom(20)(b, pr, nn, cl, e);

drawObjects(b, pr, nn, cl, e);
clink(transition)(b, pr);
clink(transition)(pr, nn);
clink(transition)(nn, cl);
clink(transition)(cl, e);

link(transition)(pathStepX(b.w, cl.w, -60));
link(transition)(pathStepX(cl.e, nn.e, 40));

item(iAssoc)("audio-data")(obj.nw = b.s);
item(iAssoc)("meta-data")(obj.s =1.3[b.w, bm.e]);
item(iAssoc)("classification == meta-data?")(obj.nw = cl.e);

