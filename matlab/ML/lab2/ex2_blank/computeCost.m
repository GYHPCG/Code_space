function J = computeCost(X, y, theta)

m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;

% ====================== YOUR CODE HERE ======================



% =========================================================================
J= 1/(2*m) * sum((X * theta-y).^2);
end
