//Perpective_6, 2015 Philip Liu


(

~path = "/Works_S/Sounds/";
~buf1 = Buffer.read(s, ~path ++ "braids.wav");

SynthDef(\syn1,{
	arg gate = 0, amp =1, attack= 0.01, decay = 1, sustain= 0, release= 0, panFreq = 0.2, panPhase = 0, mix = 0, elapsedTime = 0,  nagumoTrigAdd = 0, panning = 0, sigCadd = 0.1;
	var env, input, enved, pan, sendreply1, sendreply2, kernel, sig, fitz, impulse, impulse1, impulse2, dust1, kerSig1, kerSig2, kerSig3;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);


	impulse = Impulse.ar(MouseY.kr(10, 0.01));

	dust1 = Dust.ar(MouseY.kr(elapsedTime/5 + 8 + nagumoTrigAdd, 0), mul:0.8);
	impulse1 =  Impulse.ar(MouseY.kr(elapsedTime/5 + 8 + nagumoTrigAdd, 1), mul:0.8);

	impulse2 = TWChoose.ar(DetectSilence.ar(impulse1, time: 0.01), [impulse1, dust1 ], [0.7, 0.3]);


	fitz = 0.02* FitzHughNagumo.ar(impulse,MouseX.kr(0.01, elapsedTime/500 + 0.1),MouseX.kr(0.01, elapsedTime/500 + 0.1),1,1, mul: TExpRand.kr(MouseY.kr( elapsedTime/740 + 0.05, 0.01), 0.4, impulse));

	kerSig1 = GrayNoise.ar(0.9);
	kerSig2 = ClipNoise.ar(0.8);
	kerSig3 = Decay2.ar(impulse, 0.003, 1, kerSig2);
	kerSig3 = CombL.ar(kerSig3, 0.3, [0.02, MouseY.kr(0.05 ,0.15)], 1);
	kerSig3 = MoogFF.ar(Squiz.ar(LeakDC.ar(kerSig3), TExpRand.ar(1, 3+(elapsedTime/228.70).fold(0, 1), impulse)), 10000);

	kernel = TWChoose.ar(impulse2, [kerSig1, kerSig2, kerSig3], [0.6, 0.1, 0.3]);

	sig = TWChoose.ar(Trig.ar(DetectSilence.ar(impulse2, time: 0.08)), [kerSig3, Convolution.ar(impulse2, HPF.ar(kernel, 20), 1024, 1)*(fitz.range(0,1.5))], [sigCadd + (elapsedTime/114.35).fold(0, 0.33) ,  (1-sigCadd) - ((elapsedTime/114.35).fold(0, 0.33))]);

	sig = sig*0.1*env;

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn0Freeze', Amplitude.kr(sig));
	sendreply2 = SendReply.kr(Impulse.kr(60), '/Syn0Poll',Amplitude.ar(sig, mul:1));

	// DetectSilence.ar(LeakDC.ar(fitz), doneAction:2);
	Out.ar(18, HPF.ar(sig, 30));
}).send(s);



SynthDef(\syn2,{
	arg gate = 0, amp =1, attack= 0.01, decay = 1, sustain= 0, release= 0, buf = ~buf1.bufnum, posX = 0.01, posY = 0.01, posZ = 0.01, elapsedTime = 0, grainsTimeAdd = 0, grainsDurSubstract = 0, panning = 0.165, squizChunkUpper = 4;
	var env,  enved, pan, sendreply1, sendreply2, kernel, sig, fitz, impulse;

	impulse = Dust.kr(grainsTimeAdd  + (elapsedTime/22.87).fold(0,10) + posX.linlin(0, 2304, 4,0));
	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);

	kernel = TGrains.ar(2, impulse, buf, TExpRand.kr((elapsedTime/141.34).fold(0.8,2.8), 1, impulse), LinCongL.ar(	posY.linlin(0, 1296, 1350, 0)/100, 1.5, 0.15).range(0, BufDur.kr(buf)/posX.linlin(0, 2304, 10,1).linexp(1,10,1,10)), 0.6-(posX.linexp(0, 2304, 1000, 0)/4000)- grainsDurSubstract);

	kernel = Squiz.ar(kernel, posY.linlin(0, 1296, 2.0, 2 - (elapsedTime/228)), posX.linlin(0, 2304, 1, squizChunkUpper));

	sig = LPF.ar(kernel*1, 16000);
	enved = sig * env;

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn1Freeze', Amplitude.kr(kernel));
	sendreply2 = SendReply.kr(Impulse.kr(30), '/Syn1Poll', Lag.kr(Amplitude.kr(enved, mul:2)));

	// Out.ar(2, HPF.ar(enved, 30));
	Out.ar(2, HPF.ar(enved, 30));
}).send(s);



SynthDef(\syn3,{
	arg gate = 0, amp =1, attack= 0, decay =5, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, kFreqsMul=200, elapsedTime = 0, kFreqsModulatorFreq = 10, panning = 0.33, frictionAdd=0, massAdd=0;

	var env, enved, pan, sendreply1, sendreply2, source, sig, impulse;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);

	impulse = Impulse.kr(posX.linexp(0, 2304, 50, 5));


	source = Mix.fill(4, {arg i; (i+5).reciprocal * FitzHughNagumo.ar(impulse, (i+1)/20, (i+1)/21)  });


	sig = Friction.ar(source, friction: 0.005+(elapsedTime+50/228700).fold(0,0.002) + frictionAdd, mass: posY.linexp(0, 1296, 10, 1) + massAdd);

	sig = DFM1.ar(sig, posY.linexp(0, 1296, 2000, 15000), res: 0, type: 0);
	enved = env *sig * 0.1;

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn2Freeze', Amplitude.kr(source, mul:2));
	sendreply2 = SendReply.kr(Impulse.kr(30), '/Syn2Poll', Lag.kr(Amplitude.kr(enved, mul:2)));


	DetectSilence.ar(enved, time: 0.5, doneAction: 2);
	// Out.ar(4, HPF.ar(enved, 30));
	Out.ar(4, HPF.ar(enved, 30));
}).send(s);

SynthDef(\syn3_2,{
	arg gate = 0, amp =1, attack= 0, decay =5, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, kFreqsMul=200, elapsedTime = 0, kFreqsModulatorFreq = 10, panning = 0.33, frictionAdd=0, massAdd=0;

	var env, enved, pan, sendreply1, sendreply2, source, sig, impulse;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);

	impulse = Impulse.kr(posX.linexp(0, 2304, 50, 5));


	source = Mix.fill(4, {arg i; (i+5).reciprocal * FitzHughNagumo.ar(impulse, (i+1)/20, (i+1)/21)  });


	sig = Friction.ar(source, friction: 0.005+(elapsedTime+50/228700).fold(0,0.002) + frictionAdd, mass: posY.linexp(0, 1296, 10, 1) + massAdd, mul:0.1);

	sig = DFM1.ar(sig, posY.linexp(0, 1296, 2000, 15000), res: 0, type: 0);
	enved = env *sig;

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn2Freeze', Amplitude.kr(source, mul:2));
	sendreply2 = SendReply.kr(Impulse.kr(30), '/Syn2Poll', Lag.kr(Amplitude.kr(enved, mul:2)));


	DetectSilence.ar(enved, time: 0.5, doneAction: 2);
	// Out.ar(5, HPF.ar(enved, 30));
	Out.ar(6, HPF.ar(enved, 30));
}).send(s);


SynthDef(\syn3_3,{
	arg gate = 0, amp =1, attack= 0, decay =5, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, kFreqsMul=200, elapsedTime = 0, kFreqsModulatorFreq = 10, panning = 0.33, frictionAdd=0, massAdd=0;

	var env, enved, pan, sendreply1, sendreply2, source, sig, impulse;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);

	impulse = Impulse.kr(posX.linexp(0, 2304, 50, 5));


	source = Mix.fill(4, {arg i; (i+5).reciprocal * FitzHughNagumo.ar(impulse, (i+1)/20, (i+1)/21)  });


	sig = Friction.ar(source, friction: 0.005+(elapsedTime+50/228700).fold(0,0.002) + frictionAdd, mass: posY.linexp(0, 1296, 10, 1) + massAdd, mul:0.1);

	sig = DFM1.ar(sig, posY.linexp(0, 1296, 2000, 15000), res: 0, type: 0);
	enved = env *sig;


	DetectSilence.ar(enved, time: 0.5, doneAction: 2);
	// Out.ar(6, HPF.ar(enved, 30));
	Out.ar(8, HPF.ar(enved, 30));
}).send(s);




SynthDef(\syn4,{
	arg gate = 0, amp =0.6, attack= 0.01, decay = 0.3, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, elapsedTime = 0, fbsinBase = 67;
	var env, enved, pan, sendreply1, sendreply2, source, sig;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);
				sig = Mix.fill(10, {arg i;  ((i+3).reciprocal + (i/500)) * FBSineL.ar(1.618.pow(i+1) * (fbsinBase+posX.linlin(0, 2304, -2, 2)) , 1, posY.linexp(0, 1296, 0.01, (elapsedTime/74.175).fold(0,3)), 1, 0.1) });

	sig = LPF.ar(sig, 16000);

	enved = env* sig * amp *fbsinBase.linlin(50, 300, 3.5, 0.9);

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn3Freeze', sig);
	sendreply2 = SendReply.kr(Impulse.kr(10), '/Syn3Poll', Lag.kr(Amplitude.kr(enved, mul:2)));


	DetectSilence.ar(LeakDC.ar(enved), doneAction:2);
	// Out.ar(7, HPF.ar(enved, 40));
	Out.ar(10, HPF.ar(enved, 30));
}).send(s);


SynthDef(\syn4_2,{
	arg gate = 0, amp =0.6, attack= 0.01, decay = 0.3, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, elapsedTime = 0, fbsinBase = 67;
	var env, enved, pan, sendreply1, sendreply2, source, sig;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);
				sig = Mix.fill(10, {arg i;  ((i+3).reciprocal + (i/500)) * FBSineL.ar(1.618.pow(i+1) * (fbsinBase+posX.linlin(0, 2304, -2, 2)) , 1, posY.linexp(0, 1296, 0.01, (elapsedTime/74.175).fold(0,3)), 1, 0.1) });

	sig = LPF.ar(sig, 16000);

	enved = env* sig * amp *fbsinBase.linlin(50, 300, 3.5, 0.9);

	sendreply2 = SendReply.kr(Impulse.kr(10), '/Syn3Poll', Lag.kr(Amplitude.kr(enved, mul:2)));


	DetectSilence.ar(LeakDC.ar(enved), doneAction:2);
	// Out.ar(8, HPF.ar(enved, 40));
	Out.ar(11, HPF.ar(enved, 40));
}).send(s);

SynthDef(\syn4_3,{
	arg gate = 0, amp =0.6, attack= 0.01, decay = 0.3, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, elapsedTime = 0, fbsinBase = 67;
	var env, enved, pan, sendreply1, sendreply2, source, sig;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);
				sig = Mix.fill(10, {arg i;  ((i+3).reciprocal + (i/500)) * FBSineL.ar(1.618.pow(i+1) * (fbsinBase+posX.linlin(0, 2304, -2, 2)) , 1, posY.linexp(0, 1296, 0.01, (elapsedTime/74.175).fold(0,3)), 1, 0.1) });

	sig = LPF.ar(sig, 16000);

	enved = env* sig * amp *fbsinBase.linlin(50, 300, 3.5, 0.9);

	DetectSilence.ar(LeakDC.ar(enved), doneAction:2);
	Out.ar(12, HPF.ar(enved, 40));
}).send(s);

SynthDef(\syn4_4,{
	arg gate = 0, amp =0.6, attack= 0.01, decay = 0.3, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, elapsedTime = 0, fbsinBase = 67;
	var env, enved, pan, sendreply1, sendreply2, source, sig;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);
				sig = Mix.fill(10, {arg i;  ((i+3).reciprocal + (i/500)) * FBSineL.ar(1.618.pow(i+1) * (fbsinBase+posX.linlin(0, 2304, -2, 2)) , 1, posY.linexp(0, 1296, 0.01, (elapsedTime/74.175).fold(0,3)), 1, 0.1) });

	sig = LPF.ar(sig, 16000);

	enved = env* sig * amp *fbsinBase.linlin(50, 300, 3.5, 0.9);


	DetectSilence.ar(LeakDC.ar(enved), doneAction:2);
	// Out.ar(10, HPF.ar(enved, 40));
	Out.ar(13, HPF.ar(enved, 40));
}).send(s);

SynthDef(\syn4_5,{
	arg gate = 0, amp =0.6, attack= 0.01, decay = 0.3, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, elapsedTime = 0, fbsinBase = 67;
	var env, enved, pan, sendreply1, sendreply2, source, sig;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);
				sig = Mix.fill(10, {arg i;  ((i+3).reciprocal + (i/500)) * FBSineL.ar(1.618.pow(i+1) * (fbsinBase+posX.linlin(0, 2304, -2, 2)) , 1, posY.linexp(0, 1296, 0.01, (elapsedTime/74.175).fold(0,3)), 1, 0.1) });

	sig = LPF.ar(sig, 16000);

	enved = env* sig * amp *fbsinBase.linlin(50, 300, 3.5, 0.9);


	DetectSilence.ar(LeakDC.ar(enved), doneAction:2);
	Out.ar(11, HPF.ar(enved, 40));
}).send(s);

SynthDef(\syn4_6,{
	arg gate = 0, amp =0.6, attack= 0.01, decay = 0.3, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, elapsedTime = 0, fbsinBase = 67;
	var env, enved, pan, sendreply1, sendreply2, source, sig;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);
				sig = Mix.fill(10, {arg i;  ((i+3).reciprocal + (i/500)) * FBSineL.ar(1.618.pow(i+1) * (fbsinBase+posX.linlin(0, 2304, -2, 2)) , 1, posY.linexp(0, 1296, 0.01, (elapsedTime/74.175).fold(0,3)), 1, 0.1) });

	sig = LPF.ar(sig, 16000);

	enved = env* sig * amp *fbsinBase.linlin(50, 300, 3.5, 0.9);

	DetectSilence.ar(LeakDC.ar(enved), doneAction:2);
	// Out.ar(12, HPF.ar(enved, 40));
	Out.ar(14, HPF.ar(enved, 40));
}).send(s);






SynthDef(\syn5,{
	arg gate = 0, amp =1, attack= 0.01, decay = 1, sustain= 0, release= 0, buf = ~buf1.bufnum, posX = 0.01, posY = 0.01, posZ = 0.01, elapsedTime = 0, grainsTimeAdd = 0, grainsDurSubstract = 0, panning = 0.165;
	var env,  enved, pan, sendreply1, sendreply2, kernel, sig, fitz, impulse, squizChunkUpper = 30;

	impulse = Dust.kr(grainsTimeAdd  + (elapsedTime/22.87).fold(0,10) + posX.linlin(0, 2304, 4,0));
	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);

	kernel = TGrains.ar(2, impulse, buf, TRand.kr((elapsedTime/141.34).fold(1.0,2.5), 1, impulse), LinCongL.ar(posY.linlin(0, 1296, 1350, 0)/100, 1.5, 0.15).range(0, BufDur.kr(buf)/posX.linlin(0, 2304, 10, 1).linexp(1,10,1,10)), 1-(posX.linexp(0, 2304, 1000, 0)/3500)- grainsDurSubstract);

	kernel = Squiz.ar(kernel, posY.linlin(0, 1296, 1.0, 2 - (elapsedTime/370)), posX.linlin(0, 2304, squizChunkUpper, 20));

	sig = LPF.ar(kernel*1, 16000);
	enved = sig*env;

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn4Freeze', Amplitude.kr(kernel));
	sendreply2 = SendReply.kr(Impulse.kr(30), '/Syn4Poll', Lag.kr(Amplitude.kr(enved, mul:2)));


	// Out.ar(13, HPF.ar(enved, 30));
	Out.ar(15, HPF.ar(enved, 30));
	}).send(s);






SynthDef(\syn6,{
	arg gate = 0, amp =1, attack= 0, decay =5, sustain= 0, release= 0, posX = 1, posY = 1, posZ = 1, kFreqsMul=200, elapsedTime = 0, kFreqsModulatorFreq = 10, panning = 0.33, frictionAdd=0, massAdd=0, impulseUpper =50, fitzrateDiv = 20;

	var env, enved, pan, sendreply1, sendreply2, source, sig, impulse;

	env = EnvGen.ar(Env.adsr(attack, decay, sustain, release), gate, doneAction: 2);

	impulse = Impulse.kr(posX.linexp(0, 2304, impulseUpper, 5));


	source = Mix.fill(3, {arg i; (i+2).reciprocal * FitzHughNagumo.ar(impulse, (i+1)/(fitzrateDiv+1) +0.046, (i+1)/(fitzrateDiv+1) + 0.047)  });


	sig = Friction.ar(source, friction: 0.009+(elapsedTime+50/228700).fold(0,0.002)+frictionAdd, mass: posY.linexp(0, 1296, 5, 0.1) + massAdd);

	sig = DFM1.ar(sig, posY.linexp(0, 1296, 4000, 12000), res: 0.3, type: 0);
	enved = env *sig * 0.1;

	sendreply1 = SendReply.kr(Impulse.kr(20), '/Syn5Freeze', Amplitude.kr(source, mul:2));
	sendreply2 = SendReply.kr(Impulse.kr(30), '/Syn5Poll', Lag.kr(Amplitude.kr(enved, mul:2)));

	DetectSilence.ar(enved, time: 10, doneAction: 2);
	// Out.ar(15, HPF.ar(enved, 100));
	Out.ar(16, HPF.ar(enved, 100));
}).send(s);

SynthDef(\monitor,{
	var in;
	in = Mix.fill(19, {arg i; 0.25 * In.ar(i+2, 1)});

		Out.ar(0, in);
}).send(s);

)


(

var start= 0;

Synth(\monitor);

n = NetAddr.new("localhost", 15555);
~poll0 = OSCFunc({ |msg| n.sendMsg("/poll0", msg[3].asString(6))}, '/Syn0Poll');
~poll1 = OSCFunc({ |msg| n.sendMsg("/poll1", msg[3].asString(6))}, '/Syn1Poll');
~poll2 = OSCFunc({ |msg| n.sendMsg("/poll2", msg[3].asString(6))}, '/Syn2Poll');
~poll3 = OSCFunc({ |msg| n.sendMsg("/poll3", msg[3].asString(6))}, '/Syn3Poll');
~poll4 = OSCFunc({ |msg| n.sendMsg("/poll4", msg[3].asString(6))}, '/Syn4Poll');
~poll5 = OSCFunc({ |msg| n.sendMsg("/poll5", msg[3].asString(6))}, '/Syn5Poll');

~synth1 = nil;
~synth2 = nil;
~synth3 = nil;
~synth3_2 = nil;
~synth3_3 = nil;
~synth4 = nil;
~synth5 = nil;
~synth6 = nil;
~synth4_6 = nil;
~synth4_2 = nil;
~synth4_3 = nil;
~synth4_4 = nil;
~synth4_5 = nil;


~syn4_r1 = Pseq([Prand([2,2.2, 2, 1.8 , 2.4, 1.8], 24), Pxrand([1, 0.7, 2, 2, 0.3, 1, 2, 0.3], 8)], 1).asStream;
~syn4_r2 = Pgeom(1, 0.85, inf).asStream;
~syn4_r3 = Pseq([2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.0,2.05,2.1,2.05,2.1,2.1,2.15,2.2,2.3,2.4,3.0,3.5,4.0,6.0,3.0,3.0, 2.5, 2.0, 1.0, 40], 1).asStream;

~syn4_s1 = Routine({
	32.do{
	~synth4 = Synth(\syn4, [\attack, ~syn4_r2.next, \decay, ~syn4_r3.next, \gate, 1]);
	~syn4_r1.next.wait;
	};
	~syn4_s1= nil;
});

~syn2_s1 = Routine({
	1.do{
	~synth2.release(5);
	3.wait;
		~synth2=nil;
	};
});


~syn6_s1 = Routine({
	1.do{
	~synth6.release(10);
		2.wait;
		~synth6 = nil;
	}
});

~syn1_s1 = Routine({
	1.do{
	~synth1.release(6);
		3.wait;
		~synth1 = nil;
	}
});

~syn4_r4 = Penv([70, 75, 70], [14, 10], curve: 'exp').asStream;

~syn4_s2 = Routine({
	820.do{
		~synth4.set(\fbsinBase, ~syn4_r4.next);
	0.04.wait;
	}
});

~syn3_r1 = Pgeom(0.5, 0.95, 45).asStream;


~syn3_s1 = Routine({
	var temp;
45.do{
		temp = ~syn3_r1.next;
		Synth(\syn3, [\gate, 1, \decay, temp]);
		temp.wait;
	}
});



~syn2_r1 = Pseries(-0.1, -0.05, 18).asStream;


~syn2_s2 =  Routine({
18.do{
		~synth2.set(\grainsDurSubstract, ~syn2_r1.next);
	0.2444.wait;
	}
});

~syn4_r5 = Pgeom(0.05, 1.15, 15).asStream;
~syn4_r6 = Pgeom(0.1, 1.1, 15).asStream;

~syn4_s3 = Routine({
	var amp;
	amp = ~syn4_r6.next;
	15.do{
		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 0.3, \fbsinBase, 350, \amp, amp]);
		~synth4_2 =  Synth(\syn4_2, [\gate, 1, \decay, 0.3, \fbsinBase, 310, \amp,  amp-0.01]);
		~synth4_3 =  Synth(\syn4_3, [\gate, 1, \decay, 0.3, \fbsinBase, 270, \amp, amp-0.01]);
		~synth4_4 =  Synth(\syn4_4, [\gate, 1, \decay, 0.3, \fbsinBase, 230, \amp, amp-0.01]);
		~synth4_5 =  Synth(\syn4_5, [\gate, 1, \decay, 0.3, \fbsinBase, 190, \amp, amp-0.03]);
		~synth4_6 =  Synth(\syn4_6, [\gate, 1, \decay, 0.3, \fbsinBase, 150, \amp, amp-0.03]);
		~syn4_r5.next.wait;
	}
});


~syn6_r1 = Prand([5, 6,7,8, 25, 50,100,150,200, 250, 300, 1000], 100).asStream;
~syn6_r2 = Pseries(18, 0.025, 100).asStream;

~syn6_s2 = Routine({

	~synth6.set(\gate, 1, \sustain, 1, \frictionAdd, 0.003, \massAdd, 4, \impulseUpper, ~syn6_r1.next, \fitzrateDiv, 20, ~syn6_r2.next);
	0.1.wait;
});

~syn3_r2 = Pseq([Pgeom(0.015, 0.99, 50), Prand([0.001, 0.002, 0.003, 0.004, 0.005, 0.02, 0.016], 100)], 1).asStream;
~syn3_r3 = Pseq([Pgeom(25, 0.99, 50), Prand([0, -0.5, -0.25, 1, 2, 3, 4, 5, 8, 9, 10, 15, 18, 20, 25], 100)], 1).asStream;

~syn3_r4 = Pseq([Prand([0.25, 0.25, 0.25, 0.2, 0.44], 50), Prand([0.1, 0.2, 0.1, 0.2, 0.6, 0.7], 100)], 1).asStream;

~syn3_s2 =  Routine({
150.do{
		~synth3.set(\frictionAdd, ~syn3_r2.next, \massAdd, -1);
	    ~synth3_2.set(\frictionAdd, 0.001, \massAdd, ~syn3_r3.next);
	~syn3_r4.next.wait;
	}
});


~syn4_r7 = Pgeom(350, 1.05, 40).asStream;
~syn4_r8 = Pgeom(310, 1.042, 40).asStream;
~syn4_r9 = Pgeom(270, 1.026, 40).asStream;
~syn4_r10 = Pbrown(160, 300, 5, inf).asStream;
~syn4_r11 = Pbrown(120, 260, 10, inf).asStream;
~syn4_r12 = Pbrown(80, 210, 20, inf).asStream;
~syn4_r13 = Pgeom(0.1, 1.09, 40).asStream;


~syn4_s4 = Routine({
40.do{
			~synth4.set(\fbsinBase, ~syn4_r7.next);
		~synth4_2.set(\fbsinBase, ~syn4_r8.next);
		~synth4_3.set(\fbsinBase, ~syn4_r9.next);
		~synth4_4.set(\fbsinBase, ~syn4_r10.next);
		~synth4_5.set(\fbsinBase, ~syn4_r11.next);
		~synth4_6.set(\fbsinBase, ~syn4_r12.next);
		~syn4_r13.next.wait;
}
});


~syn3_r5 = Pbrown(0.001, 0.014, 0.0005, inf).asStream;
~syn3_r6 = Pbrown(0.005, 0.03, 0.005, inf).asStream;
~syn3_r7 =Pbrown(0.001, 0.015, 0.001, inf).asStream;

~syn3_r5 = Pbrown(0.001, 0.014, 0.0005, inf).asStream;
~syn3_r6 = Pbrown(0.005, 0.03, 0.005, inf).asStream;
~syn3_r7 =Pbrown(0.001, 0.015, 0.001, inf).asStream;

~syn3_r8 = PlinCong(a: 1.9, c: 0.2 ,m:3, x:3).asStream;
~syn3_r9 = PlinCong(a: 1.8, c: 1 ,m:4, x:4).asStream;
~syn3_r10 = PlinCong(a: 1.8, c: 5 ,m: 29, x:29).asStream;


~syn3_r11 = Pbrown(0.05, 2, 0.8, inf).asStream;


~syn3_s3 =  Routine({
100.do{
			~synth3_2.set(\frictionAdd, ~syn3_r5.next, \massAdd, ~syn3_r8.next);
				~synth3_3.set(\frictionAdd, ~syn3_r6.next, \massAdd,  ~syn3_r9.next);
		        ~synth3.set(\frictionAdd, ~syn3_r7.next, \massAdd,  ~syn3_r10.next);
		~syn3_r11.next.wait;
	}
});



~mainScore = Routine({
	1.do{

		//start 0
		~syn4_s1.play;

		(19 - ~delayedTime).wait;

		~synth1 = Synth(\syn1, [\gate, 1, \sustain, 1]);

		(41-19).wait; //41

		~synth2 = Synth(\syn2, [\gate, 1, \sustain, 1]);

		13.wait; //54
		~synth5 = Synth(\syn5, [\gate, 1, \sustain, 1]);

		~synth4_2 =  Synth(\syn4_2, [\gate, 1, \decay, 18, \fbsinBase, 230, \amp, 0.15]);
		~synth2.set(\squizChunkUpper, 10, \grainsTimeAdd, 5);
		6.wait;
		~synth4_2 = nil;
		~synth4 =  Synth(\syn4, [\gate, 1, \attack, 0, \decay, 2, \fbsinBase, 230, \amp, 0.3]);
		~synth6 = Synth(\syn6, [\gate, 1, \decay, 1.2, \frictionAdd, 0.003, \massAdd, 6, \impulseUpper, 60]);
		~synth6 = nil;
		2.wait;
		~synth4 = nil;
		~synth6 = Synth(\syn6, [\gate, 1, \sustain, 1, \frictionAdd, 0.003, \massAdd, 7, \impulseUpper, 20]);

		17.3.wait;
		~synth1.set(\syn1, [\gate, 1, \sigCadd, 0.5, \nagumoTrigAdd, 10]);


		(41-25.3).wait; //95
		~syn2_s1.play;

		8.wait;  //103
		~syn6_s1.play;
		~syn3_s1.play;

		3.wait;
		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 3, \fbsinBase, 270, \amp, 0.4]);
		~synth4_2 =  Synth(\syn4_2, [\gate, 1, \decay, 3, \fbsinBase, 190, \amp, 0.4]);
		~synth4_3 = Synth(\syn4_3, [\fbsinBase, 110, \decay, 3, \gate, 1, \amp, 0.4]);

		1.wait;
		~synth4 = nil;
		~synth4_2 = nil;
		~synth4_3 = nil;
		~synth3 = Synth(\syn3, [\gate, 1, \sustain, 1]);
		~synth3.set(\frictionAdd, 0.002, \massAdd, 2.5);

		5.wait;


		(23.69-9).wait;  //126.69

		~syn1_s1.play;
		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 35, \amp, 0.1]);
		~syn4_s2.play;
		~synth2 = Synth(\syn2, [\gate, 1, \sustain, 1, \grainsTimeAdd, -3]);
		~synth5.set(\grainsTimeAdd, 5);

		9.25.wait;
		~synth4 = nil;
		~syn2_s2.play;
		0.618.wait;

		~synth3_2 = Synth(\syn3_2, [\gate, 1, \sustain, 1]);
		~synth3_2.set(\gate, 1, \sustain, 1, \frictionAdd, 0.015, \massAdd, 4);
		0.382.wait;

		(14.65-10.25).wait;   //negative golden 141.34

		~synth6 = Synth(\syn6, [\gate, 1, \sustain, 1, \frictionAdd, 0, \massAdd, 6, \impulseUpper, 50]);
		6.18.wait;
		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 40, \fbsinBase, 210, \amp, 0.08]);
		3.82.wait;
		~synth4_2 =  Synth(\syn4, [\gate, 1, \decay, 40, \fbsinBase, 180, \amp, 0.08]);

		6.18.wait;
		~synth3.set(\frictionAdd, 0.005, \massAdd, 3);
		~synth4 = nil;
		~synth4_2 = nil;

		3.82.wait;
		~synth3.set(\frictionAdd, 0.001, \massAdd, 15);
		~synth3_2.set(\gate, 1, \frictionAdd, 0.02, \massAdd, 4);
		~synth3.release(12);
		~synth3 = nil;
		~synth3_2.release(16);
		~synth3_2 = nil;
		~synth6.release(3);
		~synth6 = nil;

		~syn2_s1.reset;
		~syn2_s1.play;
		~synth5.set(\grainsTimeAdd, 20);


		(36.29 - 20).wait; //177.63
		~synth5.release(6);
		~synth5 = nil;
		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 15, \fbsinBase, 350, \amp, 0.3]);
		~synth1 = Synth(\syn1, [\gate, 1, \sustain, 1]);
		~synth5 = Synth(\syn5, [\gate, 1, \sustain, 1, \grainsTimeAdd, -0.5, \elapedTime, 177.63]);
	~synth6 = Synth(\syn6, [\gate, 1, \sustain, 1, \frictionAdd, 0.003, \massAdd, 5, \impulseUpper, 50, \fitzrateDiv, 20]);
		~syn6_s2.play;

		~synth3 = Synth(\syn3, [\gate, 1, \sustain, 1]);
~synth3.set(\frictionAdd, 0.003, \massAdd, 29);

		8.wait;
		~synth1.set(\nagumoTrigAdd, 10);
		~synth4 = nil;
		~synth3_2 = Synth(\syn3_2, [\gate, 1, \sustain, 1]);
		(17.7-8).wait; //195.33

		~synth3_3 = Synth(\syn3_3, [\gate, 1, \sustain, 1]);
		~syn3_s2.play;
		~synth3.set(\frictionAdd, 0.003, \massAdd, 28);

		~synth4_2 =  Synth(\syn4_2, [\gate, 1, \decay, 20, \fbsinBase, 310, \amp, 0.3]);
		~synth2 = Synth(\syn2, [\gate, 1, \sustain, 1, \grainsTimeAdd, -7,\squizChunkUpper, 40]);
		~synth6.set(\frictionAdd, 0.004, \massAdd, 5.5, \impulseUpper, 17);

		12.75.wait; //208.08
		~synth4_2 = nil;
		~synth4_3 =  Synth(\syn4_3, [\gate, 1, \decay, 15, \fbsinBase, 270, \amp, 0.2]);

		7.88.wait; //215.96
		~synth4_3 = nil;
		~synth4_4 =  Synth(\syn4_4, [\gate, 1, \decay, 10, \fbsinBase, 230, \amp, 0.2]);

		4.87.wait; //220.83
		~synth4_4 = nil;
		~synth4_5 =  Synth(\syn4_5, [\gate, 1, \decay, 5, \fbsinBase, 190, \amp, 0.18]);


		3.01.wait; //223.84
		~synth1.set(\nagumoTrigAdd, 20);
		~synth4_5 = nil;
		~synth4_6 =  Synth(\syn4_6, [\gate, 1, \decay, 2, \fbsinBase, 150, \amp, 0.12]);

		1.86.wait; //225.70
		~syn4_s3.play;
		~synth3.set(\frictionAdd, 0.003, \massAdd, 30);


		3.wait; //228.70  golden section
		~syn3_s3.play;
		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 50, \fbsinBase, 350, \amp, 0.6]);
		~synth4_2 =  Synth(\syn4_2, [\gate, 1, \decay, 50, \fbsinBase, 310, \amp, 0.55]);
		~synth4_3 =  Synth(\syn4_3, [\gate, 1, \decay, 50, \fbsinBase, 270, \amp, 0.5]);
		~synth4_4 =  Synth(\syn4_4, [\gate, 1, \decay, 50, \fbsinBase, 230, \amp, 0.5]);
		~synth4_5 =  Synth(\syn4_5, [\gate, 1, \decay, 50, \fbsinBase, 190, \amp, 0.5]);
		~synth4_6 =  Synth(\syn4_6, [\gate, 1, \decay, 50, \fbsinBase, 150, \amp, 0.5]);
		5.5.wait;
		~syn4_s4.play;

		24.62.wait;

		~synth4 =  Synth(\syn4, [\gate, 1, \decay, 90, \fbsinBase, 310, \amp, 0.3]);
		~synth4_2 =  Synth(\syn4_2, [\gate, 1, \decay, 90, \fbsinBase, 270, \amp, 0.3]);
		~synth4_3 =  Synth(\syn4_3, [\gate, 1, \decay, 90, \fbsinBase, 230, \amp, 0.25]);
		~synth4_4 =  Synth(\syn4_4, [\gate, 1, \decay, 90, \fbsinBase, 190, \amp, 0.25]);
		~synth4_5 =  Synth(\syn4_5, [\gate, 1, \decay, 90, \fbsinBase, 150, \amp, 0.25]);
		~synth4_6 =  Synth(\syn4_6, [\gate, 1, \decay, 90, \fbsinBase, 110, \amp, 0.3]);

		3.5.wait;
		~syn4_s4.reset;
		~syn4_s4.play(TempoClock(0.6));

~synth5.set(\grainsTimeAdd, 5);
~synth2.set(\squizChunkUpper, 50, \grainsTimeAdd, 10);

		(46.3-33.62).wait; //275
~syn3_s3.stop;
				~synth3_2.set(\frictionAdd, 0.015, \massAdd, 3);
				~synth3_3.set(\frictionAdd, 0.000, \massAdd,  15);
		        ~synth3.set(\frictionAdd, 0.015, \massAdd,  5);

		~synth6.release;
		~synth6 = Synth(\syn6, [\gate, 1, \sustain, 1, \frictionAdd, 0.006, \massAdd, 3.2, \impulseUpper, 70, \fitzrateDiv, 20]);

~synth5.set(\grainsTimeAdd, 15);
~synth2.set(\squizChunkUpper, 10, \grainsTimeAdd, 20);

		36.29.wait; //311.29

		17.71.wait; //329
		 ~synth3.set(\frictionAdd, 0.02, \massAdd,  5);
		41.wait; // 370 end
	}

});

~syn3Geom =  Pgeom(0.5, 0.99, 350).asStream;
~syn3Decay = Pgeom(0.5, 0.99, 350).asStream;
~synth3Routine = Routine({
	350.do{
		~synth3 = Synth(\syn3, [\decay, ~syn3Decay.next, \gate,1]);
		~syn3Geom.next.wait;

	};
});




OSCdef(\icoPos1).free;
OSCdef(\icoPos2).free;
OSCdef(\icoPos3).free;
OSCdef(\icoPos4).free;
OSCdef(\icoPos5).free;
OSCdef(\elapsedTime).free;
OSCdef(\exit).free;



OSCdef.newMatching(\icoPos1,
	{|msg, time, addr, recvPort|
		var msg1, msg2, msg3;
		if((msg[1]>0) && (msg[1]<2400), {msg1 = msg[1]}, { msg1 = 1});
		if((msg[2]>0) && (msg[2]<1350), {msg2 = msg[2]}, { msg2 = 1});
		if((msg[3]>0) && (msg[3]<1000), {msg3 = msg[3]}, { msg3 = 1});

~synth2 !? {
			~synth2.set(\posX, msg1, \posY, msg2, \posZ, msg3)};
}, '/icoPos1').add;

OSCdef.newMatching(\icoPos2,
	{|msg, time, addr, recvPort|
		var msg1, msg2, msg3;
		if((msg[1]>0) && (msg[1]<2450), {msg1 = msg[1]}, { msg1 = 1});
		if((msg[2]>0) && (msg[2]<1350), {msg2 = msg[2]}, { msg2 = 1});
		if((msg[3]>0) && (msg[3]<1000), {msg3 = msg[3]}, { msg3 = 1});
~synth3 !? {
			~synth3.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth3_2 !? {
			~synth3_2.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth3_3 !? {
			~synth3_3.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
}, '/icoPos2').add;

OSCdef.newMatching(\icoPos3,
	{|msg, time, addr, recvPort|
		var msg1, msg2, msg3;
		if((msg[1]>0) && (msg[1]<2450), {msg1 = msg[1]}, { msg1 = 1});
		if((msg[2]>0) && (msg[2]<1350), {msg2 = msg[2]}, { msg2 = 1});
		if((msg[3]>0) && (msg[3]<1000), {msg3 = msg[3]}, { msg3 = 1});

	~synth4 !?{
			~synth4.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth4_2 !?{
			~synth4_2.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth4_3 !?{
			~synth4_3.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth4_4 !?{
			~synth4_4.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth4_5 !?{
			~synth4_5.set(\posX, msg1, \posY, msg2, \posZ, msg3);};
		~synth4_6 !?{
			~synth4_6.set(\posX, msg1, \posY, msg2, \posZ, msg3);};


}, '/icoPos3').add;


OSCdef.newMatching(\icoPos4,
	{|msg, time, addr, recvPort|
		var msg1, msg2, msg3;
		if((msg[1]>0) && (msg[1]<2450), {msg1 = msg[1]}, { msg1 = 1});
		if((msg[2]>0) && (msg[2]<1350), {msg2 = msg[2]}, { msg2 = 1});
		if((msg[3]>0) && (msg[3]<1000), {msg3 = msg[3]}, { msg3 = 1});

	~synth5 !?{
			~synth5.set(\posX, msg1, \posY, msg2, \posZ, msg3);};



}, '/icoPos4').add;

OSCdef.newMatching(\icoPos5,
	{|msg, time, addr, recvPort|
		var msg1, msg2, msg3;
		if((msg[1]>0) && (msg[1]<2450), {msg1 = msg[1]}, { msg1 = 1});
		if((msg[2]>0) && (msg[2]<1350), {msg2 = msg[2]}, { msg2 = 1});
		if((msg[3]>0) && (msg[3]<1000), {msg3 = msg[3]}, { msg3 = 1});

	~synth6 !?{
			~synth6.set(\posX, msg1, \posY, msg2, \posZ, msg3);};



}, '/icoPos5').add;



OSCdef.newMatching(\elapsedTime,
	{|msg, time, addr, recvPort|
		var msg1, msg2, msg3;
		if((msg[1]>0) && (msg[1]<370), {msg1 = msg[1] }, { msg1 = 1});


		if((msg[1] > 0) && (msg[1] < 5) && (start == 0) , {
			~mainScore.play;
			~delayedTime = msg[1]; start = 1;

			s.record;
		});

~synth1 !? {
			~synth1.set(\elapsedTime, msg1)};

	~synth2 !? {
			~synth2.set(\elapsedTime, msg1)};

		~synth3 !? {
			~synth3.set(\elapsedTime, msg1)};

		~synth4 !? {
			~synth4.set(\elapsedTime, msg1)};
		~synth5 !? {
			~synth4.set(\elapsedTime, msg1)};
		~synth6 !? {
			~synth4.set(\elapsedTime, msg1)};

}, '/elapsedTime').add;


OSCdef.newMatching(\exit,
	{|msg, time, addr, recvPort|

		if(msg[1] == 44, {  s.stopRecording; });

if(msg[1] == 44, { CmdPeriod.run; });

}, '/exit').add;


)

s.prepareForRecord;
~delayedTime;
s.stopRecording






//simple random spatializer

(
SynthDef(\syn1, {
var sig;

	sig = PlayBuf.ar(1, b, BufRateScale.kr(b));

	sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
		TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.375, 0.1875, 0.125, 0.0625, 0.125, 0.125]), // pos
        1,            // level
        1,            // width
		0
		);

	Out.ar(0, sig);
}).add;

SynthDef(\syn2, {
var sig;

	sig = PlayBuf.ar(1, c, BufRateScale.kr(c));

		sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
		TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.125, 0.375, 0.125, 0.0625, 0.1875, 0.125]), // pos
        1,            // level
        1,
		0          // width
	);

	Out.ar(0, sig);
}).add;

SynthDef(\syn3, {
var sig;

	sig = PlayBuf.ar(1, d, BufRateScale.kr(d));

			sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
		TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.1875, 0.125, 0.375, 0.0625, 0.125, 0.125]), // pos
        1,            // level
        1,            // width
		0
	);
	Out.ar(0, sig);
}).add;

SynthDef(\syn4, {
var sig;

	sig = PlayBuf.ar(1, e, BufRateScale.kr(e));

			sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
		TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.1875, 0.25, 0.25, 0.0625, 0.125, 0.125]), // pos
        1,            // level
        1,            // width
		0
	);
	Out.ar(0, sig);
}).add;

SynthDef(\syn5, {
var sig;

	sig = PlayBuf.ar(1, f, BufRateScale.kr(f));

			sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
				TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.125, 0.125, 0.125, 0.125, 0.25, 0.25]), // pos
        1,           // level
        1,            // width
		0
	);
	Out.ar(0, sig);
}).add;

SynthDef(\syn6, {
var sig;

	sig = PlayBuf.ar(1, g, BufRateScale.kr(g));

			sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
			TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.1875, 0.25, 0.25, 0.0625, 0.125, 0.125]), // pos
        1,            // level
        1,            // width
		0
	);
	Out.ar(0, sig);
}).add;

SynthDef(\syn7, {
var sig;

	sig = PlayBuf.ar(1, h, BufRateScale.kr(h));

			sig =    PanAz.ar(
        6,                 // numChans
        sig,     // in
			TWChoose.kr( Trig.kr(DetectSilence.ar(sig, time: MouseY.kr(0.5, 0.05))), [0, 0.333, 0.666, 1, 1.333, 1.666], [0.1875, 0.125, 0.125, 0.0625, 0.25, 0.25]), // pos
        1,            // level
        1,            // width
		0
	);
	Out.ar(0, sig);
}).add;

)