clear
clc;    
L=1000;
fp=48000;
f=1000;

t=(0:L-1)/fp;
y=square(2*pi*f*t,0.80);

NFFT = 2^nextpow2(L);
Y = fft(y,NFFT)/L;
f = fp/2*linspace(0,1,NFFT/2+1);

subplot(2,1,1);
plot(y);
subplot(2,1,2);
plot(f,2*abs(Y(1:NFFT/2+1)));
print -deps proba1_4.eps
print -djpg proba1_4.jpg
print -dpng proba1_4.png
