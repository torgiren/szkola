clear
clc;    
L=4001;
fp=48000;
f=(1000:1:5000);

t=(0:L-1)/fp;

y=sin(2*pi*(f.*t));

NFFT = 2^nextpow2(L);
Y = fft(y,NFFT)/L;
f = fp/2*linspace(0,1,NFFT/2+1);

subplot(3,1,1);
plot(y);
subplot(3,1,2);
plot(f,2*abs(Y(1:NFFT/2+1)));
subplot(3,1,3);
specgram(y);
print -deps proba2_1.eps
print -djpg proba2_1.jpg
print -dpng proba2_1.png
