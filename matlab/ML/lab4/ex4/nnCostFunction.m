
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

X = [ones(m,1) X];    
a_super2 = sigmoid(Theta1 * X');
a_super2 = [ones(1,m);a_super2]; 
a_super3 = sigmoid(Theta2 * a_super2);%10*5000

a3 = 1 - a_super3;%10*5000


%part1
Y=zeros(num_labels,m);   
for i=1:num_labels
  Y(i,y==i)=1;          
end  
Y1=1-Y;
res1=0;
res2=0;
for j=1:m
 tmp1 = sum( log(a_super3(:,j)) .* Y(:,j) );   
    res1 = res1 + tmp1;     
    tmp2 = sum( log(a3(:,j)) .* Y1(:,j) );       
    res2 = res2 + tmp2;
end
J = (-res1 - res2) / m;     


%part2?
  for i=1:m
  a1=X(i,:)';  
  z2=Theta1*a1;
  a2=sigmoid(z2);
  a2=[1;a2];  
  z3=Theta2*a2;
  a3=sigmoid(z3);

error_3=a3-Y(:,i); 
err_2=Theta2'*error_3;    
error_2 = ( err_2(2:end) ) .*  sigmoidGradient(z2);   

Theta2_grad = Theta2_grad + error_3 * a2';   
Theta1_grad = Theta1_grad + error_2 * a1';
end

Theta2_grad = Theta2_grad / m;  
Theta1_grad = Theta1_grad / m;

%part3
Theta1_tmp = Theta1(:, 2:end).^2;
Theta2_tmp = Theta2(:, 2:end).^2;
reg = lambda / (2*m) * ( sum( Theta1_tmp(:) ) + sum( Theta2_tmp(:) ) );

J = (-res1 - res2) / m + reg;


% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
