function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1); % 样本数
num_labels = size(Theta2, 1); %标签数

% You need to return the following variables correctly 
% 预测结果
p = zeros(size(X, 1), 1);


% ====================== YOUR CODE HERE ======================

l1 = sigmoid([ones(m, 1) X] * Theta1');
l2 = sigmoid([ones(m, 1) l1] * Theta2');
[pval, p] = max(l2, [], 2);

% =========================================================================


end
