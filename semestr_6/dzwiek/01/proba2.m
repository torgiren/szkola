clear
clc;    
L=1000;
fp=48000;
f1=1000;
f2=100;

t=(0:L-1)/fp;

y1=sin(2*pi*f1*t);
y2=sin(2*pi*f2*t);
y=y1+y2;

NFFT = 2^nextpow2(L); 
Y = fft(y,NFFT)/L;
f = fp/2*linspace(0,1,NFFT/2+1);

subplot(2,2,1);
plot(y);
subplot(2,2,2);
plot(f,2*abs(Y(1:NFFT/2+1)));
subplot(2,2,3);
plot(y1);
subplot(2,2,4);
plot(y2);
wavwrite(y,fp,'proba.wav');
print -deps proba2_dom.eps
