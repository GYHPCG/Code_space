
% �������ݼ�
clear
clc
load('watermelon.mat')
size_data = size(watermelon); %watermelon2Ϊ���빤��̨������

%��Ϊѵ�����Ͳ��Լ���
x_train = watermelon(1:size_data(1)-2,:) ;     %������������Ա�ǩ��
x_test = watermelon(size_data(1)-1:end,1:size_data(2)-1);  %ѡ��������������Լ�


%ѵ��
size_data = size(x_train);
dataset = x_train(2:size_data(1),:); %�����ݼ�
labels = x_train(1,1:size_data(2)-1); %���Ա�ǩ

%���ɾ�����
mytree = ID3(dataset,labels);
[nodeids,nodevalue,branchvalue] = print_tree(mytree);
tree_plot(nodeids,nodevalue,branchvalue);


