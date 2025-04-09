function myTree = ID3(dataset,labels)
% ID3算法构建决策树
% 输入参数：
% dataset：数据集
% labels：属性标签
% 输出参数：
% tree：构建的决策树


size_data = size(dataset);
classList = dataset(:,size_data(2));   %得到标签

%全为同一类，熵为0
if length(unique(classList))==1
    myTree =  char(classList(1));
    return 
end

%%属性集为空，应该用找最多数的那一类，这里取值第一个类标
if size_data(2) == 1
    myTree =  char(classList(1));
    return
end

bestFeature = chooseFeature(dataset);           %找到信息增益最大的特征
bestFeatureLabel = char(labels(bestFeature));     %得到信息增益最大的特征的名字，即为接下来要删除的特征
myTree = containers.Map;
leaf = containers.Map;
featValues = dataset(:,bestFeature);
uniqueVals = unique(featValues);

labels=[labels(1:bestFeature-1) labels(bestFeature+1:length(labels))]; %删除该特征

%形成递归，一个特征的按每个类别再往下分
for i=1:length(uniqueVals)
    subLabels = labels(:)';                            
    value = char(uniqueVals(i));
    subdata = splitDataset(dataset,bestFeature,value);    %取出该特征值为value的所有样本,并去除该属性
    leaf(value) = ID3(subdata,subLabels);
    myTree(char(bestFeatureLabel)) = leaf;
end
end