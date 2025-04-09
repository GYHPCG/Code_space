
% 西瓜数据集
clear
clc
load('watermelon.mat')
size_data = size(watermelon); %watermelon2为导入工作台的数据

%分为训练集和测试集，
x_train = watermelon(1:size_data(1)-2,:) ;     %这里加上了属性标签行
x_test = watermelon(size_data(1)-1:end,1:size_data(2)-1);  %选择最后两个当测试集


%训练
size_data = size(x_train);
dataset = x_train(2:size_data(1),:); %纯数据集
labels = x_train(1,1:size_data(2)-1); %属性标签

%生成决策树
mytree = ID3(dataset,labels);
[nodeids,nodevalue,branchvalue] = print_tree(mytree);
tree_plot(nodeids,nodevalue,branchvalue);


