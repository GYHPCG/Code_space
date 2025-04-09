function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)

Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1)); 
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% 前向传播计算
X = [ones(m,1) X];    
a_s2 = sigmoid(Theta1 * X'); % 计算隐藏层的激活值
a_s2 = [ones(1,m);a_s2];  % 增加偏置单元
a_s3 = sigmoid(Theta2 * a_s2); % 计算输出层的激活值，即预测值

a_s3 = 1 - a_s3;

%计算无正则化的损失,成本函数
Y=zeros(num_labels,m);   
for i=1:num_labels
  Y(i,y==i)=1;  % 将标签 `y` 转换为独热编码形式        
end  
Y1=1-Y;
res1=0;
res2=0;
for j=1:m
 tmp1 = sum(log(a_s3(:,j)) .* Y(:,j) );    % 计算预测为正类的部分的损失
    res1 = res1 + tmp1;     
    tmp2 = sum( log(a_s3(:,j)) .* Y1(:,j) );      % 计算预测为负类的部分的损失 
    res2 = res2 + tmp2;
end
J = (-res1 - res2) / m;  % 计算总体成本，不考虑正则化   


%反向传播计算梯度
 for i=1:m
       % 第一步，前向传播计算各层的激活值
  a1=X(i,:)';  
  z2=Theta1*a1;
  a2=sigmoid(z2);
  a2=[1;a2];   % 增加隐藏层的偏置单元
  z3=Theta2*a2;
  a3=sigmoid(z3);

 
% 第二步，计算输出层的误差
error_3=a3-Y(:,i); 
% 第三步，计算隐藏层的误差
err_2=Theta2'*error_3;    
error_2 = ( err_2(2:end) ) .*  sigmoidGradient(z2);   
    % 第四步，累积计算梯度
Theta2_grad = Theta2_grad + error_3 * a2';   
Theta1_grad = Theta1_grad + error_2 * a1';
end

% 第 5 步将累积梯度除以 m，得到神经网络成本函数的梯度
% 计算平均梯度
Theta2_grad = Theta2_grad / m;  
Theta1_grad = Theta1_grad / m;
% 
% 计算正则化项
Theta1_tmp = Theta1(:, 2:end).^2;
Theta2_tmp = Theta2(:, 2:end).^2;
reg = lambda / (2*m) * ( sum( Theta1_tmp(:) ) + sum( Theta2_tmp(:) ) );
% 重新计算总体成本 J（包括正则化）
J = (-res1 - res2) / m + reg;




% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
