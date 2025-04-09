% % 矩阵的算术运算
% A = [1 2 3; 4 5 6];
% B = [3 2 1; 6 5 4];
% C = [2 3; 1 2; 4 5];
% ma = A + B % 矩阵相加
% ms = A - B % 矩阵相减
% mm = A * C % 矩阵相乘 (2,3) x (3,2) = (2,2)，A的列要和B的行相同
% mdm = A .* B % 数组乘
% md = A / B % 矩阵相乘
% masquare = A.^2 % 数组幂
% mbsquare = B.^2


% 
% % 绘制两条曲线的交点
% % y=2x-0.5 和参数曲线
% 
% 
% % 定义函数
% 定义第一条直线
x1 = linspace(-2, 2, 100);  % 取一个范围
y1 = 2*x1 - 0.5;
figure;
plot(x1, y1, 'b');  % 绘制为蓝色

hold on;  % 将要绘制的图形保持在同一个图中

% 定义参数 t
t = linspace(0, pi, 100000);  % 从 0 到 pi 均匀取点

% 计算第二条曲线的 x 和 y
x2 = sin(3*t) .* cos(t);
y2 = sin(3*t) .* sin(t);

% 绘制第二条曲线
plot(x2, y2, 'r');  % 绘制为红色

% 求解交点
tol = 1e-4;  % 容差值
intersections = [];
for i = 1:length(t)
    % 计算当前 t 对应的曲线点
    x_curr = x2(i);
    y_curr = y2(i);

    % 检查当前曲线点是否满足直线方程
    dist = abs(y_curr - (2*x_curr - 0.5));
    if dist < tol
        intersections = [intersections; x_curr, y_curr];
    end
end

intersections

% disp(intersections);  % 输出交点数组内容

% 绘制交点
plot(intersections(:, 1), intersections(:, 2), 'b*');  % 绘制交点为黑色圆点
% 添加图例和标签
axis equal;
legend('Line y = 2x - 0.5', 'Curve x = sin(3*t)*cos(t) y = sin(3*t)*sin(t)', 'data1', 'Location', 'best');
xlabel('x:2100770217');
ylabel('y:软工2101');
title('潘成功');


% % 计算公式中的每一项
% n = 100;  % 设置 n 的值
% terms = 1./(1:2*n-1);  % 计算所有项的值，即 1/(2*1-1), 1/(2*2-1), ..., 1/(2*n-1)
% 
% % 计算累加和
% y = sum(terms);
% 
% % i. 输出 n=100 时，对应的 y 值，保留 3 位有效数字
% disp(['For n=100, y = ', num2str(y, '%.3f')]);  % 显示保留 3 位有效数字的 y 值
% 
% % ii. 找到 y < 3 时最大的 n 值，同时输出对应的 n 值及 y 值
% n_values = 1:100;  % 设置 n 的取值范围
% y_values = cumsum(1./(1:2*n_values-1));  % 计算对应的 y 值序列
% 
% % 找到满足 y < 3 的最大的 n 值
% max_n_less_than_3 = find(y_values < 3, 1, 'last');  % 找到最后一个满足条件的 n 值
% corresponding_y_value = y_values(max_n_less_than_3);  % 获取对应的 y 值
% disp(['For y < 3, the maximum n value is ', num2str(max_n_less_than_3), ' and the corresponding y value is ', num2str(corresponding_y_value)]);

% 绘制 y 值随 n 变化的曲线图
% figure;
% plot(n_values, y_values, 'b.-');  % 绘制 y 值随 n 变化的曲线
% xlabel('n');  % 设置 x 轴标签
% ylabel('y');  % 设置 y 轴标签
% title('Plot of y vs. n');  % 设置图标题
% grid on;  % 显示网格


% i. 输出 n=100 时，对应的 y 值，保留 3 位有效数字
n = 1:100;  % 设置 n 的值
terms = 1./(2*n-1);  % 计算所有项的值，即 1/(2*1-1), 1/(2*2-1), ..., 1/(2*n-1)
y = sum(terms);  % 计算累加和

% 显示保留 3 位有效数字的 y 值
disp(['当 n=100时, y = ', num2str(y, '%.3f')]);

% ii. 找到 y < 3 时最大的 n 值，同时输出对应的 n 值及 y 值
n_values = 1:100;  % 设置 n 的取值范围
y_values = cumsum(1./(2*n_values-1));  % 计算对应的 y 值序列

% 找到满足 y < 3 的最大的 n 值
max_n_less_than_3 = find(y_values < 3, 1, 'last');  % 找到最后一个满足条件的 n 值
corresponding_y_value = y_values(max_n_less_than_3);  % 获取对应的 y 值
disp(['y < 3的最大值, 即当 n 的值 = ', num2str(max_n_less_than_3), ' 时， y 的值= ', num2str(corresponding_y_value,'%.3f')]);


