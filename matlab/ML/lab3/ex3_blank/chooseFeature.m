function bestFeature=chooseFeature(dataset,~)
% 选择信息增益最大的属性特征


%baseEntropy = calShannonEnt(dataset);   %计算当前节点的信息熵
%data_size = size(dataset);
%numFeatures = data_size(2) - 1;      %得到特征个数
%minEntropy = 2.0;
%bestFeature = 0;
%gain = (1:numFeatures);           %创建一个数组，以后用来储存每个特征的信息增益    %%%%%%%%%

[N,M]=size(dataset);                %样本数量N
M=M-1;                              %特征个数M
y=strcmp(dataset(:,M+1),dataset(1,M+1)); %标签y(以第一个标签为1)
x=dataset(:,1:M);                   %数据x
gain = (1:M);                       %创建一个数组，用于储存每个特征的信息增益
%bestFeature;                       %最大信息增益的特征
Ent_D=calShannonEnt(y);             %当前信息熵

%%%%====== 下面语句请同学们完成，循环每一个特征计算信息增益，选取信息增益最大的特征 =======

% 初始化信息增益向量
gain = zeros(1, M);

% 循环遍历每个属性
for i = 1:M
    % 统计第 i 种属性的不同取值及其出现次数
    temp = tabulate(x(:, i));
    value = temp(:, 1);            % 属性值
    count = cell2mat(temp(:, 2));  % 不同属性值的各自数量
    Kind_Num = length(value);      % 取值数目
    
    % 初始化每种属性值下的信息熵向量
    Ent = zeros(Kind_Num, 1);
    
    % 计算每种属性值的信息熵
    for j = 1:Kind_Num
        % 在第 j 种取值下正例的数目
        Ent(j) = calShannonEnt(y(strcmp(x(:, i), value(j))));
    end
    
    % 计算第 i 种属性的信息增益
    gain(i) = Ent_D - sum(count) / N * sum(Ent);
end

% 随机挑选一个最大值
max_gain = find(gain == max(gain));
bestFeature = max_gain(randi(length(max_gain)));





%%%%===================================================================================
end
