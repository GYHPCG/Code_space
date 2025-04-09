function myTree = ID3(dataset,labels)
% ID3�㷨����������
% ���������
% dataset�����ݼ�
% labels�����Ա�ǩ
% ���������
% tree�������ľ�����


size_data = size(dataset);
classList = dataset(:,size_data(2));   %�õ���ǩ

%ȫΪͬһ�࣬��Ϊ0
if length(unique(classList))==1
    myTree =  char(classList(1));
    return 
end

%%���Լ�Ϊ�գ�Ӧ���������������һ�࣬����ȡֵ��һ�����
if size_data(2) == 1
    myTree =  char(classList(1));
    return
end

bestFeature = chooseFeature(dataset);           %�ҵ���Ϣ������������
bestFeatureLabel = char(labels(bestFeature));     %�õ���Ϣ�����������������֣���Ϊ������Ҫɾ��������
myTree = containers.Map;
leaf = containers.Map;
featValues = dataset(:,bestFeature);
uniqueVals = unique(featValues);

labels=[labels(1:bestFeature-1) labels(bestFeature+1:length(labels))]; %ɾ��������

%�γɵݹ飬һ�������İ�ÿ����������·�
for i=1:length(uniqueVals)
    subLabels = labels(:)';                            
    value = char(uniqueVals(i));
    subdata = splitDataset(dataset,bestFeature,value);    %ȡ��������ֵΪvalue����������,��ȥ��������
    leaf(value) = ID3(subdata,subLabels);
    myTree(char(bestFeatureLabel)) = leaf;
end
end