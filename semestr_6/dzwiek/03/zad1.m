clear
clc
%y=wavread("fletnia_44khz.wav");
%y=wavread("akordeon_44khz.wav");
%y=wavread("flet_szkolny_44khz.wav");
%y=wavread("trabka_44khz.wav");
y=wavread("kamerton_44khz.wav");
L=4001;
fp=48000;
f=(1000:1:5000);

t=(0:L-1)/fp;
NFFT = 2^nextpow2(L);
Y = fft(y,NFFT)/L;
f = fp/2*linspace(0,1,NFFT/2+1);

subplot(3,1,1);
plot(y);
subplot(3,1,2);
plot(f,2*abs(Y(1:NFFT/2+1)));
subplot(3,1,3);
specgram(y(:,1));
print -deps proba1_kamerton.eps
print -djpg proba1_kamerton.jpg
print -dpng proba1_kamerton.png
