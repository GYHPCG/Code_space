%1. 二维平面图
%多行注释CTRL 人， 取消ctrl t
% x = 0:0.01:2*pi;
% y = sin(x);
% figure %建立一个幕布
% plot(x,y)
% title("y = sin(x)")
% xlabel("x")
% ylabel("sin(x)")
% xlim([0 2*pi]) 


x = 0:0.01:20;
y1 = 200*exp(-0.05*x).*sin(x);
y2 = 0.8*exp(-0.5*x).*sin(10*x);
figure
[AX,H1,h2] = plotyy(x,y1,x,y2,"plot");


