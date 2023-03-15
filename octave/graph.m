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


% x = 0:0.01:20;
% y1 = 200*exp(-0.05*x).*sin(x);
% y2 = 0.8*exp(-0.5*x).*sin(10*x);
% figure
% [AX,H1,h2] = plotyy(x,y1,x,y2,"plot");

%三维绘图
t = 0:pi/50:10*pi;
plot3(sin(t),cos(t),t)
xlabel("sin(t)")
ylabel("cos(t)")
zlabel("t")
grid on %在幕布上添加网格

%双峰图
[x, y, z] = peaks(30);
mesh(x,y,z);
grid

%画子图
x = linspace(0,2*pi,60);
subplot(2,2,1);
plot(x,sin(x));

subplot(2,1,2);
plot(x,cos(x));
