clear
clc;    
L=500;
fp=48000;
f=1000;

t=(0:L-1)/fp;
y=sin(2*pi*f*t);
y=quantiz(y,linspace(-1,1,16));

NFFT = 2^nextpow2(L);
Y = fft(y,NFFT)/L;
f = fp/2*linspace(0,1,NFFT/2+1);

subplot(2,1,1);
plot(y);
subplot(2,1,2);
plot(f,2*abs(Y(1:NFFT/2+1)));
print -deps zad1_7.jpg
print -deps zad1_7.png
