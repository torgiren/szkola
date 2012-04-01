clear
clc
[y,a]=wavread("agnieszka.wav");
L=4001;
%L=1000;
fp=48000;
%f=(1000:1:5000);
f=1000;

t=(0:L-1)/fp;
%y=square(2*pi*f*t,0.80);
for q=21:4001,
	ya(q)=y(q-20);
end





NFFT = 2^nextpow2(L);
Y = fft(y,NFFT)/L;
Ya= fft(ya,NFFT)/L;
f = fp/2*linspace(0,1,NFFT/2+1);
fa= fp/2*linspace(0,1,NFFT/2+1);



subplot(3,3,1);
plot(y);
subplot(3,3,2);
plot(f,2*abs(Y(1:NFFT/2+1)));
subplot(3,3,3);
specgram(y);

subplot(3,3,4);
plot(ya);
subplot(3,3,5);
plot(fa,2*abs(Ya(1:NFFT/2+1)));
subplot(3,3,6);
specgram(ya);

yb=y.+0.5*ya;
subplot(3,3,7);
plot(yb);


print -deps proba2_1.eps
print -djpg proba2_1.jpg
print -dpng proba2_1.png
